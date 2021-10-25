import random

class Velocity:
    """
    Velocity constructor
    Start the object with a random x/y velocity
    """
    def __init__(self):
        self.dx = float(random.uniform(1, 5))
        self.dy = float(random.uniform(-5, 5))
