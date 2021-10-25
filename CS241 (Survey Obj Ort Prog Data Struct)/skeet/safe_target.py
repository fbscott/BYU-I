import arcade
import random
from flying_object import FlyingObject

class SafeTarget(FlyingObject):
    def __init__(self, radius, color, screen_height):
        super().__init__()
        self.radius = radius
        self.center.x = 0
        # The initial position of the target is anywhere along the top half of
        # the left side the screen
        self.center.y = float(random.uniform(screen_height / 2, screen_height))
        # The horizontal component of the velocity should be between 1 and 3
        # pixels/frame
        self.velocity.dx = float(random.uniform(1, 3))
        # The vertical component of the velocity should be between -2 and +3
        # pixels/frame
        self.velocity.dy = float(random.uniform(-2, 3))
        self.color = color
        self.lives = 3

    def draw(self):
        '''
        Override the default (parent) implementation of draw() so it will
        contain a number and be transparent with an outline.
        '''
        arcade.draw_rectangle_filled(self.center.x,
            self.center.y,
            self.radius,
            self.radius,
            self.color)

    def advance(self):
        super().advance()

    def is_off_screen(self, width, height):
        super().is_off_screen(width, height)

    def hit():
        return 1
