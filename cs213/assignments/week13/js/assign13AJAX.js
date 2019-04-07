/**
 * LOAD DOCUMENT
 * Build a query string, perform an XHR (AJAX) request, and build a table
 * containing the response data.
 */
PR.loadPianoRegistrationData = function() {
    PR.displayRecitalData.innerHTML = 'Loading . . .';

    // new request object
    let _xhr  = new XMLHttpRequest();
    let _queryString = '?firstName='   + PR.firstName.value +
                       '&lastName='    + PR.lastName.value +
                       '&studentID='   + PR.studentID.value +
                       '&performance=' + PR.performance.value +
                       '&skill='       + PR.skill.value +
                       '&instrument='  + PR.instrument.value +
                       '&location='    + PR.location.value +
                       '&room='        + PR.room.value +
                       '&time='        + PR.time.value +
                       '&firstName2='  + PR.firstName2.value +
                       '&lastName2='   + PR.lastName2.value +
                       '&studentID2='  + PR.studentID2.value;

    // when the state changes
    _xhr.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            let _response = this.responseText;
            // result
            let _tabularData = '<table><tbody><tr>' +
                                '<th>Name</th>' +
                                '<th>Student ID</th>' +
                                '<th>Performance</th>' +
                                '<th>Sill Level</th>' +
                                '<th>Instrument</th>' +
                                '<th>Location</th>' +
                                '<th>Room #</th>' +
                                '<th>Time</th>' +
                                '<th>Name 2</th>' +
                                '<th>Student ID 2</th>' +
                             '</tr>';

            _tabularData += _response;
            _tabularData += '</tbody></table>'

            // write to the DOM
            PR.displayRecitalData.innerHTML = _tabularData;
        }
    };

    // GET the requested file
    _xhr.open('GET', 'assign13.php' + _queryString, true);
    
    // send the GET request
    _xhr.send();
}
