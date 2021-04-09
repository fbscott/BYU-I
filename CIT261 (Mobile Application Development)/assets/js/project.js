// global namespace: Memory Match (MM)
var MM = MM || {};

MM.theme; // query
MM.highScore = 0;

// DOM elements
MM.scoreCard      = document.getElementById('js-score');
MM.highScoreCard  = document.getElementById('js-high-score');
MM.panelContainer = document.getElementById('js-panel-container');
MM.loadGame       = document.getElementById('js-load-game');
MM.saveGame       = document.getElementById('js-save-game');
MM.clearGame      = document.getElementById('js-clear-game');
MM.saveState      = document.getElementById('js-save-state');
MM.userInput      = document.memMatch;

// Event listeners
MM.loadGame.addEventListener('click',   () => { MM.loadGameData();   });
MM.saveGame.addEventListener('click',   () => { MM.setGameStats();   });
MM.clearGame.addEventListener('click',  () => { MM.clearGameStats(); });
MM.userInput.addEventListener('submit', e  => { MM.setAndAnimate(e); });

/******************************************************************************
 * SET THEME AND ANIMATE SLIDES
 * @param {Event} e - event
 *****************************************************************************/
MM.setAndAnimate = e => {

    // keep page from refreshing
    e.preventDefault();

    // set the theme as provided by the user
    MM.setTheme();

    let _slide1 = document.getElementsByClassName('slide-in-1')[0];
    let _slide2 = document.getElementsByClassName('slide-in-2')[0];
    let _slide3 = document.getElementsByClassName('slide-in-3')[0];

    // initialize the game
    if (_slide1 && _slide2 && _slide3) {

        _slide1.classList.add('slide-out-1');
        _slide2.classList.add('slide-out-2');
        _slide3.classList.add('slide-out-3');
        
        setTimeout(() => {
            MM.init();
        }, 750);
    // re-initialize the game after a new theme is selected
    } else {
        MM.init();
    }
};

/******************************************************************************
 * IS VALID NUMBER
 * Validation check. See if a passed number already exists in an array.
 * @param  {Int}   num - number to check against the array
 * @param  {Array} arr - existing numbers
 * @return {Bool}
 *****************************************************************************/
MM.isValidNumber = (num, arr = []) => !arr.includes(num) ? true : false;

/******************************************************************************
 * RANDOM NUMBER GENERATOR
 * Generates and returns a random number between and including a min/max range.
 * Minimum and maximum inclusive.
 * @param  {int}   max - maximum value
 * @param  {int}   min - minimum value
 * @param  {Array} arr - for validation check
 * @return {Int} randomized number from min to max inclusive
 *****************************************************************************/
MM.getRandomNumber = (max, min = 0, arr = []) => {

    // random number between and including range
    const RAND = Math.floor(Math.random() * max);

    // make sure random number doesn't already exist in the array
    if (MM.isValidNumber(RAND, arr)) {
        // TODO: refactor this double array push
        //       it's a clumsy way of getting the duplicate
        //       numbers I want for the panels
        arr.push(RAND);
        return RAND;
    } else {
        // recursive call if validation fails
        return MM.getRandomNumber(max, min, arr);
    }
};

/******************************************************************************
 * GET IMAGE INDICES
 * Creates and returns an array of random numbers.
 * @return {Array} - array of random numbers
 *****************************************************************************/
MM.getImageIndices = () => {

    const MAX = 20;
    const MIN = 0;

    let _numsArr = [];

    for (let i = 0; i < 6; i++) {
        // TODO: fix hackiness from other array push in MM.getRandomNumber
        _numsArr.push(MM.getRandomNumber(MAX, MIN, _numsArr));
    }

    return _numsArr;
};

/******************************************************************************
 * ARRAY SHUFFLER
 * Takes an array as a parameter and shuffles its contents. Returns the
 * original array in a different order.
 * Source: https://stackoverflow.com/questions/2450954/how-to-randomize-shuffle-a-javascript-array#answer-2450976
 * @param  {Array} array - array to be shuffled
 * @return {Array} shuffled array
 *****************************************************************************/
MM.shuffleArray = array => {

  let _currentIndex = array.length;
  let _temporaryValue;
  let _randomIndex;

  // While there remain elements to shuffle...
  while (0 !== _currentIndex) {

    // Pick a remaining element...
    _randomIndex = Math.floor(Math.random() * _currentIndex);
    _currentIndex -= 1;

    // And swap it with the current element.
    _temporaryValue = array[_currentIndex];
    array[_currentIndex] = array[_randomIndex];
    array[_randomIndex] = _temporaryValue;
  }

  return array;
};

