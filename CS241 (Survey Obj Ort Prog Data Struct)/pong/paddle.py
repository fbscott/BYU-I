import arcade
from point import Point

class Paddle:
    def __init__(self, width, height, screen_width, screen_height):
        self.center = Point(screen_width - 10, screen_height / 2)
        self.width = width
        self.height = height
        self.screen_width = screen_width
        self.screen_height = screen_height

    def draw(self):
        arcade.draw_rectangle_filled(self.center.x,
                                     self.center.y,
                                     self.width,
                                     self.height,
                                     arcade.color.WHITE)

    def move_up(self):
        if self.center.y < (self.screen_height - (self.height / 2)):
            self.center.y += 5

    def move_down(self):
        if self.center.y > (self.height / 2):
            self.center.y -= 5
