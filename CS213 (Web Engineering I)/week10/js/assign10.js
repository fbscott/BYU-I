var phpResponse = document.getElementById('js-phpResponse');
var requestBtn  = document.getElementById('js-button');

function updateDiv() {
    // content while user waits
    phpResponse.innerHTML = 'Loading . . .';

    // new request object
    let xhttp = new XMLHttpRequest();

    // when the state changes
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            // response (parsed as JSON)
            let jsonObject = JSON.parse(this.responseText);
            // result
            let jsonParsed = '<table><tbody><tr><th>File Name</th><th>File Type</th><th>Current Working Directory</th><th>View Contents</th></tr>';

            for (var i = 0; i < jsonObject.length; i++) {
                jsonParsed += '<tr>';
                jsonParsed += '<td>' + jsonObject[i].fileName + '</td>';
                jsonParsed += '<td>' + jsonObject[i].fileType + '</td>';
                jsonParsed += '<td>' + jsonObject[i].cwd + '</td>';
                if(jsonObject[i].fileType === 'file') {
                    // navigate via link
                    // jsonParsed += '<td><a href="' + jsonObject[i].fileName + '" target="blank">' + jsonObject[i].fileName + '</a></td>';
                    // navigate via button
                    jsonParsed += '<td><button name="button" onclick="window.open(\'' + jsonObject[i].fileName + '\', \'_blank\')">Click to Display</button></td>';
                } else {
                    jsonParsed += '<td>&nbsp;</td>';
                }
                jsonParsed += '</tr>';
            }


            // close the result table
            jsonParsed += '</tbody></table>'

            // write to the DOM
            phpResponse.innerHTML = jsonParsed;
        }
    };

    // GET the requested file
    xhttp.open('GET', 'assign10.php', true);
    // send the GET request
    xhttp.send();
}

// listeners
requestBtn.addEventListener('click', updateDiv);
