import random
from rock_base import Rock

class Rock_large(Rock):
    """
    Large rock. Broken up by bullet.
    """
    def __init__(
        self,
        radius,
        screen_width,
        screen_height,
        rotation
    ):
        """constructor"""
        super().__init__(
            # "meteorGrey_big1.png",
            "asteroid_large.png",
            radius,
            screen_width,
            screen_height
        )
        self.center.x    = float(random.uniform(0, screen_width))
        self.center.y    = float(random.uniform(0, screen_height))
        self.velocity.dx = float(random.uniform(-1.5, 1.5))
        self.velocity.dy = float(random.uniform(-1.5, 1.5))
        self.radius      = radius
        self.rotation    = rotation

    def rotate(self):
        super().advance()
        self.rotation += self.random

    def hit(self):
        """Spawns smaller rocks when a bullet hits it"""
        self.spawnMediumRock()
        self.spawnSmallRock()

    def spawnMediumRock():
        pass

    def spawnSmallRock():
        pass
