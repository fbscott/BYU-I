import arcade
import random
from standard_target import StandardTarget

class SafeTarget(StandardTarget):
    """
    Safe Target. NOT meant to be destroyed. Incurs 10 pt penalty. Originates
    from the left side of the top half of the screen.
    """
    def __init__(self, radius, color, screen_height):
        """constructor"""
        super().__init__(radius, color, screen_height)
        # The horizontal component of the velocity should be between 1 and 3
        # pixels/frame
        self.velocity.dx = float(random.uniform(1, 3))
        # The vertical component of the velocity should be between -2 and +3
        # pixels/frame
        self.velocity.dy = float(random.uniform(-2, 3))

    def draw(self):
        '''
        Override the default (parent) implementation of draw() so it will
        contain a number and be transparent with an outline.
        '''
        # this object will be a square rather than a circle
        arcade.draw_rectangle_filled(
            self.center.x,
            self.center.y,
            self.radius,
            self.radius,
            self.color)

    def hit(self):
        """Kills the object when a bullet hits it"""
        self.alive = False
        return int(-10)
