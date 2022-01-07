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

APP.get('/home', (req, res) => {
    res.render('pages/home');
});

APP.listen(PORT, () => console.log('Server running on port ' + PORT));

// function onRequest(req, res) {
//     console.log('Received request for: ' + req.url);

//     switch (req.url) {
//         case '/':
//             res.writeHead(200, {"Content-Type": "text/html"});
//             res.write(person.greeting());
//             res.end();
//             break;
//         case '/home':
//             fs.readFile(path.join(__dirname, 'public', 'index.htm'), 'utf8', (err, content) => {
//                 if (err) throw err;
//                 res.writeHead(200, {"Content-Type": "text/html"});
//                 res.end(content);
//             });
//             break;
//         case '/getData':
//             res.writeHead(200, {"Content-Type": "application/json"});
//             res.end(JSON.stringify(person));
//             break;
//         default:
//             fs.readFile(path.join(__dirname, 'public', 'page-not-found.htm'), 'utf8', (err, content) => {
//                 if (err) throw err;
//                 // console.log({
//                 //     dirname: __dirname,
//                 //     path: path.dirname(__dirname),
//                 //     content: content,
//                 //     request_url: req.url,
//                 //     args: [process.argv[0], process.argv[1]]
//                 // });
//                 res.writeHead(200, {"Content-Type": "text/html"});
//                 res.end(content);
//             });
//     }
// }

// var server = http.createServer(onRequest);

// server.listen(PORT, () => console.log('Server running on port ' + PORT));
