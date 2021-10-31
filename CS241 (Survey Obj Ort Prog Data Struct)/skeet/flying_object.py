import arcade
from point import Point
from velocity import Velocity

class FlyingObject:
    """
    Base (parent) class for all objects (other than the rifle) that move on the
    screen.
    """
    def __init__(self):
        """constructor"""
        self.center = Point()
        self.velocity = Velocity()
        self.radius = 0.0
        self.color = ''
        self.alive = True

    def draw(self):
        """
        Draw the object (bullet, target, etc.) on the screen. Assumes the
        object is a circle. Can be overridden in the child class.
        """
        arcade.draw_circle_filled(
            self.center.x,
            self.center.y,
            self.radius,
            self.color)

    def advance(self):
        """Moves the object. Adds velocity (dx,dy) to its (x,y) coordinates."""
        self.center.x += self.velocity.dx
        self.center.y += self.velocity.dy

    def is_off_screen(self, screen_width, screen_height):
        """Determines if the object is outside the viewable screen area."""
        if self.center.x > screen_width or self.center.y > screen_height or self.center.x < 0 or self.center.y < 0:
            return True
        else:
            return False
