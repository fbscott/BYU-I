import random
from rock_base import Rock

class Rock_medium(Rock):
    """
    Medium rock. Broken up by bullet.
    """
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
        """constructor"""
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
        super().advance()
        self.rotation += self.random

    def hit(self, obj):
        """Spawns smaller rocks when a bullet hits it"""
        print('big rock hit')
        self.spawnSmallRock()

    def spawnSmallRock(self):
        pass
