// const url  = require('url');
// const fs = require('fs');
const PATH       = require('path');
const EXPRESS    = require('express');
const APP        = EXPRESS();
const HTTP       = require('http');
const SERVER     = HTTP.createServer(APP);
// const io         = require('socket.io')(SERVER);
const { Server } = require('socket.io');
const IO         = new Server(SERVER);
const GPIO       = require('onoff').Gpio;
const SWITCH     = new GPIO(17, 'in', 'both');

// const Person = require('./person.js');
// const person = new Person('Scott', 'CSE499');
// const EXPRESS_PORT = process.env.PORT || 8888;
const HTTP_PORT = process.env.PORT || 3000;

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
    
    res.render('pages/log', {
        title: _title
    });
});

/******************************************************************************
 * LOG EVENT
 * @param {Bool} data 1: open, 2: closed
 * @param {String} layer GPIO or websocket
 *****************************************************************************/
const logEvent = (data, layer) => {
    let doorStatus = data ? 'Open' : 'Closed';

    console.log(`${doorStatus} (${layer})`);
};

// // WebSocket connection
// io.sockets.on('connection', socket => {
IO.on('connection', socket => {
    let doorStatus = false;

    console.log('user connected');
    console.table({
        'time': new Date(socket.handshake.time).toLocaleString(),
        'client address': socket.handshake.address.slice(7)
    });

    // get door status from the client
    socket.on('door-south', data => {
        // broadcast to all clients except the sender
        // i.e., all other clients
        socket.broadcast.emit('door-south', data);

        logEvent(data, 'websocket');
    });

    socket.on('disconnect', () => {
        console.log('user disconnected');
    });

    // Watch for hardware interrupts
    SWITCH.watch(function (err, value) {
        if (err) {
            console.error('Error: ', err);
            return;
        }

        doorStatus = value;

        logEvent(value, 'GPIO');

        //send button status to client
        socket.emit('door-south', doorStatus);
    });
});

// APP.listen(EXPRESS_PORT, () => {
//     console.log('Express server listening on port ' + EXPRESS_PORT);
// });

SERVER.listen(HTTP_PORT, () => {
    console.log('HTTP server listening on port ' + HTTP_PORT);
});
