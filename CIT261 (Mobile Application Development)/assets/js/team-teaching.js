// resources:
// https://www.w3schools.com/js/js_object_prototypes.asp
// https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Objects/Inheritance

/******************************************************************************
 * Aliens Object
 * Not strictly JSON, but you can use JSON if you want. Just parse your JSON
 * before using it to get it to this state: JSON.parse(text);
 *****************************************************************************/
var aliens = JSON.parse(localStorage.getItem('aliens')) || {

    et : {
        species: 'E.T.',
        homeWorld: 'unknown',
        discovered: 'Earth',
        isHazardous: false,
        info: 'E.T. just wants to go home.',
        img: './assets/img/et.jpg',
        movie: 'E.T.'
    },

    gray : {
        species: 'Classic Gray',
        homeWorld: 'unknown',
        discovered: 'Earth',
        isHazardous: false,
        info: 'The Classic Gray alien will abduct and probe you!',
        img: './assets/img/gray.jpg',
        movie: 'The X-Files'
    },

    klingon : {
        species: 'Klingon',
        homeWorld: 'Kronos',
        discovered: 'unknown',
        isHazardous: true,
        info: 'Klingons are moody.',
        img: './assets/img/klingon.jpg',
        movie: 'Star Trek'
    },

    predator : {
        species: 'Predator',
        homeWorld: 'Yautja Prime',
        discovered: 'Earth',
        isHazardous: true,
        info: 'Predator will rip out your spine!',
        img: './assets/img/predator.jpg',
        movie: 'Predator'
    },

    xenomorph : {
        species: 'Xenomorph',
        homeWorld: 'G-435',
        discovered: 'LV-426',
        isHazardous: true,
        info: 'Xenomorph will punch through your skull!',
        img: './assets/img/xenomorph.jpg',
        movie: 'Aliens'
    },

    yoda : {
        species: 'Yoda',
        homeWorld: 'Dagobah???',
        discovered: 'unknown',
        isHazardous: false,
        info: '"Do or do not. There is no try."',
        img: './assets/img/yoda.jpg',
        movie: 'Empire Strikes Back'
    }
};

/******************************************************************************
 * Alien Constructor Function
 *****************************************************************************/
function Alien(options) {
    // Scope-safe check. Makes sure all instances of "Alien" are called with
    // the "new" keyword.
    if(!(this instanceof Alien)) {
        return new Alien(options);
    }

    // Loop through properties of "options" object and assign them to "this."
    // Same as if each property was mapped individually.
    // E.g.: this.make  = options.make;
    //       this.model = options.model;
    //       etc.
    for(let property in options) {
        if(options.hasOwnProperty(property)) {
            // Doesn't work with dot-notation (this.property).
            this[property] = options[property];
        }
    }
}

/******************************************************************************
 * GET INFO
 * Get a pre-scripted message about the alien.
 *****************************************************************************/
Alien.prototype.getInfo = function() {
    if (this.isHazardous) {
        return this.species + ' is HAZARDOUS!!! KEEP AWAY!!!';
    } else {
        return this.species + ' is friendly. Go ahead and pet the little fella!';
    }
};

/******************************************************************************
 * SET PROPERTY
 * Prompts the user for a key/value pair to add to the object's properties.
 *****************************************************************************/
Alien.prototype.setProperties = function() {
    this.species     = prompt('What is this alien\'s species?');
    this.homeWorld   = prompt('What is ' + this.species + '\'s home world?');
    this.discovered  = prompt('Where was ' + this.species + ' discovered?');
    this.isHazardous = confirm('Is this alien known to be hazardous to humans? Click "OK" for "Yes" and "Cancel" for "No"');
    this.info        = prompt('Add a message about ' + this.species + ':');
    this.img         = './assets/img/alien.png';
};

/******************************************************************************
 * Global Namespace
 *****************************************************************************/
var ALIEN = ALIEN || {};

/******************************************************************************
 * CREATE ALIENS
 * New instances of 'Alien' for each property in 'aliens'
 * @param {Object} options - aliens object
 *****************************************************************************/
ALIEN.createAliens = function(options) {
    for (const property in options) {
        this[property] = new Alien(options[property]);
    }
};

/******************************************************************************
 * UPDATE THE DOM
 * Iterates over the aliens object and appends each property to the DOM.
 *****************************************************************************/
ALIEN.addAliensToDOM = function(options) {
    this.aliensContainer.innerHTML = '';

    for (const property in options) {
        let _alienNode = `<div class="columns large-4 end">
                            <a class="alien js-alien" href="javascript:void(0);" data-alien="${property}">
                              <img src="${options[property].img}" alt="${options[property].species}">
                              <span>${options[property].species}</span>
                            </a>
                          </div>`;

        // add all aliens to the DOM
        this.aliensContainer.insertAdjacentHTML('beforeend', _alienNode);
    }
};

