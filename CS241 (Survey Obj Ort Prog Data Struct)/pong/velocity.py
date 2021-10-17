import random

class Velocity:
    def __init__(self):
        self.dx = float(random.uniform(1, 5))
        self.dy = float(random.uniform(-5, 5))
