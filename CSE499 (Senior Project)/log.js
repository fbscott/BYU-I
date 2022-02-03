// https://nodejs.org/en/knowledge/file-system/how-to-write-files-in-nodejs/
// https://stackoverflow.com/questions/36856232/write-add-data-in-json-file-using-node-js
const fs = require('fs');

class Log {
    constructor(status, doorInterface) {
        this.status = status;
        this.doorInterface = doorInterface;
    }
    
    greeting() {
        return `${this.status, doorInterface} connected.`;
    }

    /**************************************************************************
     * LOG EVENT
     * @param {Bool} status 0: open, 1: closed
     * @param {String} doorInterface GPIO or websocket
     * @param {String} time
     *************************************************************************/
    logEvent(status, doorInterface, time) {
        let doorStatus = status ? 'Closed' : 'Open';
        let obj = JSON.parse(fs.readFileSync('./public/assets/data/event-log.json', 'utf-8'));

        obj.events.push({
            doorStatus,
            doorInterface,
            time
        });

        let json = JSON.stringify(obj);

        fs.writeFileSync('./public/assets/data/event-log.json', json, 'utf-8');
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

    setData() {
        try {
            const data = fs.readFileSync('./public/assets/data/event-log.json', 'utf8');
            this.events = JSON.parse(data).events;
          } catch (err) {
            console.error(err)
          }
    };
}

module.exports = Log;
