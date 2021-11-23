import random
from rock_base import Rock
from rock_medium import Rock_medium
from rock_small import Rock_small

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

    def hit(
        self,
        asteroids,
        radius,
        rotation
    ):
        rock_medium_1 = Rock_medium(
            radius,
            self.screen_width,
            self.screen_height,
            rotation,
            self.center.x,
            self.center.y,
            self.velocity.dx,
            self.velocity.dy + 2,
            "asteroid_med_1.png"
        )
        rock_medium_2 = Rock_medium(
            radius,
            self.screen_width,
            self.screen_height,
            rotation,
            self.center.x,
            self.center.y,
            self.velocity.dx,
            self.velocity.dy - 2,
            "asteroid_med_2.png"
        )
        rock_small = Rock_small(
            radius,
            self.screen_width,
            self.screen_height,
            rotation,
            self.center.x,
            self.center.y,
            self.velocity.dx + 5,
            self.velocity.dy
        )
        self.alive = False
        asteroids.extend([rock_medium_1, rock_medium_2, rock_small])
