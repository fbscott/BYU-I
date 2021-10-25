import arcade
from point import Point
from velocity import Velocity

class FlyingObject:
    def __init__(self):
        self.center = Point()
        self.velocity = Velocity()
        self.radius = 0.0
        self.alive = True

    def draw(self, color):
        """draw the ball on the screen"""
        arcade.draw_circle_filled(self.center.x,
            self.center.y,
            self.radius,
            color)

    def advance(self):
        """move the ball"""
        self.center.x += self.velocity.dx
        self.center.y += self.velocity.dy

    def is_off_screen(self, width, height):
        self.screen_width = width
        self.screen_height = height
        if self.center.x > self.screen_width or self.center.y > self.screen_height or self.center.x < 0 or self.center.y < 0:
            return True
        else:
            return False
