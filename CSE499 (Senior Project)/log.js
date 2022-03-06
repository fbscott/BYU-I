// https://nodejs.org/en/knowledge/file-system/how-to-write-files-in-nodejs/
// https://stackoverflow.com/questions/36856232/write-add-data-in-json-file-using-node-js
const fs = require('fs');

class Log {
    constructor(status, doorInterface) {
        this.status = status;
        this.doorInterface = doorInterface;
    }
    
    // greeting() {
    //     return `${this.status, doorInterface} connected.`;
    // }

    /**************************************************************************
     * LOG EVENT
     * @param {Bool} status 0: open, 1: closed
     * @param {String} doorInterface GPIO or websocket
     * @param {String} door SOUTH/NORTH
     * @param {String} time
     *************************************************************************/
    logEvent(status, doorInterface, door, time) {
        let doorStatus = status ? 'closed' : 'opened';
        let obj = JSON.parse(fs.readFileSync('./public/assets/data/event-log.json', 'utf-8'));

        obj.events.push({
            doorStatus,
            doorInterface,
            door,
            time
        });

        let json = JSON.stringify(obj);

        fs.writeFileSync('./public/assets/data/event-log.json', json, 'utf-8');
    };

    /**************************************************************************
     * LOG USER
     * @param {String} time
     * @param {String} address client IP address
     * @param {String} agent client browser
     * @param {String} status connected/disconnected
     *************************************************************************/
     logUser(time, address, agent, status) {
        let obj = JSON.parse(fs.readFileSync('./public/assets/data/user-log.json', 'utf-8'));

        obj.users.push({
            status,
            address,
            agent,
            time
        });

        let json = JSON.stringify(obj);

        fs.writeFileSync('./public/assets/data/user-log.json', json, 'utf-8');
    };

    /**************************************************************************
     * GET LOG DATA
     *************************************************************************/
    getData() {
        try {
            const eventData = fs.readFileSync('./public/assets/data/event-log.json', 'utf8');
            const loginData = fs.readFileSync('./public/assets/data/user-log.json', 'utf8');
            this.events = JSON.parse(eventData).events;
            this.users = JSON.parse(loginData).users;
        } catch (err) {
            console.error(err)
        }
    };
}

module.exports = Log;
