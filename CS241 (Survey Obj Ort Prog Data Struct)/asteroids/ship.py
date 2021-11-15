import math
from flying_object import FlyingObject

class Ship(FlyingObject):

    def __init__(
        self,
        screen_width,
        screen_height,
        radius,
        thrust_amount,
        turn_amount
    ):
        super().__init__(
            "playerShip1_orange.png",
            screen_width,
            screen_height,
            radius,
            turn_amount
        )
        self.center.x      = (screen_width / 2)
        self.center.y      = (screen_height / 2)
        self.rotation      = 0
        self.radius        = radius
        self.thrust_amount = thrust_amount
        self.turn_amount   = turn_amount

    def rotate_left(self):
        self.rotation += self.turn_amount

    def rotate_right(self):
        self.rotation -= self.turn_amount

    def forward(self):
        self.velocity.dx -= math.sin(math.radians(self.rotation)) * self.thrust_amount
        self.velocity.dy += math.cos(math.radians(self.rotation)) * self.thrust_amount

    def reverse(self):
        self.velocity.dx += math.sin(math.radians(self.rotation)) * self.thrust_amount
        self.velocity.dy -= math.cos(math.radians(self.rotation)) * self.thrust_amount

    def hit(self):
        pass
