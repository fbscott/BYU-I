import math
from flying_object import FlyingObject

class Bullet(FlyingObject):
    """Projectile. Fires from rifle. Destroys targets. Origin: (0,0)"""
    def __init__(self, radius, speed, color):
        """constructor"""
        super().__init__()
        # bullets start at (0,0) so there's no need to override the "center"
        # value as it's already set in the Point class by default
        self.radius = radius
        self.velocity.dy = speed
        self.velocity.dx = speed
        self.color = color

    def fire(self, angle):
        """Fire bullets"""
        self.velocity.dx = math.cos(math.radians(angle)) * self.velocity.dx
        self.velocity.dy = math.sin(math.radians(angle)) * self.velocity.dy
