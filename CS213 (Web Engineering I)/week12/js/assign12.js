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
 * @author [student name obfuscated]
 */

// DOM element to be updated
var displayTravelData = document.getElementById('js-travel-data');
// call to action
var button            = document.getElementById('js-button');
// input array
var inputArr          = document.getElementsByTagName('input');

/**
 * LOAD DOCUMENT
 * Build a query string, perform an XHR (AJAX) request, and build a table
 * containing the response data.
 */
function loadTravelData() {
    displayTravelData.innerHTML = 'Loading . . .';

    // new request object
    let _xhr     = new XMLHttpRequest();
    // JSON path
    let _baseURI = '/cgi-bin/ercanbracks/mileage/mileageAjaxJSON';
    // data to be appended to _baseURI (the query string)
    let _fullURI = _baseURI +
                   '?startCity='  + inputArr[1].value +
                   '&startState=' + inputArr[0].value.toUpperCase() +
                   '&endCity='    + inputArr[3].value +
                   '&endState='   + inputArr[2].value.toUpperCase();

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
            displayTravelData.innerHTML = jsonParsed;
        }
    };

    // GET the requested file
    _xhr.open('GET', _fullURI, true);
    
    // send the GET request
    _xhr.send();
}

/**
 * VALIDATE INPUT
 * Validate individual inputs. Display error if input is invalid.
 */
function validateInput(el) {
    // reference to the input being validated
    let _this;

    // determine what "el" is
    // can be either text (from an input) or an event (from the listener below)
    el.type === 'text' ? _this = el : _this = this;

    // state length != 2 characters
    if ((_this.name === 'startState' || _this.name === 'endState') && _this.value.length != 2) {
        // tell user to resolve errors
        displayTravelData.innerHTML = 'Please resolve the errors above.';
        // show error
        _this.nextElementSibling.style.display = 'initial';
        return false;
    // input is blank
    } else if (!_this.value) {
        displayTravelData.innerHTML = 'Please resolve the errors above.';
        // show error
        _this.nextElementSibling.style.display = 'initial';
        return false;
    // input properly filled out
    } else {
        // hide error
        _this.nextElementSibling.style.display = 'none';
        return true;
    }
}

/**
 * VALIDATE THE FORM
 * Check all inputs for data. Display error if input is blank.
 * @return {Boolean} is the form valid?
 */
function validateForm() {
    // start off true
    let _isValid = true;

    // check individual inputs for validity
    for (var i = inputArr.length - 1; i >= 0; i--) {
        _isValid = validateInput(inputArr[i]);
    }

    return _isValid;
}

button.addEventListener('click', loadTravelData);

for (var i = inputArr.length - 1; i >= 0; i--) {
    inputArr[i].addEventListener('change', validateInput);
}
