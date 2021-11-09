import random
from rock_base import Rock

class Rock_small(Rock):
    """
    Small rock. Killed by bullet.
    """
    def __init__(self, screen_height):
        """constructor"""
        super().__init__("meteorGrey_small1.png")
        self.center.x = 0
        self.center.y = 0
        self.velocity.dx = 0
        self.velocity.dy = 0
        self.rotation = 5.0

    def hit(self):
        pass