/******************************************************************************
 * IS A MATCH
 * Checks to see if two data attributes are the same
 * @param {Array} arr - array of DOM elements
 * @return {Bool} _isMatch
 *****************************************************************************/
MM.isMatch = arr => {

    let _isMatch = false;

    for (let i = 0; i < arr.length; i++) {
        if (arr.length === 2 &&
            arr[0].dataset.id === arr[1].dataset.id) {
            _isMatch = true;
        }
    }

    return _isMatch;
};

/******************************************************************************
 * ADVANCE SCORE
 * Advance game and best scores.
 *****************************************************************************/
MM.advanceScore = () => {

    MM.score++;

    MM.scoreCard.innerHTML = MM.score;

    if ((MM.flippedCount === 12 && MM.highScore === 0) ||
        MM.flippedCount === 12 && MM.score < MM.highScore) {
        MM.highScore = MM.score;
        MM.highScoreCard.innerHTML = MM.score;
    }
};

/******************************************************************************
 * PANEL FLIPPER
 * Flips the panels over when clicked
 *****************************************************************************/
MM.flipPanels = el => {

    const EL = el.currentTarget;

    // flip a max of 2 panels at a time, but only those that are not already flipped or disabled
    if (!EL.classList.contains('flip', 'disabled') && MM.flippedCount < MM.maxFlipCount) {

        EL.classList.toggle('flip');

        MM.flippedPanels = document.getElementsByClassName('js-panel-flip flip');

        // check flipped panels to make sure they're a match
        if (MM.isMatch(MM.flippedPanels)) {
            [].forEach.call(MM.flippedPanels, flippedPanel => {
                // prevent them from flipping back over once matched
                flippedPanel.classList.add('disabled', 'js-disabled');
                MM.maxFlipCount += 1;
            });
        }

        const DISABLED_PANELS = document.getElementsByClassName('js-disabled');

        [].forEach.call(DISABLED_PANELS, disabledPanel => {
            disabledPanel.classList.remove('flip');
            // remove click handler
            // allows other panels to be flipped after match
            disabledPanel.removeEventListener('click', MM.flipPanels);
        });

        MM.flippedCount++;
        
        MM.advanceScore();

    // flip a panel back over if it's already flipped
    } else if(EL.classList.contains('flip', 'disabled')) {

        EL.classList.toggle('flip');
        
        MM.flippedCount--;
    }
};

/******************************************************************************
 * ON PANEL CLICK
 * Listens for panel click event
 *****************************************************************************/
MM.onPanelClick = () => {

    // all panels
    MM.panels = document.getElementsByClassName('js-panel-flip');

    // flip panels on click
    for (let i = 0; i < MM.panels.length; i++) {
        MM.panels[i].addEventListener('click', MM.flipPanels);
    }
};

/******************************************************************************
 * UPDATE THE DOM
 * @param  {Object} data - parsed JSON object array
 *****************************************************************************/
MM.updateTheDOM = data => {

    const IMG_ARRAY = MM.shuffleArray(MM.getImageIndices());

    // build panel container
    let _panels = `<div class="row slide-in-1" style="left: 2000px;">`;

    // add 12 panels to the container
    for (let i = 0; i < IMG_ARRAY.length; i++) {
        // break panels up into rows of four
        if (i != 0 && i % 4 === 0) {
            _panels += `</div><div class="row slide-in-${(i % 3) + 1}" style="left: 2000px;">`;
        }

        // individual panel markup
        _panels += `<div class="column small-3">
                     <div class="panel-container">
                       <div class="panel-flip js-panel-flip" data-id="${data.hits[IMG_ARRAY[i]].id}">
                         <div class="panel-front">
                           <img src="./assets/img/question_mark.png" width="113" height="113" />
                         </div>
                         <div class="panel-back"
                              style="background-image: url(${data.hits[IMG_ARRAY[i]].webformatURL})">
                         </div>
                       </div>
                     </div>
                   </div>`;
    }

    // close container
    _panels += `</div>`;

    // update the DOM
    MM.panelContainer.innerHTML = _panels;

    // add flip logic
    MM.onPanelClick();
};

/******************************************************************************
 * SET THEME
 * Set the theme to the one provided by the user. Receives a string of just a
 * few words and updates the global namespace. Theme is collected on form
 * submit.
 *****************************************************************************/
