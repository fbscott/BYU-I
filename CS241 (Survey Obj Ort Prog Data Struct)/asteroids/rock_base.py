from abc import ABC
from abc import abstractmethod
import random
from flying_object import FlyingObject

class Rock(ABC, FlyingObject):
    def __init__(
        self,
        img,
        radius,
        screen_width,
        screen_height
    ):
        super().__init__(
            img,
            radius,
            screen_width,
            screen_height
        )
        self.random = float(random.uniform(-1, 1))

    @abstractmethod
    def rotate():
        pass

    @abstractmethod
    def hit():
        pass
