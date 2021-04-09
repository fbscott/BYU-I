// inputs
var apr       = document.getElementById('apr');
var term      = document.getElementById('term');
var amount    = document.getElementById('amount');
var payment   = document.getElementById('payment');
var calculate = document.getElementById('calculate');
var clear     = document.getElementById('clear');
// valid inputs (booleans)
var aprIsValid;
var termIsValid;
var amountIsValid;

/*****************************************************************************
 * VALIDATE APR
 * APR must be greater than 0% and less than 25.00%.
 * Display error if the value is invalid.
 ****************************************************************************/
function validateAPR() {
    var _apr        = this.value;
    // validation criteria
    var _isValidAPR = _apr > 0 && _apr <= 25;
    // error DOM el
    var _aprError   = document.getElementById('apr-error');

    // hide/show error
    _isValidAPR ? _aprError.classList.add('hide') : _aprError.classList.remove('hide');

    // update global
    aprIsValid = _isValidAPR;
}

/*****************************************************************************
 * VALIDATE TERM
 * Term must be greater than 0(yrs) and less than 40(yrs).
 * Display error if the value is invalid.
 ****************************************************************************/
function validateTerm() {
    var _term        = this.value;
    // validation criteria
    var _isValidTerm = _term > 0 && _term <= 40;
    // error DOM el
    var _termError   = document.getElementById('term-error');

    // hide/show error
    _isValidTerm ? _termError.classList.add('hide') : _termError.classList.remove('hide');

    // update global
    termIsValid = _isValidTerm
}

/*****************************************************************************
 * VALIDATE AMOUNT
 * Amount must be greater than $0.00.
 * Display error if the value is invalid.
 ****************************************************************************/
function validateAmount() {
    var _amount        = this.value;
    // validation criteria
    var _isValidAmount = _amount > 0;
    // error DOM el
    var _amountError   = document.getElementById('amount-error');

    // hide/show error
    _isValidAmount ? _amountError.classList.add('hide') : _amountError.classList.remove('hide');

    // update global
    amountIsValid = _isValidAmount;
}

/*****************************************************************************
 * CALCULATE LOAN PAYMENT
 ****************************************************************************/
function calculatePayment() {
    var _amount  = amount.value;
    var _apr     = (apr.value) / 1200; // divide by # of months and 100 to get true %
    var _term    = (term.value) * 12;  // multiply by # of months in a year
    var _payment = _amount * _apr / (1 - (Math.pow(1 / (1 + _apr), _term)));
    
    return _payment.toFixed(2);
}

/*****************************************************************************
 * UPDATE THE DOM (Payment Amount)
 * Update the payment field if all required inputs are filled in and valid.
 ****************************************************************************/
function updateDOM() {
    var _calculateError = document.getElementById('calculate-error');

    // if all inputs are valid
    if(aprIsValid && termIsValid && amountIsValid) {
        // update the DOM
        payment.value = calculatePayment();
        // hide the error
        _calculateError.classList.add('hide');
    }
}

/*****************************************************************************
 * VALIDATE ON CLICK
 * Show error if 'Calculate' button is clicked and any input(s) is/are
 * invalid.
 ****************************************************************************/
function validateCalculation() {
    var _calculateError = document.getElementById('calculate-error');

    // if any of the inputs is invalid
    if(!aprIsValid || !termIsValid || !amountIsValid) {
        // update the DOM
        payment.value = '';
        // show the error
        _calculateError.classList.remove('hide');
        // give focus to input that requires valid data
        if(!aprIsValid) {
            apr.focus();
        } else if(!termIsValid) {
            term.focus();
        } else if(!amountIsValid) {
            amount.focus();
        }
    }
}

/*****************************************************************************
 * RESET GLOBAL BOOLEANS
 * Prevents the 'Payment' field from displaying 'NaN' if the 'Calculate'
 * button is clicked after reset.
 * Sets focus on first input field (APR).
 ****************************************************************************/
function resetValues() {
    // set all global booleans to false
    aprIsValid = false;
    termIsValid = false;
    amountIsValid = false;

    // set focus to APR field
    apr.focus();
}

// validate APR on change and/or blur
apr.addEventListener('blur', validateAPR);
apr.addEventListener('change', updateDOM);
// validate term on change and/or blur
term.addEventListener('blur', validateTerm);
term.addEventListener('change', updateDOM);
// validate amount on change and/or blur
amount.addEventListener('blur', validateAmount);
amount.addEventListener('change', updateDOM);
// calculate payment and/or show error if inputs are invalid
calculate.addEventListener('click', updateDOM);
calculate.addEventListener('click', validateCalculation);
// reset form
clear.addEventListener('click', resetValues);
