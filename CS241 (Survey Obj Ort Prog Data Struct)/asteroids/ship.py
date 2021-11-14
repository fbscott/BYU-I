from flying_object import FlyingObject

class Ship(FlyingObject):

    def __init__(
        self,
        screen_width,
        screen_height,
        radius,
        thrust,
        turn_amount
    ):
        super().__init__("playerShip1_orange.png", screen_width, screen_height, radius)
        self.center.x = (screen_width / 2)
        self.center.y = (screen_height / 2)
        self.angle = 45
        self.radius = radius
        self.thrust = thrust
        self.turn_amount = turn_amount

    def rotate(self):
        self.angle += self.turn_amount

    def hit(self):
        pass
