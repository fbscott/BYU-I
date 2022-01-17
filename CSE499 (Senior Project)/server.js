// const http = require('http');
// const url  = require('url');
const PATH = require('path');
const EXPRESS = require('express');
const APP = EXPRESS();
// const fs = require('fs');
// const Person = require('./person.js');
// const person = new Person('Scott', 'CSE499');
const PORT = process.env.PORT || 8888;

// allow server to use anything that lives in /public
APP.use(EXPRESS.static(PATH.join(__dirname + '/public')));

// view engine
APP.set('views', './views'); // object, directory
APP.set('view engine', 'ejs'); // render .ejs files as views

APP.get('/', (req, res) => {
    res.sendFile(PATH.join(__dirname + '/public/index.htm'));
});

APP.get('/log', (req, res) => {
    let _title = "Pi Garage | Log";

    res.render('pages/log', {
        title: _title
    });
});

APP.listen(PORT, () => console.log('Server running on port ' + PORT));
