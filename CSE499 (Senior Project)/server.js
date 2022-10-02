const PATH         = require('path');
const EXPRESS      = require('express');
const HTTP         = require('http');
const { Server }   = require('socket.io');
const { Gpio }     = require('onoff');
const LOG          = require('./log.js');
const APP           = EXPRESS();
const SERVER        = HTTP.createServer(APP);
const IO            = new Server(SERVER);
const SWITCH_SOUTH  = new Gpio(17, 'in', 'both');
const RELAY         = new Gpio(23, 'out');
const PORT          = process.env.PORT || 8080;
// const DOOR_TIMEOUT  = 300000; // 5 minutes
const DOOR_TIMEOUT  = 30000; // 30 seconds
let log             = new LOG();
let doorInterface   = 'button';
let autoCloseTimer  = null;
let timer           = null;
let doorStatusSouth = null;

/******************************************************************************
 * TRIGGER RELAY
 * Trigger the relay to open/close the door (shorts the door circuit for 0.5
 * seconds).
 *****************************************************************************/
const triggerRelay = () => {
    RELAY.writeSync(1); // close (latch) relay

    setTimeout(() => {
        RELAY.writeSync(0); // open (unlatch) relay
    }, 750); // 0.75 seconds
};

/******************************************************************************
 * EMIT CHANGE ON EVENT
 * @param {Object} websocket 
 * @param {Object} err 
 * @param {Int} val 0 or 1
 * @returns null on error
 *****************************************************************************/
const emitChangeOnEvent = (websocket, err, val) => {
    if (err) {
        console.error('Error: ', err);
        return;
    }

    //send button status to client
    websocket.emit('door-south', Number(!val));
};

// middleware: allow server to use anything that lives in /public (static assets)
APP.use(EXPRESS.static(PATH.join(__dirname + '/public')));
APP.set('views', './views'); // view engine (object, directory)
APP.set('view engine', 'ejs'); // render .ejs files as views
APP.get('/', (req, res) => {
    // res.sendFile(PATH.join(__dirname + '/public/index.htm'));
    res.render('pages/index', {
        title: 'Pi Garage | Home',
        button_route: '/log'
    });
});
APP.get('/log', (req, res) => {
    // read event log data
    log.getData();

    res.render('pages/log', {
        title: 'Pi Garage | Log',
        button_route: '/',
        events: log.events,
        users: log.users
    });
});

// WebSocket connection
IO.on('connection', (socket) => {
    // log.logUser(
    //     new Date(socket.handshake.time).toLocaleString(),
    //     socket.handshake.address.slice(7),
    //     socket.handshake.headers['user-agent'],
    //     'connected'
    // );

    // client event
    socket.on('door-south', (data, callback) => {
        // broadcast to all clients except the sender
        socket.broadcast.emit('door-south', data);

        triggerRelay();

        doorInterface = 'app';

        callback({
            status: 'OK'
        });
    });

    socket.on('disconnect', () => {
        // log.logUser(
        //     new Date().toLocaleString(),
        //     socket.handshake.address.slice(7),
        //     socket.handshake.headers['user-agent'],
        //     'disconnected'
        // );
    });

    // notify the client of the initial state of the door contact (open/closed)
    // on connect
    SWITCH_SOUTH.read(function (err, value) {
        doorStatusSouth = value;
        emitChangeOnEvent(socket, err, doorStatusSouth);
    });

    // notify the client when the door contact changes state (open/closed) on
    // connect
    SWITCH_SOUTH.watch(function (err, value) {
        doorStatusSouth = value;
        emitChangeOnEvent(socket, err, doorStatusSouth);
    });
});

SWITCH_SOUTH.watch(function (err, value) {
    doorStatusSouth = value;

    // set auto-close timer on open event
    if (!doorStatusSouth) {
        let timeRemaining = (DOOR_TIMEOUT/1000);

        timer = setInterval(() => {
            console.log(--timeRemaining);
        }, 1000);

        autoCloseTimer = setTimeout(function (doorStatusSouth) {
            if (!doorStatusSouth) { // if door is open
                triggerRelay();
                doorInterface = 'auto';
            }

            clearInterval(timer);
        }, DOOR_TIMEOUT, doorStatusSouth);
    // clear auto-close timer on close event
    } else {
        clearTimeout(autoCloseTimer);
        clearInterval(timer);
    }

    // log event (open/close with door contact) outside of IO connection,
    // otherwise duplicate log events result
    // log.logEvent(doorStatusSouth, doorInterface, 'south', new Date().toLocaleString());
    console.info({ doorStatusSouth, doorInterface });

    // set interface back to button after event is logged
    doorInterface = 'button';
});

SERVER.listen(PORT, () => {
    console.log(`HTTP server listening on port ${PORT}`);
});
