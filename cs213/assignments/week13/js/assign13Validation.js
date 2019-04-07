/**
 * IS DUET
 * Checks performance value. If performance === 'duet', enable additional
 * student fields, else, disable them.
 * @param {Object} radio - selected performance (solo, duet, or concerto)
 */
PR.isDuet = function(radio) {
    let _value = radio.value;
    let _this  = this;

    if (_value === 'duet') {
        _this.duetArr.forEach(function(el) {
            _this.enableInput(el);
        });
    } else {
        _this.duetArr.forEach(function(el) {
            _this.disableInput(el);
        });
    }
};

/**
 * DISABLE INPUT FIELD
 * Receives a specified input and disables it.
 * @param {String} input - input field
 */
PR.disableInput = function(input) {
    let _input = input;

    _input.disabled = true;
};

/**
 * ENABLE INPUT FIELD
 * Receives a specified input and enables it.
 * @param {String} input - input field
 */
PR.enableInput = function(input) {
    let _input = input;

    _input.disabled = false;
};

PR.isValidName = function() {
    let _name  = this.value;
    let _error = document.getElementById('js-name-error');

    !_name ? _error.classList.add('show') : _error.classList.remove('show');
};

PR.isValidId = function() {
    let _name  = this.value;
    let _error = document.getElementById('js-ID-error');

    !_name ? _error.classList.add('show') : _error.classList.remove('show');
};

PR.isValidName2 = function() {
    let _name  = this.value;
    let _error = document.getElementById('js-name2-error');

    if (!_name && PR.performance !== 'duet') {
        _error.classList.add('show');
    } else {
        _error.classList.remove('show');
    }
};

PR.isValidId2 = function() {
    let _name  = this.value;
    let _error = document.getElementById('js-ID2-error');

    if (!_name && PR.performance !== 'duet') {
        _error.classList.add('show');
    } else {
        _error.classList.remove('show');
    }
};
