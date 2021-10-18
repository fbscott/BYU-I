import arcade
import random
from point import Point
from velocity import Velocity

class Ball:
    """Ball constructor"""
    def __init__(self, radius, screen_height):
        # center the ball at a random position on the left wall
        self.center = Point(radius,
            random.uniform(radius,
            screen_height - radius))
        self.velocity = Velocity()
        self.radius = radius
        self.screen_height = screen_height

    def draw(self):
        """draw the ball on the screen"""
        arcade.draw_circle_filled(self.center.x,
            self.center.y,
            self.radius,
            arcade.color.WHITE)

    def advance(self):
        """move the ball"""
        self.center.x += self.velocity.dx
        self.center.y += self.velocity.dy

    def bounce_horizontal(self):
        """change ball x-direction on collision with wall"""
        self.velocity.dx *= -1

    def bounce_vertical(self):
        """change ball y-direction on collision with wall"""
        self.velocity.dy *= -1

    def restart(self):
        """
        reposition the ball on the left wall with a random height and velocity
        (usually occurs on score in main.py)
        """
        self.center.x = 0
        self.center.y = random.uniform(self.radius, self.screen_height - self.radius)
        self.velocity = Velocity()
