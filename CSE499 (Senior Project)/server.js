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

// const Person = require('./person.js');
// const person = new Person('Scott', 'CSE499');
// const EXPRESS_PORT = process.env.PORT || 8888;
// const IO_PORT = process.env.PORT || 3000;
const PORT = process.env.PORT || 3000;

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

// // WebSocket connection
// io.sockets.on('connection', socket => {
IO.on('connection', socket => {
    let _doorStatus = false;

    console.log('user connected');

    // get door status from the client
    socket.on('door-south', data => {
        _doorStatus = data;

        if (!!_doorStatus) {
            console.log('South door is open.');
        } else {
            console.log('South door is closed.');
        }
    });

    socket.on('disconnect', () => {
        console.log('user disconnected');
    });

    setInterval(() => {
        _doorStatus = !_doorStatus;

        socket.emit('door-south', _doorStatus);
    }, 2000);
});

// APP.listen(EXPRESS_PORT, () => {
//     console.log('Express server listening on port ' + EXPRESS_PORT);
// });

SERVER.listen(PORT, () => {
    console.log('HTTP server listening on port ' + PORT);
});
