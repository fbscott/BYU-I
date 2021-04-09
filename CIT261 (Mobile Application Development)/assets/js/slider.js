var CUBE = CUBE || {};

CUBE.cube       = document.getElementsByClassName('js-cube')[0];
CUBE.sides      = document.getElementsByClassName('js-cube-side');
CUBE.transZ     = document.cubeValues.transZ;
CUBE.rot        = document.cubeValues.rot;
CUBE.dir        = document.cubeValues.dir;
CUBE.transZdisp = document.getElementById('js-transZ-value');
CUBE.rotdisp    = document.getElementById('js-rot-value');
CUBE.transZVal  = 122;
CUBE.rotVal     = 0;

CUBE.transZ.oninput = function() {
    CUBE.transZdisp.innerHTML = this.value;

    CUBE.sides[0].style.transform = "rotateY(0deg)   translateZ(" + this.value + "px) rotate(" + CUBE.rotVal + "deg)";
    CUBE.sides[1].style.transform = "rotateY(90deg)  translateZ(" + this.value + "px) rotate(" + CUBE.rotVal + "deg)";
    CUBE.sides[2].style.transform = "rotateY(180deg) translateZ(" + this.value + "px) rotate(" + CUBE.rotVal + "deg)";
    CUBE.sides[3].style.transform = "rotateY(-90deg) translateZ(" + this.value + "px) rotate(" + CUBE.rotVal + "deg)";
    CUBE.sides[4].style.transform = "rotateX(90deg)  translateZ(" + this.value + "px) rotate(" + CUBE.rotVal + "deg)";
    CUBE.sides[5].style.transform = "rotateX(-90deg) translateZ(" + this.value + "px) rotate(" + CUBE.rotVal + "deg)";

    if (this.value) {
        CUBE.transZVal = this.value;
    }
};

CUBE.rot.oninput = function() {
    CUBE.rotdisp.innerHTML = this.value;

    CUBE.sides[0].style.transform = "rotateY(0deg)   translateZ(" + CUBE.transZVal + "px) rotate(" + this.value + "deg)";
    CUBE.sides[1].style.transform = "rotateY(90deg)  translateZ(" + CUBE.transZVal + "px) rotate(" + this.value + "deg)";
    CUBE.sides[2].style.transform = "rotateY(180deg) translateZ(" + CUBE.transZVal + "px) rotate(" + this.value + "deg)";
    CUBE.sides[3].style.transform = "rotateY(-90deg) translateZ(" + CUBE.transZVal + "px) rotate(" + this.value + "deg)";
    CUBE.sides[4].style.transform = "rotateX(90deg)  translateZ(" + CUBE.transZVal + "px) rotate(" + this.value + "deg)";
    CUBE.sides[5].style.transform = "rotateX(-90deg) translateZ(" + CUBE.transZVal + "px) rotate(" + this.value + "deg)";

    if (this.value) {
        CUBE.rotVal = this.value;
    }
};

for (radio in CUBE.dir) {
    CUBE.dir[radio].onclick = function() {
        if (this.value == 'up') {
            CUBE.cube.style.animation = "loopUp 30s linear infinite";
        } else if (this.value == 'right') {
            CUBE.cube.style.animation = "loopRight 30s linear infinite";
        } else if (this.value == 'diagonal') {
            CUBE.cube.style.animation = "loopDiagonal 30s linear infinite";
        }
    }
}
