from flying_object import FlyingObject

class Target(FlyingObject):
    def __init__(self):
        super().__init__()
        self.alive = True

    def draw(self):
        super().draw()

    def advance(self):
        super().advance()

    def is_off_screen(self):
        super().is_off_screen()

    def hit():
        return 1
