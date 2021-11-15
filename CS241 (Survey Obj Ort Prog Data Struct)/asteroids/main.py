"""
File: asteroids.py
Original Author: Br. Burton
Designed to be completed by others

This program implements the asteroids game.
"""
import arcade
import os
from rock_large import Rock_large
# from rock_medium import Rock_medium
# from rock_small import Rock_small
from ship import Ship
# from bullet import Bullet

# These are Global constants to use throughout the game
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600

BULLET_RADIUS = 30
BULLET_SPEED = 10
BULLET_LIFE = 60

SHIP_TURN_AMOUNT = 3
SHIP_THRUST_AMOUNT = 0.25
SHIP_RADIUS = 30

INITIAL_ROCK_COUNT = 5

BIG_ROCK_SPIN = 1
BIG_ROCK_SPEED = 1.5
BIG_ROCK_RADIUS = 15

MEDIUM_ROCK_SPIN = -2
MEDIUM_ROCK_RADIUS = 5

SMALL_ROCK_SPIN = 5
SMALL_ROCK_RADIUS = 2




class Game(arcade.Window):
    """
    This class handles all the game callbacks and interaction

    This class will then call the appropriate functions of
    each of the above classes.

    You are welcome to modify anything in this class.
    """

    def __init__(self, width, height):
        """
        Sets up the initial conditions of the game
        :param width: Screen width
        :param height: Screen height
        """
        super().__init__(width, height)
        # arcade.set_background_color(arcade.color.SMOKY_BLACK)

        self.held_keys = set()

        # TODO: declare anything here you need the game class to track
        self.background = None
        
        self.asteroids = []

        self.ship = Ship(
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SHIP_RADIUS,
            SHIP_THRUST_AMOUNT,
            SHIP_TURN_AMOUNT
        )

        for i in range(INITIAL_ROCK_COUNT):
            rock_large = Rock_large(
                SCREEN_WIDTH,
                SCREEN_HEIGHT,
                BIG_ROCK_RADIUS
            )
            self.asteroids.append(rock_large)

    def setupBgImage(self):
        """
        Add background image to game.
        source: https://api.arcade.academy/en/latest/examples/sprite_collect_coins_background.html
        """
        absolutepath = os.path.abspath(__file__)
        rootDirectory = os.path.dirname(absolutepath)
        bgImgPath = os.path.join(rootDirectory, 'img')
        self.background = arcade.load_texture(bgImgPath + "\\space.png")

    def on_draw(self):
        """
        Called automatically by the arcade framework.
        Handles the responsibility of drawing all elements.
        """

        # clear the screen to begin drawing
        arcade.start_render()

        # TODO: draw each object
        # Draw the background texture
        arcade.draw_lrwh_rectangle_textured(
            0,
            0,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            self.background
        )

        self.ship.draw()

        for asteroid in self.asteroids:
            asteroid.draw()

    def update(self, delta_time):
        """
        Update each object in the game.
        :param delta_time: tells us how much time has actually elapsed
        """
        self.check_keys()

        # TODO: Tell everything to advance or move forward one step in time
        self.ship.advance()
        self.ship.wrap()

        for asteroid in self.asteroids:
            asteroid.advance()
            asteroid.wrap()

        # TODO: Check for collisions

    def check_keys(self):
        """
        This function checks for keys that are being held down.
        You will need to put your own method calls in here.
        """
        if arcade.key.LEFT in self.held_keys:
            self.ship.rotate_left()

        if arcade.key.RIGHT in self.held_keys:
            self.ship.rotate_right()

        if arcade.key.UP in self.held_keys:
            self.ship.forward()

        if arcade.key.DOWN in self.held_keys:
            self.ship.reverse()

        # Machine gun mode...
        #if arcade.key.SPACE in self.held_keys:
        #    pass


    def on_key_press(self, key: int, modifiers: int):
        """
        Puts the current key in the set of keys that are being held.
        You will need to add things here to handle firing the bullet.
        """
        if self.ship.alive:
            self.held_keys.add(key)

            if key == arcade.key.SPACE:
                # TODO: Fire the bullet here!
                pass

    def on_key_release(self, key: int, modifiers: int):
        """
        Removes the current key from the set of held keys.
        """
        if key in self.held_keys:
            self.held_keys.remove(key)


# Creates the game and starts it going
window = Game(SCREEN_WIDTH, SCREEN_HEIGHT)
window.setupBgImage()
arcade.run()