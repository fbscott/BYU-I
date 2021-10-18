import arcade
from point import Point

class Paddle:
    """Paddle constructor"""
    def __init__(self, width, height, screen_width, screen_height):
        # center the paddle on the right wall and give it a bit of space (10px)
        # so it's not too crowded
        self.center = Point(screen_width - 10, screen_height / 2)
        self.width = width
        self.height = height
        self.screen_width = screen_width
        self.screen_height = screen_height

    def draw(self):
        """draw the paddle on the screen"""
        arcade.draw_rectangle_filled(self.center.x,
            self.center.y,
            self.width,
            self.height,
            arcade.color.WHITE)

    def move_up(self):
        """move the paddle up but not beyond the top of the screen"""
        if self.center.y < (self.screen_height - (self.height / 2)):
            self.center.y += 5

    def move_down(self):
        """move the paddle down but not beyond the bottom of the screen"""
        if self.center.y > (self.height / 2):
            self.center.y -= 5
