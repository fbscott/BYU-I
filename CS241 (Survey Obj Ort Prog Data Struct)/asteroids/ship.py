import math
import os
import arcade
from flying_object import FlyingObject

absolutepath  = os.path.abspath(__file__)
rootDirectory = os.path.dirname(absolutepath)
imgPath       = os.path.join(rootDirectory, 'img')

class Ship(FlyingObject):
    """Flies around and destroys asteroids. Fires bullets."""
    def __init__(
        self,
        radius,
        screen_width,
        screen_height,
        thrust_amount,
        turn_amount
    ):
        super().__init__(
            "millennium_falcon.png",
            radius,
            screen_width,
            screen_height,
            turn_amount
        )
        self.center.x      = (screen_width / 2)
        self.center.y      = (screen_height / 2)
        self.rotation      = 0
        self.radius        = radius
        self.thrust_amount = thrust_amount
        self.turn_amount   = turn_amount

    def rotate_left(self):
        """rotate the ship left on key press"""
        self.rotation += self.turn_amount

    def rotate_right(self):
        """rotate the ship right on key press"""
        self.rotation -= self.turn_amount

    def forward(self):
        """move the ship forward on key press"""
        self.velocity.dx -= math.sin(math.radians(self.rotation)) * self.thrust_amount
        self.velocity.dy += math.cos(math.radians(self.rotation)) * self.thrust_amount

    def reverse(self):
        """move the ship backwards on key press"""
        self.velocity.dx += math.sin(math.radians(self.rotation)) * self.thrust_amount
        self.velocity.dy -= math.cos(math.radians(self.rotation)) * self.thrust_amount

    def replace_img(self):
        """update texture"""
        self.texture = arcade.load_texture(imgPath + "\\" + self.img)

    def img_on_key_press(self):
        """update image and texture on key press"""
        self.img = "millennium_falcon_alt.png"
        self.replace_img()

    def img_on_key_release(self):
        """update image and texture on key release"""
        self.img = "millennium_falcon.png"
        self.replace_img()
