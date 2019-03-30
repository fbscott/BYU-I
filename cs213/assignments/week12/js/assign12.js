/**
 * MILEAGE CALCULATOR
 * Fetch travel data via AJAX then append that data (in tabular format) to the DOM.
 *
 * DOM Dependencies - #js-travel-data   results container
 *                  - #js-button        call to action
 *                  - input             user-provided data
 *
 * JS Dependencies - None. Vanilla JS.
 *
 * @author Scott Currell
 */

// DOM element to be updated
var distance = document.getElementById('js-travel-data');
var button   = document.getElementById('js-button');
// input array
var inputArr = document.getElementsByTagName('input');

/**
 * LOAD DOCUMENT
 * Build a query string, perform an XHR (AJAX) request, and build a table
 * containing the response data.
 */
function loadDoc() {
    // content while user waits
    distance.innerHTML = 'Loading . . .';

    // new request object
    let _xhr     = new XMLHttpRequest();
    // JSON path
    let _baseURI = '/cgi-bin/ercanbracks/mileage/mileageAjaxJSON';
    // data to be appended to _baseURI (the query string)
    let _fullURI = _baseURI +
                    '?startCity='  + inputArr[1].value +
                    '&startState=' + inputArr[0].value +
                    '&endCity='    + inputArr[3].value +
                    '&endState='   + inputArr[2].value;

    // when the state changes
    _xhr.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200 && validateForm()) {
            // response (parsed as JSON)
            let jsonObject = JSON.parse(this.responseText);
            // result
            let jsonParsed = '<table><tbody><tr><th>Origin</th><th>Destination</th><th>Distance</th><th>Travel Modes</th></tr>';

            // build the table
            jsonParsed += '<tr>';
            jsonParsed += '<td>' + jsonObject.trip.startcity + ', ' + 
                                   jsonObject.trip.startstate + '</td>';
            jsonParsed += '<td>' + jsonObject.trip.endcity + ', ' + 
                                   jsonObject.trip.endstate + '</td>';
            jsonParsed += '<td>' + jsonObject.trip.miles + '</td>';
            jsonParsed += '<td>' + jsonObject.trip.tmode + '</td>';
            jsonParsed += '</tr>';
            jsonParsed += '</tbody></table>'

            // write to the DOM
            distance.innerHTML = jsonParsed;
        }
    };

    // GET the requested file
    _xhr.open('GET', _fullURI, true);
    
    // send the GET request
    _xhr.send();
}

/**
 * VALIDATE THE FORM
 * Check inputs for data. Display error if input is blank.
 * @return {Boolean} is the form valid?
 */
function validateForm() {
    // start off true
    let _isValid = true;

    for (var i = inputArr.length - 1; i >= 0; i--) {
        if (!inputArr[i].value) {
            _isValid = false;
            distance.innerHTML = 'Please resolve the errors above.';
            // show error
            inputArr[i].nextElementSibling.style.display = 'initial';
        } else {
            // hide error
            inputArr[i].nextElementSibling.style.display = 'none';
        }
    }

    return _isValid;
}

button.addEventListener('click', loadDoc);
