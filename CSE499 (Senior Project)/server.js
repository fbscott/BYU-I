// const url          = require('url');
const PATH         = require('path');
const EXPRESS      = require('express');
const HTTP         = require('http');
// const io           = require('socket.io')(SERVER);
const { Server }   = require('socket.io');
const { Gpio }     = require('onoff');
const LOG          = require('./log.js');

const APP          = EXPRESS();
const SERVER       = HTTP.createServer(APP);
const IO           = new Server(SERVER);
const SWITCH_SOUTH = new Gpio(17, 'in', 'both');
const RELAY        = new Gpio(23, 'out');
const PORT         = process.env.PORT || 8080;

let log            = new LOG();
let doorInterface  = 'button';

// allow server to use anything that lives in /public
APP.use(EXPRESS.static(PATH.join(__dirname + '/public')));
// view engine
APP.set('views', './views'); // object, directory
APP.set('view engine', 'ejs'); // render .ejs files as views

APP.get('/', (req, res) => {
    // res.sendFile(PATH.join(__dirname + '/public/index.htm'));
    res.render('pages/index', {
        title: 'Pi Garage | Home'
    });
});

APP.get('/log', (req, res) => {
    log.setData();

    res.render('pages/log', {
        title: 'Pi Garage | Log',
        button_route: '/',
        events: log.events
    });
});

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

// WebSocket connection
// io.sockets.on('connection', socket => {
IO.on('connection', socket => {
    log.logUser(
        new Date(socket.handshake.time).toLocaleString(),
        socket.handshake.address.slice(7),
        socket.handshake.headers['user-agent'],
        'connected'
    );

    // get door status from the client
    socket.on('door-south', data => {
        // broadcast to all clients except the sender
        // i.e., all other clients
        socket.broadcast.emit('door-south', data);

        RELAY.writeSync(1);

        setTimeout(() => {
            RELAY.writeSync(0);
        }, 1000);

        doorInterface = 'app';
    });

    socket.on('disconnect', () => {
        log.logUser(
            new Date().toLocaleString(),
            socket.handshake.address.slice(7),
            socket.handshake.headers['user-agent'],
            'disconnected'
        );
    });

    // emit change on initial page load
    SWITCH_SOUTH.read(function (err, value) {
        emitChangeOnEvent(socket, err, value);
    });

    // emit change on event (open/close with door contact)
    SWITCH_SOUTH.watch(function (err, value) {
        emitChangeOnEvent(socket, err, value);
    });
});

// log event (open/close with door contact)
SWITCH_SOUTH.watch(function (err, value) {
    log.logEvent(value, doorInterface, 'south', new Date().toLocaleString());
    doorInterface = 'button';
});

// APP.listen(PORT, () => {
//     console.log(`Express server listening on port ${PORT}`);
// });

SERVER.listen(PORT, () => {
    console.log(`HTTP server listening on port ${PORT}`);
});
