from abc import ABC
from abc import abstractmethod
from flying_object import FlyingObject

class Rock(ABC, FlyingObject):
    def __init__(
        self,
        img,
        screen_width,
        screen_height,
        radius
    ):
        super().__init__(
            img,
            screen_width,
            screen_height,
            radius
        )
        self.rotation = float(0.0)

    @abstractmethod
    def hit():
        pass
