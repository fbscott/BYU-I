// const url  = require('url');
const PATH       = require('path');
const EXPRESS    = require('express');
const HTTP       = require('http');
// const io         = require('socket.io')(SERVER);
const { Server } = require('socket.io');
const GPIO       = require('onoff').Gpio;
const LOG        = require('./log.js');

const APP        = EXPRESS();
const SERVER     = HTTP.createServer(APP);
const IO         = new Server(SERVER);
const SWITCH     = new GPIO(17, 'in', 'both');
const RELAY      = new GPIO(23, 'out');
const PORT       = process.env.PORT || 8080;

let log          = new LOG();

// allow server to use anything that lives in /public
APP.use(EXPRESS.static(PATH.join(__dirname + '/public')));
// view engine
APP.set('views', './views'); // object, directory
APP.set('view engine', 'ejs'); // render .ejs files as views
APP.get('/', (req, res) => {
    res.sendFile(PATH.join(__dirname + '/public/index.htm'));
});
APP.get('/log', (req, res) => {
    let _title = 'Pi Garage | Log';

    log.setData();

    res.render('pages/log', {
        title: _title,
        button_route: '/',
        events: log.events
    });
});

/******************************************************************************
 * EMIT CHANGE ON EVENT
 * @param {Object} websocket 
 * @param {Object} err 
 * @param {Int} val 1: open, 2: closed
 * @returns null on error
 *****************************************************************************/
const emitChangeOnEvent = (websocket, err, val) => {
    let doorStatus = false;

    if (err) {
        console.error('Error: ', err);
        return;
    }

    doorStatus = val;

    log.logEvent(val, 'Button', new Date().toLocaleString());

    //send button status to client
    websocket.emit('door-south', doorStatus);
};

// // WebSocket connection
// io.sockets.on('connection', socket => {
IO.on('connection', socket => {
    log.logUser(
        new Date(socket.handshake.time).toLocaleString(),
        socket.handshake.address.slice(7),
        socket.handshake.headers['user-agent'],
        'connected'
    );

    // console.log(socket);

    // get door status from the client
    socket.on('door-south', data => {
        // broadcast to all clients except the sender
        // i.e., all other clients
        socket.broadcast.emit('door-south', data);

        RELAY.writeSync(1);

        setTimeout(() => {
            RELAY.writeSync(0);
        }, 1000);

        log.logEvent(data, 'App', new Date().toLocaleString());
    });

    socket.on('disconnect', () => {
        log.logUser(
            new Date().toLocaleString(),
            socket.handshake.address.slice(7),
            socket.handshake.headers['user-agent'],
            'disconnected'
        );
    });

    // Read hardware state on connect
    SWITCH.read(function (err, value) {
        emitChangeOnEvent(socket, err, value);
    });

    // Watch for hardware interrupts
    SWITCH.watch(function (err, value) {
        emitChangeOnEvent(socket, err, value);
    });
});

// APP.listen(PORT, () => {
//     console.log('Express server listening on port ' + PORT);
// });

SERVER.listen(PORT, () => {
    console.log('HTTP server listening on port ' + PORT);
});
