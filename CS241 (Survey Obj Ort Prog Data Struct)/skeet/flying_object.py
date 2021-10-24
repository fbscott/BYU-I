import arcade
import random
from point import Point
from velocity import Velocity

class FlyingObject:
    def __init__(self, radius, screen_height):
        self.center = Point(radius,
            random.uniform(radius,
            screen_height - radius))
        self.velocity = Velocity()
        self.radius = radius

    def draw(self):
        """draw the ball on the screen"""
        arcade.draw_circle_filled(self.center.x,
            self.center.y,
            self.radius,
            arcade.color.GRAPE)

    def advance(self):
        """move the ball"""
        self.center.x += self.velocity.dx
        self.center.y += self.velocity.dy

    def is_off_screen(self, screen_width, screen_height):
        return False
