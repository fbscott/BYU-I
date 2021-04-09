/*****************************************************************************
 * Recreation of the 1970's PONG game.
 * 
 * Author: Scott Currell
 *
 * Adapted from Chris DeLeon's Udemy course: Code Your First Game: Arcade
 * Classic in JavaScript on Canvas
 * https://www.udemy.com/code-your-first-game/
 ****************************************************************************/

// Canvas
const CANVAS         = document.getElementById('pong');
const CANVAS_CONTEXT = CANVAS.getContext('2d');
const CANVAS_WIDTH   = CANVAS.width;
const CANVAS_HEIGHT  = CANVAS.height;

// Colors
const WHITE       = '#ffffff';
const BLACK       = '#000000';
const BOARD_COLOR = BLACK;
const PIECE_COLOR = WHITE;

// Game pieces
const BALL_WIDTH     = 10;
const BALL_HEIGHT    = 10;
var ballX            = (CANVAS_WIDTH / 2) - (BALL_WIDTH / 2);
var ballY            = (CANVAS_HEIGHT / 2) - (BALL_HEIGHT / 2);
const PADDLE_WIDTH   = 10;
const PADDLE_HEIGHT  = 100;
const PADDLE_LEFT_X  = 20;
const PADDLE_RIGHT_X = CANVAS_WIDTH - (20 + PADDLE_WIDTH);
var paddleLeftY      = (CANVAS_HEIGHT / 2) - (PADDLE_HEIGHT / 2);
var paddleRightY     = (CANVAS_HEIGHT / 2) - (PADDLE_HEIGHT / 2);

// Motion
var ballSpeedX = -10;
var ballSpeedY = 4;

var ballStartDir = false;

// Scores
var scoreLeft  = 0;
var scoreRight = 0;

// Random AI collision point
// Makes it so the ball isn't always colliding with the top of the paddle,
// forcing the ball in an upward direction
var aiPaddleRandCollisionPoint = 0;

/*****************************************************************************
 * DRAW GAME PIECE
 * @param {Integer} xPos   [piece x position]
 * @param {Integer} yPos   [piece y position]
 * @param {Integer} width  [piece width]
 * @param {Integer} height [piece height]
 * @param {String}  color  [piece color]
 ****************************************************************************/
function drawGamePiece(xPos, yPos, width, height, color) {
    CANVAS_CONTEXT.fillStyle = color;
    CANVAS_CONTEXT.fillRect(xPos,  // Game piece x position
                            yPos,  // Game piece y position
                            width, // Game piece width
                            height // Game piece height
    );
}

/*****************************************************************************
 * DRAW NET
 ****************************************************************************/
function drawNet() {
    let netWidth = 6;

    for (let i = CANVAS_HEIGHT; i >= 0; i -= 52) {
        drawGamePiece(((CANVAS_WIDTH / 2) - (netWidth / 2)), i, netWidth, 20, PIECE_COLOR);
    }
}

/*****************************************************************************
 * DRAW ALL THE THINGS
 * Canvas, paddles, ball, and net.
 ****************************************************************************/
function drawGame() {
    // Draw the canvas (game board)
    drawGamePiece(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT, BOARD_COLOR);
    // Draw the left paddle
    drawGamePiece(PADDLE_LEFT_X, paddleLeftY, PADDLE_WIDTH, PADDLE_HEIGHT, PIECE_COLOR);
    // Draw the right paddle
    drawGamePiece(PADDLE_RIGHT_X, paddleRightY, PADDLE_WIDTH, PADDLE_HEIGHT, PIECE_COLOR);
    // Draw the ball
    drawGamePiece(ballX, ballY, BALL_WIDTH, BALL_HEIGHT, PIECE_COLOR);
    // Draw the net
    drawNet();
    // Score
    CANVAS_CONTEXT.fillText(scoreLeft, (CANVAS_WIDTH / 2) + 75 , 50);
    CANVAS_CONTEXT.fillText(scoreRight, (CANVAS_WIDTH / 2) - 100, 50);
}

/*****************************************************************************
 * MOVE BALL
 * Move the ball and change its direction when it collides with a paddle.
 * Reset the ball position when it collides with the left/right side of the
 * canvas.
 ****************************************************************************/
