// https://nodejs.org/en/knowledge/file-system/how-to-write-files-in-nodejs/
// https://stackoverflow.com/questions/36856232/write-add-data-in-json-file-using-node-js
const fs = require('fs');

class Log {
    constructor(status, layer) {
        this.status = status;
        this.layer = layer;
    }
    
    greeting() {
        return `${this.status, layer} connected.`;
    }

    /**************************************************************************
     * LOG EVENT
     * @param {Bool} status 1: open, 2: closed
     * @param {String} layer GPIO or websocket
     *************************************************************************/
    logEvent(status, layer) {
        let doorStatus = status ? 'Open' : 'Closed';
        let obj = {};
        var json = JSON.stringify(obj);

        fs.readFile('./public/assets/data/event-log.json', 'utf8', (err, data) => {
            if (err) {
                return console.log(err)
            } else {
                obj = JSON.parse(data);
                obj.events.push({
                    doorStatus,
                    layer
                });
                json = JSON.stringify(obj);

                fs.writeFile('./public/assets/data/event-log.json', json, 'utf8', () => {
                    console.log('event logged');
                }); // write it back
            }
        });
    };

    /**************************************************************************
     * LOG USER
     * @param {String} user user
     *************************************************************************/
     logUser(time, address, agent, status) {
        console.table({
            status,
            address,
            agent,
            time
        });
    };

    readLog() {
        fs.readFile('./public/assets/data/event-log.json', 'utf8', (err, data) => {
            if (err) {
                return console.log(err)
            } else {
                console.log(data);
                return data;
            }
        });
    };
}

module.exports = Log;
