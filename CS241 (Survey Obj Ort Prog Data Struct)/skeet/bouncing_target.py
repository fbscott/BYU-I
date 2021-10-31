import random
from standard_target import StandardTarget

class BouncingTarget(StandardTarget):
    """
    Bouncing Target. Bounces when struck by bullet. This target does NOT die.
    Scores one point for each hit. Originates from the left side of the top
    half of the screen.
    """
    def __init__(self, radius, color, screen_height):
        """constructor"""
        super().__init__(radius, color, screen_height)
        self.color = color

    def hit(self):
        """Changes the target's trajectory"""
        self.velocity.dx *= float(random.uniform(-5, 5))
        self.velocity.dy *= float(random.uniform(-5, 5))
        return int(1)
