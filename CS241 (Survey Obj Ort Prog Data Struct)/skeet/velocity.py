import random

class Velocity:
    """
    Velocity constructor
    Start the object with a random x/y velocity
    """
    def __init__(self, dx = 0, dy = 0):
        self.dx = float(dx)
        self.dy = float(dy)
