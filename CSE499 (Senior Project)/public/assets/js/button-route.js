/******************************************************************************
 * ROUTE ON BUTTON CLICK
 * Gets the route from the button's data attr and navigates based on that
 * value.
 *****************************************************************************/

var button = document.getElementById('js-navigate');

button.addEventListener('click', (e) => {
  e.preventDefault();
  document.location = button.dataset.url;
});
