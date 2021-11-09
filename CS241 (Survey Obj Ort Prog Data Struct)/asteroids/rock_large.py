import random
from flying_object import FlyingObject

class Rock_large(FlyingObject):
    """
    Large asteroid. Broken up by bullet.
    """
    def __init__(self, screen_height):
        """constructor"""
        super().__init__("meteorGrey_big1.png")
        # The initial position of the target is anywhere along the top half of
        # the left side the screen
        self.center.y = float(random.uniform(screen_height / 2, screen_height))
        # The horizontal component of the velocity should be between 1 and 5
        # pixels/frame
        self.velocity.dx = float(random.uniform(-1.5, 1.5))
        # The vertical component of the velocity should be between -2 and +5
        # pixels/frame
        self.velocity.dy = float(random.uniform(-1.5, 1.5))

    def hit(self):
        """Kills the object when a bullet hits it"""
        self.alive = False
        return int(1)
