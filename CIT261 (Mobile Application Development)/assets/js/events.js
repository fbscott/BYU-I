var COUNTER = COUNTER || {};

COUNTER.countStart     = document.getElementById('js-count-start');
COUNTER.countStop      = document.getElementById('js-count-stop');
COUNTER.countContainer = document.getElementById('js-count-num');
COUNTER.seconds        = 0;
COUNTER.countValue;

COUNTER.countStart.addEventListener('touchstart', function () {

    COUNTER.countValue = setInterval(function () {
        COUNTER.seconds++;
        COUNTER.countContainer.innerHTML = COUNTER.seconds;
    }, 1000);
});

COUNTER.countStop.addEventListener('touchstart', function () {
    clearInterval(COUNTER.countValue);
});
