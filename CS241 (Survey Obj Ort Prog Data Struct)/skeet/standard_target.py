import random
from flying_object import FlyingObject

class StandardTarget(FlyingObject):
    def __init__(self, radius, color, screen_height):
        """constructor"""
        super().__init__()
        self.radius = radius
        self.center.x = 0
        # The initial position of the target is anywhere along the top half of
        # the left side the screen
        self.center.y = float(random.uniform(screen_height / 2, screen_height))
        # The horizontal component of the velocity should be between 1 and 5
        # pixels/frame
        self.velocity.dx = float(random.uniform(1, 5))
        # The vertical component of the velocity should be between -2 and +5
        # pixels/frame
        self.velocity.dy = float(random.uniform(-2, 5))
        self.color = color

    def draw(self):
        super().draw()

    def advance(self):
        super().advance()

    def is_off_screen(self, width, height):
        super().is_off_screen(width, height)

    def hit(self):
        self.alive = False
        return int(1)
