// DOM elements
var country       = document.getElementById('country');
var cities        = document.getElementById('cities');
var jsonRequested = document.getElementById('json-requested');
var jsonButton    = document.getElementById('json-button');
var jsonReturned  = document.getElementById('json-returned');

/**
 * GET most populated cities based on country selection
 */
function loadDoc() {
    // content while user waits
    cities.innerHTML = 'Loading . . .';

    // new request object
    let xhttp = new XMLHttpRequest();

    // when the state changes
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            cities.innerHTML = this.responseText;
        }
    };

    // GET the requested file
    xhttp.open('GET', this.value + '.txt', true);
    // send the GET request
    xhttp.send();
}

/**
 * GET student info based on user request
 */
function loadJSON() {
    // content while user waits
    jsonReturned.innerHTML = '<p style="margin-top:30px;">Loading . . .</p>';

    // new request object
    let xhttp = new XMLHttpRequest();

    // when the state changes
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            // parse the JSON
            let jsonObject = JSON.parse(this.responseText);
            // result
            let jsonParsed = '<table><tbody><tr><th>Name</th><th>Address</th><th>Major</th><th>GPA</th></tr>';

            // update the result
            for (let i = 0; i < jsonObject.students.length; i++) {
                jsonParsed += '<tr>';
                jsonParsed += '<td>' + jsonObject.students[i].first + ' ' +
                                       jsonObject.students[i].last + '</td>';
                jsonParsed += '<td>' + jsonObject.students[i].address.city + ', ' +
                                       jsonObject.students[i].address.state + ' ' +
                                       jsonObject.students[i].address.zip + '</td>';
                jsonParsed += '<td>' + jsonObject.students[i].major + '</td>';
                jsonParsed += '<td>' + jsonObject.students[i].gpa + '</td>';
                jsonParsed += '</tr>';
            }

            // close the result table
            jsonParsed += '</tbody></table>'

            // write to the DOM
            jsonReturned.innerHTML = jsonParsed;
        // if the AJAX call fails
        } else if (this.status == 403 || this.status == 404 || jsonRequested.value == false) {
            jsonReturned.innerHTML = '<p class="error">Please enter a valid file name.</p>';
        }
    };

    // GET the requested file
    xhttp.open('GET', jsonRequested.value, true);
    // send the GET request
    xhttp.send();
}

// listeners
country.addEventListener('change', loadDoc);
jsonButton.addEventListener('click', loadJSON);
