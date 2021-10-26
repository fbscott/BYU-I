import arcade
import random
from standard_target import StandardTarget

class StrongTarget(StandardTarget):
    """
    Strong Target. Destroyed by bullet. Originates from the left side of the
    top half of the screen. Takes 3 hits to destory.
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
        self.lives = int(3)

    def draw(self):
        '''
        Override the default (parent) implementation of draw() so it will
        contain a number and be transparent with an outline.
        '''
        # this object will be an empty circle
        arcade.draw_circle_outline(self.center.x,
            self.center.y,
            self.radius,
            self.color)

        # position the text for this object
        text_x = self.center.x - (self.radius / 2)
        text_y = self.center.y - (self.radius / 2)

        # draw text in the object
        arcade.draw_text(repr(self.lives),
            text_x,
            text_y,
            self.color,
            font_size = 20)

    def hit(self):
        """Kills the object when a bullet hits it"""
        # score one poinit while the object is alive
        while self.lives > 1:
            self.lives -= 1
            return int(1)

        # score five points when the object is dead
        self.alive = False
        return int(5)
