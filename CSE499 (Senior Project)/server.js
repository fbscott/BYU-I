// const url  = require('url');
// const fs = require('fs');
const PATH       = require('path');
const EXPRESS    = require('express');
const APP        = EXPRESS();
const HTTP       = require('http');
const SERVER     = HTTP.createServer(APP);
// const io         = require('socket.io')(SERVER);
const { Server } = require('socket.io');
const io         = new Server(SERVER);
const Gpio       = require('onoff').Gpio;

// const Person = require('./person.js');
// const person = new Person('Scott', 'CSE499');
const EXPRESS_PORT = process.env.PORT || 8888;
const IO_PORT = 3000;

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

// WebSocket Connection
io.sockets.on('connection', function (socket) {
    let _doorStatus = 0;

    //get light switch status from client
    socket.on('door-south', function(data) {
        _doorStatus = data;

        if (_doorStatus) {
            //turn LED on or off, for now we will just show it in console.log
            console.log(_doorStatus);
        }
    });
});

APP.listen(EXPRESS_PORT, () => {
    console.log('Express server running on port ' + EXPRESS_PORT);
});

SERVER.listen(IO_PORT, () => {
    console.log('socket.io listening on port ' + IO_PORT);
});

io.on('connection', (socket) => {
    console.log('user connected');
    socket.on('disconnect', () => {
        console.log('user disconnected');
    });
});