MM.setTheme = () => !!MM.userInput.theme.value ?
    MM.theme = MM.userInput.theme.value :
        MM.theme = 'bbq';

/******************************************************************************
 * GET THEME
 * Returns the user-defined theme for the game.
 * @return {String} MM.theme - user-defined theme
 *****************************************************************************/
MM.getTheme = () => MM.theme;

/******************************************************************************
 * LOAD DOCUMENT
 * Perform an XMLHttpRequest (AJAX) request and pass the response data to the
 * callback.
 * @param {String}   url           - API url
 * @param {Function} localCallback - callback that will handle the AJAX
 *                                     response
 *****************************************************************************/
MM.ajax = (url, loadCallback) => {

    // placeholder while loading
    MM.panelContainer.innerHTML = `<div class="row">
                                     <div class="column">
                                       <div class="spinner"></div>
                                     </div>
                                   </div>`;

    let _xhr = new XMLHttpRequest();

    _xhr.onreadystatechange = function() {
        if (this.readyState === 4 && this.status === 200) {
            // response (parsed as JSON)
            let _jsonObject = JSON.parse(_xhr.responseText);

            // pass the parsed response to the DOM loader
            loadCallback(_jsonObject);
        }
    };

    _xhr.open('GET', url, true);
    _xhr.send();
};

/******************************************************************************
 * CONFIGURE API
 * Set up the key/value pairs needed to make the API call to pixabay. Base URL
 * and API key remain constant, but the query (theme) key is dynamic.
 *****************************************************************************/
MM.configureAPI = () => {

    MM.baseURL = 'https://pixabay.com/api/';
    MM.key     = '15462183-52054d7c5a68977efe09803b8';
    MM.theme   = MM.getTheme();
};

/******************************************************************************
 * SET GAME STATS
 * Set game data to local storage.
 *****************************************************************************/
MM.setGameStats = () => {

    let _gameStats = {
        theme     : MM.getTheme(),
        highScore : MM.highScore
    };

    localStorage.setItem('gameData', JSON.stringify(_gameStats));

    MM.saveState.innerHTML = `<div class="column">
                                <div class="save-container text-left">
                                  <p class="margin-bottom-0">Game Saved!</p>
                                </div>
                              </div>`;
    MM.saveState.classList.add('opacity-one');

    setTimeout(() => {
        MM.saveState.classList.remove('opacity-one');
    }, 3000);
};

/******************************************************************************
 * GET GAME STATS
 * Get game data from local storage.
 *****************************************************************************/
MM.getGameStats = () => JSON.parse(localStorage.getItem('gameData'));

/******************************************************************************
 * CLEAR GAME STATS
 * Clear game data from local storage.
 *****************************************************************************/
MM.clearGameStats = () => {

    localStorage.removeItem('gameData');

    MM.saveState.innerHTML = `<div class="column">
                                <div class="save-container text-left">
                                  <p class="margin-bottom-0">Game Data Deleted.</p>
                                </div>
                              </div>`;
    MM.saveState.classList.add('opacity-one');

    setTimeout(() => {
        MM.saveState.classList.remove('opacity-one');
    }, 3000);
};

/******************************************************************************
 * LOAD GAME DATA
 * Get game data from local storage, load it into the DOM, and invoke the game.
 *****************************************************************************/
MM.loadGameData = () => {

    let _stats = MM.getGameStats();

    MM.highScore = _stats.highScore;

    if (_stats) {
        MM.userInput.theme.value   = _stats.theme;
        MM.highScoreCard.innerHTML = MM.highScore
        MM.userInput.submit.click();

        MM.saveState.innerHTML = `<div class="column">
                                    <div class="save-container text-left">
                                      <p class="margin-bottom-0">Game Data Loaded.</p>
                                    </div>
                                  </div>`;
        MM.saveState.classList.add('opacity-one');

        setTimeout(() => {
            MM.saveState.classList.remove('opacity-one');
        }, 3000);
    }
};

/******************************************************************************
 * INITIALIZER
 * Do all the things
 *****************************************************************************/
MM.init = () => {

    // default values
    MM.maxFlipCount = 2;
    MM.score        = 0;
    MM.flippedCount = 0; // number of flipped panels

    MM.scoreCard.innerHTML = MM.score;

    MM.configureAPI();

    MM.ajax(MM.baseURL + '?key=' +
            MM.key + '&q=' +
            MM.theme + '&image_type=photo',
            MM.updateTheDOM);
};
