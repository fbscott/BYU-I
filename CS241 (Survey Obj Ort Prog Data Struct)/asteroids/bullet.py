import math

from arcade.key import X
from flying_object import FlyingObject

class Bullet(FlyingObject):

    def __init__(
        self,
        radius,
        screen_width,
        screen_height,
        ship_x,
        ship_y,
        ship_dx,
        ship_dy,
        ship_rotation,
        speed,
        life
    ):
        super().__init__(
            # "laserBlue01.png",
            "millennium_falcon_laser.png",
            radius,
            screen_width,
            screen_height,
            ship_rotation
        )
        self.center.x = ship_x
        self.center.y = ship_y
        self.velocity.dx = ship_dx
        self.velocity.dy = ship_dy
        self.rotation = ship_rotation
        self.speed = speed
        self.life = life

    def is_alive(self):
        if self.alive == True and self.life > 0:
            self.life -= 1
        else:
            self.alive = False

    def fire(self):
        self.velocity.dx = (math.cos(math.radians(self.rotation + 90)) * self.speed) + self.velocity.dx
        self.velocity.dy = (math.sin(math.radians(self.rotation + 90)) * self.speed) + self.velocity.dy