/******************************************************************************
 * SHOW ALIEN DATA
 * Iterate over clickable alien links in the DOM. Display data for each alien.
 *****************************************************************************/
ALIEN.showAlienData = function() {
    let _this = this;
    let _alienLinks = document.getElementsByClassName('js-alien');

    for (var i = 0; i < _alienLinks.length; i++) {
        _alienLinks[i].addEventListener('click', function() {
            _this.alienAttrsContainer.innerHTML = `<h3>${_this[this.dataset.alien].species}</h3>
               <table>
                 <tr>
                   <td>Home World</td>
                   <td>${_this[this.dataset.alien].homeWorld}</td>
                 </tr>
                 <tr>
                   <td>Discovered</td>
                   <td>${_this[this.dataset.alien].discovered}</td>
                 </tr>
                 <tr>
                   <td>Hazardous</td>
                   <td>${_this[this.dataset.alien].isHazardous}</td>
                 </tr>
                 ${_this[this.dataset.alien].movie ? `<tr>
                   <td>Movie</td>
                   <td>${_this[this.dataset.alien].movie}</td>
                 </tr>` : ``}
               </table>
               <p class="margin-top-30 margin-bottom-15"><strong>${_this[this.dataset.alien].isHazardous ? `<span class="alien-red">WARNING!!!</span>` : `NOTE:`}</strong></p>
               <p>${_this[this.dataset.alien].getInfo()}</p>
               <p class="margin-top-30 margin-bottom-15"><strong>Additional Info:</strong></p>
               <p>${_this[this.dataset.alien].info}</p>`;
        });
    }
};

/******************************************************************************
 * CREATE NEW ALIEN
 * Creates a new alien on button click. Adds it to the 'aliens' object.
 *****************************************************************************/
ALIEN.createNewAlien = function(options) {
    let _this = this;
    let _addButton = document.getElementById('js-alien-add');

    _addButton.addEventListener('click', function() {
        // create a new ALIEN (so I can use object methods - getters/setters, etc.)
        _this['new_' + _this.newAlienCount] = new Alien();
        // set the alien's properties
        _this['new_' + _this.newAlienCount].setProperties();

        // add the new alien to the aliens object
        aliens['new_' + _this.newAlienCount] = _this['new_' + _this.newAlienCount];

        _this.addAliensToDOM(options);

        _this.showAlienData();

        // increment the new alien counter so existing aliens aren't overwritten
        _this.newAlienCount ++;
    });
};

/******************************************************************************
 * LOCAL STORAGE -- SETTER
 *****************************************************************************/
ALIEN.setState = function(options) {
    let _button = document.getElementById('js-save');

    _button.addEventListener('click', function() {
        localStorage.setItem('aliens', JSON.stringify(options));
    });
};

/******************************************************************************
 * LOCAL STORAGE -- GETTER
 *****************************************************************************/
ALIEN.getState = function() {
    return JSON.parse(localStorage.getItem('aliens'));
};

/******************************************************************************
 * LOCAL STORAGE -- CLEAR
 *****************************************************************************/
ALIEN.clearState = function() {
    let _button = document.getElementById('js-clear');
    let _obj;

    _button.addEventListener('click', function() {
        localStorage.removeItem('aliens');
    });
};

/******************************************************************************
 * INITIALIZER
 * Do all the things.
 *****************************************************************************/
ALIEN.init = function() {
    // DOM elements
    this.aliensContainer     = document.getElementById('js-aliens-container');
    this.alienAttrsContainer = document.getElementById('js-alien-attributes-container');

    // TODO: need to increment this counter in page load if localStorage already exists.
    this.newAlienCount = 1;

    // create all the alien objects
    if (localStorage.hasOwnProperty('aliens')) {
        let _aliens = this.getState()

        this.createAliens(_aliens);
        this.addAliensToDOM(_aliens);
        // add the aliens to the grid container
        // display data for clicked alien
        this.showAlienData();
        // add new alien to aliens object and update the DOM
        this.createNewAlien(_aliens);
    } else {
        this.createAliens(aliens);
        this.addAliensToDOM(aliens);
        // add the aliens to the grid container
        // display data for clicked alien
        this.showAlienData();
        // add new alien to aliens object and update the DOM
        this.createNewAlien(aliens);
    }
    // local storage
    this.setState(aliens);
    this.clearState();
};

ALIEN.init();
