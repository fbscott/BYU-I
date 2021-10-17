import arcade
import random
from point import Point
from velocity import Velocity

class Ball:
    def __init__(self, radius, screen_width, screen_height):
        # center the ball at a random position on the left wall
        self.center = Point(radius, random.uniform(radius, screen_height - radius))
        self.velocity = Velocity()
        self.radius = radius
        self.screen_width = screen_width
        self.screen_height = screen_height

    def draw(self):
        arcade.draw_circle_filled(self.center.x,
                                  self.center.y,
                                  self.radius,
                                  arcade.color.WHITE)

    def advance(self):
        self.center.x += self.velocity.dx
        self.center.y += self.velocity.dy

    def bounce_horizontal(self):
        if self.center.x <= 0:
            self.velocity.dx *= -1

    def bounce_vertical(self):
        if self.center.y >= self.screen_height or self.center.y <= 0:
            self.velocity.dy *= -1

    def restart(self):
        pass