function moveBall() {
    // Ball trajectory
    ballX += ballSpeedX;
    ballY += ballSpeedY;

    // When ball collides with left side
    if(ballX < 0) {
        ballStartDir = true;
        ballReset();
        scoreLeft++;
        // ignored in manual play
        aiPaddleRandCollisionPoint = Math.floor((Math.random() * 10) + 1);
    // When ball collides with left paddle
    } else if(ballX < (PADDLE_LEFT_X + PADDLE_WIDTH) &&
                ballY > paddleLeftY - BALL_HEIGHT &&
                    ballY < paddleLeftY + PADDLE_HEIGHT) {

        // Vertical ball direction based on where it hits the paddle
        let _deltaY = ballY - (paddleLeftY + (PADDLE_HEIGHT / 2));

        // Change horizontal direction
        ballSpeedX *= -1;
        // Change vertical ball speed
        ballSpeedY = _deltaY * 0.35;
        // Increase the ball's X speed with every collision
        ballSpeedX > 0 ? ballSpeedX += 1 : ballSpeedX -= 1;
        // Increase the ball's Y speed with every collision
        ballSpeedY > 0 ? ballSpeedY += 1 : ballSpeedY -= 1;
    }

    // When ball collides with right side
    if(ballX > (CANVAS_WIDTH - BALL_WIDTH)) {
        ballStartDir = false;
        ballReset();
        scoreRight++;
        // ignored in manual play
        aiPaddleRandCollisionPoint = Math.floor((Math.random() * 9) + 1);
    // When ball collides with right paddle
    } else if(ballX > (CANVAS_WIDTH - ((CANVAS_WIDTH - PADDLE_RIGHT_X) + BALL_WIDTH)) &&
                ballY > paddleRightY - BALL_HEIGHT &&
                    ballY < paddleRightY + PADDLE_HEIGHT) {

        // Vertical ball direction based on where it hits the paddle
        let _deltaY = ballY - (paddleRightY + (PADDLE_HEIGHT / 2));

        // Change horizontal direction
        ballSpeedX *= -1;
        // Change vertical ball speed
        ballSpeedY = _deltaY * 0.35;
        // Increase the ball's X speed with every collision
        ballSpeedX > 0 ? ballSpeedX += 1 : ballSpeedX -= 1;
        // Increase the ball's Y speed with every collision
        ballSpeedY > 0 ? ballSpeedY += 1 : ballSpeedY -= 1;
    }

    // Change vertical direction when ball collides with top/bottom
    if(ballY > (CANVAS_HEIGHT - BALL_HEIGHT) || ballY < 0) {
        ballSpeedY *= -1;
    }
}

/*****************************************************************************
 * MOVE PADDLE(S)
 * Move the paddle(s) based on the mouse position.
 ****************************************************************************/
function movePaddle() {
    // Listen for mouse event
    CANVAS.addEventListener('mousemove', event => {
        // Get the mouse's position
        let _mousePosition = calcMousePos(event);

        // Prevent paddle from leaving viewable canvas area,
        keepPaddleInView(_mousePosition.y, true);
    });
}

/*****************************************************************************
 * GET MOUSE POSITION
 * Get the X/Y positions of the mouse as it moves across the canvas. Account
 * for canvas position w/in the window.
 * @param  {User Input} event [Mouse movement]
 * @return {Object}           [Mouse X/Y positions]
 ****************************************************************************/
function calcMousePos(event) {
    // canvas bounding area (game board)
    let _gameBoard = CANVAS.getBoundingClientRect();
    // DOM or window
    let _document = document.documentElement;
    // Get mouse coordinates from window and compensate for canvas position.
    // I.e., mouse X/Y coordinates w/in the canvas.
    let _mouseX = event.clientX - _gameBoard.left - _document.scrollLeft;
    let _mouseY = event.clientY - _gameBoard.top;

    // return the mouse coordinates
    return {
        x : _mouseX,
        y : _mouseY
    }
}

/*****************************************************************************
  * KEEP PADDLE IN VIEW
  * Determine ball or mouse value and set the paddle's "Y" position to that
  * value.
  * @param  {Integer} control [Paddle position]
  * @param  {Boolean} isLeft  [Is paddle left or right]
 ****************************************************************************/
function keepPaddleInView(control, isLeft) {
    // Move paddle and keep it inside the viewable canvas area
    if(control >= (PADDLE_HEIGHT / 2) &&
            control <= (CANVAS_HEIGHT - (PADDLE_HEIGHT / 2))) {

        // If left side paddle
        isLeft ? paddleLeftY = control - (PADDLE_HEIGHT / 2) : 
            paddleRightY = control - (PADDLE_HEIGHT / 2);
    }
}

/*****************************************************************************
 * ARTIFICIAL INTELLIGENCE
 * Make the game paddles respond to the ball's "Y" position.
 ****************************************************************************/
function ai() {
    if(ballX >= (CANVAS_WIDTH / 2)) {
        paddleRightY = ballY - (PADDLE_HEIGHT * (aiPaddleRandCollisionPoint / 10));
    }
}

/*****************************************************************************
 * BALL RESET
 * Reposition the ball when it goes off screen
 ****************************************************************************/
function ballReset() {
    ballStartDir ? ballSpeedX = 10 : ballSpeedX = -10;
    ballSpeedY = 4;
    ballX = CANVAS_WIDTH / 2;
    ballY = CANVAS_HEIGHT / 2;
}

/*****************************************************************************
 * MAIN
 * Do all the things.
 ****************************************************************************/
(function init() {
    CANVAS_CONTEXT.font = '30px Consolas';

    // Frames per second
    const FPS = 30;

    // Move the ball every second
    setInterval(() => {
        drawGame();
        moveBall();
        ai();
    }, 1000 / FPS);

    // Move the paddle(s)
    movePaddle();

})();
