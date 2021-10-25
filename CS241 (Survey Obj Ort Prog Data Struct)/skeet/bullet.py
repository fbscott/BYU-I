import arcade
import math
from flying_object import FlyingObject

class Bullet(FlyingObject):
    def __init__(self, radius, speed, color):
        super().__init__()
        self.radius = radius
        self.speed = speed
        self.velocity.dx = self.speed
        self.velocity.dy = self.speed
        self.color = color

    def draw(self):
        """draw the ball on the screen"""
        arcade.draw_circle_filled(self.center.x,
            self.center.y,
            self.radius,
            self.color)

    def advance(self):
        super().advance()

    def is_off_screen(self, width, height):
        super().is_off_screen(width, height)

    def fire(self, angle):
        self.velocity.dx = math.cos(math.radians(angle)) * self.speed
        self.velocity.dy = math.sin(math.radians(angle)) * self.speed
