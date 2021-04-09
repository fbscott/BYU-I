// DOM elements
var form        = document.orderForm;
var address     = form.address;
var credit_card = form.credit_card;
var cvv         = form.cvv;
var exp_date    = form.exp_date;
var first_name  = form.first_name;
var last_name   = form.last_name;
var phone       = form.phone;
var total       = form.total;
var totalVal    = 0;

// DOM 0 events
address.onblur       = checkInputValidity;
address.onchange     = checkInputValidity;
credit_card.onblur   = checkInputValidity;
credit_card.onchange = checkInputValidity;
cvv.onblur           = checkInputValidity;
cvv.onchange         = checkInputValidity;
exp_date.onblur      = checkInputValidity;
exp_date.onchange    = checkInputValidity;
first_name.onblur    = checkInputValidity;
first_name.onchange  = checkInputValidity;
last_name.onblur     = checkInputValidity;
last_name.onchange   = checkInputValidity;
phone.onblur         = checkInputValidity;
phone.onchange       = checkInputValidity;

/**
 * CHECK INPUT VALIDITY
 * Check DOM element's validity with RegEx and input field length
 */
function checkInputValidity() {
    var _this    = this;
    var _isValid = _this.checkValidity();
    var _label   = _this.labels[0];

    if(_isValid) { // hide error message(s)
        _this.nextElementSibling.classList.remove('hide', 'invalid');
        _this.nextElementSibling.classList.add('valid');
        _label.classList.add('hide');
    } else { // show error message(s)
        _this.nextElementSibling.classList.remove('hide', 'valid');
        _this.nextElementSibling.classList.add('invalid');
        _label.classList.remove('hide');
    }
}

/*****************************************************************************
 * GET CHECKBOX VALUE(S)
 * Get values from check boxes and update the global "total" variable then
 * call updateTotal() to update the DOM
 ****************************************************************************/
function getCheckboxValue(el) {
    var _isChecked = el.checked;
    var _val       = Number(el.value);

    _isChecked ? totalVal += _val : totalVal -= _val;

    updateTotal();
}

/*****************************************************************************
 * UPDATE TOTAL INPUT FIELD
 ****************************************************************************/
function updateTotal() {
    total.value = totalVal.toFixed(2).replace(/\B(?=(\d{3})+(?!\d))/g, ",");
}

/*****************************************************************************
 * RESET GLOBAL BOOLEANS
 * Prevents the 'Payment' field from displaying 'NaN' if the 'Calculate'
 * button is clicked after reset.
 * Sets focus on first input field (APR).
 ****************************************************************************/
function resetValues() {
    first_name.focus();
}

function validateAll() {
    var address_is_valid     = address.checkValidity();
    var credit_card_is_valid = credit_card.checkValidity();
    var exp_date_is_valid    = exp_date.checkValidity();
    var first_name_is_valid  = first_name.checkValidity();
    var last_name_is_valid   = last_name.checkValidity();
    var phone_is_valid       = phone.checkValidity();

    if(!first_name_is_valid || !last_name_is_valid || !address_is_valid || !phone_is_valid || !credit_card_is_valid || !exp_date_is_valid) {
        // give focus to input that requires valid data
        if(!first_name_is_valid) {
            first_name.focus();
        } else if(!last_name_is_valid) {
            last_name.focus();
        } else if(!address_is_valid) {
            address.focus();
        } else if(!phone_is_valid) {
            phone.focus();
        } else if(!credit_card_is_valid) {
            credit_card.focus();
        } else if(!exp_date_is_valid) {
            exp_date.focus();
        }
    }
}
