import random
from rock_base import Rock
from rock_small import Rock_small

class Rock_medium(Rock):
    """Medium rock. Broken up by bullet."""
    def __init__(
        self,
        radius,
        screen_width,
        screen_height,
        rotation,
        center_x,
        center_y,
        velocity_dx,
        velocity_dy,
        img
    ):
        super().__init__(
            img,
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
        asteroids,
        radius,
        rotation
    ):
        """Breaks rock into smaller rocks when a bullet hits it"""
        rock_small_1 = Rock_small(
            radius,
            self.screen_width,
            self.screen_height,
            rotation,
            self.center.x,
            self.center.y,
            self.velocity.dx + 1.5,
            self.velocity.dy + 1.5
        )
        rock_small_2 = Rock_small(
            radius,
            self.screen_width,
            self.screen_height,
            rotation,
            self.center.x,
            self.center.y,
            self.velocity.dx - 1.5,
            self.velocity.dy - 1.5
        )
        self.alive = False
        asteroids.extend([rock_small_1, rock_small_2])

