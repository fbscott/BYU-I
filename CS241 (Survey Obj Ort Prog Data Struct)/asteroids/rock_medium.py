import random
from rock_base import Rock

class Rock_medium(Rock):
    """
    Medium rock. Broken up by bullet.
    """
    def __init__(self, screen_height):
        """constructor"""
        super().__init__("meteorGrey_med1.png")
        self.center.x = 0
        self.center.y = 0
        self.velocity.dx = 0
        self.velocity.dy = 0
        self.rotation = 2.0

    def hit(self):
        """Spawns smaller rocks when a bullet hits it"""
        self.spawnSmallRock()

    def spawnSmallRock():
        pass
