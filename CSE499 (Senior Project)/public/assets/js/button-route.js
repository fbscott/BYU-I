var button = document.getElementById('js-navigate');

button.addEventListener('click', (e) => {
  e.preventDefault();
  document.location = button.dataset.url;
});
