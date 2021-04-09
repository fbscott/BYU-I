// global namespace
// banner ad (BAN)
var BAN = BAN || {};

// DOM elements
BAN.bannerPitch  = document.getElementById('transition-banner-sales-pitch');
BAN.bannerThanks = document.getElementById('transition-banner-thanks');
BAN.bannerButton = document.getElementById('transition-banner-button');
BAN.bannerImg    = document.getElementById('transition-banner-img');

// when the page is ready
window.onload = function() {
    // show the sales pitch
    BAN.bannerPitch.classList.add('show');
    // show the sleazy salesman
    BAN.bannerImg.classList.add('show');
};

// when the button is clicked
BAN.bannerButton.addEventListener('click', function() {
    // show "thank you" message
    BAN.bannerThanks.classList.add('show');
});
