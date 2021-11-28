import random
from rock_base import Rock

class Rock_small(Rock):
    """Small rock. Destroyed by bullet."""
    def __init__(
        self,
        radius,
        screen_width,
        screen_height,
        rotation,
        center_x,
        center_y,
        velocity_dx,
        velocity_dy
    ):
        super().__init__(
            "asteroid_small.png",
            radius,
            screen_width,
            screen_height
        )
        self.center.x    = float(center_x)
        self.center.y    = float(center_y)
        self.velocity.dx = float(random.uniform(velocity_dx * -1, velocity_dx))
        self.velocity.dy = float(random.uniform(velocity_dy * -1, velocity_dy))
        self.radius      = radius
        self.rotation    = rotation

    def rotate(self):
        """rotate rock"""
        super().advance()
        self.rotation += self.random

    def hit(
        self,
        asteroids = None,
        radius = None,
        rotation = None
    ):
        """Destroys rock when a bullet hits it"""
        self.alive = False
