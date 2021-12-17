import random

class Velocity:
    """
    Velocity constructor
    Start the ball with a random x/y velocity
    """
    def __init__(self):
        self.dx = float(random.uniform(1, 8))
        self.dy = float(random.uniform(-5, 5))
