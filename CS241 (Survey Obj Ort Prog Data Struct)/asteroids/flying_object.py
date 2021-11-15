import os
import arcade
from point import Point
from velocity import Velocity

"""
I'm using VSCode instead of Thonny as my text editor. I had to do some special
configuration to get the arcade module to work in VSCode. Part of that
configuration was to setup a virtual environment to get the arcade game engine
to run. The virtual environment utilizes absolute pathing. The following three
lines cache that absolute path so 1) it doesn't have to be hardcoded, and 2)
this code will "hopefully" run on any machine as the paths will be different.
"""
absolutepath  = os.path.abspath(__file__)
rootDirectory = os.path.dirname(absolutepath)
imgPath       = os.path.join(rootDirectory, 'img')   

class FlyingObject:
    """
    Base (parent) class for all objects (other than the rifle) that move on the
    screen.
    """
    def __init__(
        self,
        img,
        screen_width = 0,
        screen_height = 0,
        radius = 0,
        rotation = 0
    ):
        """constructor"""
        self.center        = Point()
        self.velocity      = Velocity()
        self.texture       = arcade.load_texture(imgPath + "\\" + img)
        self.screen_width  = screen_width
        self.screen_height = screen_height
        self.width         = self.texture.width
        self.height        = self.texture.height
        self.radius        = radius
        self.rotation      = rotation
        self.alive         = True

    def draw(self):
        """
        Draw the object (bullet, target, etc.) on the screen. Assumes the
        object is a circle. Can be overridden in the child class.
        """
        arcade.draw_texture_rectangle(
            self.center.x,
            self.center.y,
            self.width,
            self.height,
            self.texture,
            self.rotation,
            255
        )

    def advance(self):
        """Moves the object. Adds velocity (dx,dy) to its (x,y) coordinates."""
        self.center.x += self.velocity.dx
        self.center.y += self.velocity.dy

    def wrap(self):
        if self.center.x > self.screen_width:
            self.center.x -= self.screen_width

        if self.center.y > self.screen_height:
            self.center.y -= self.screen_height

        if self.center.x < 0:
            self.center.x += self.screen_width

        if self.center.y < 0:
            self.center.y += self.screen_height
