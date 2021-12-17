from abc import ABC
from abc import abstractmethod
import random
from flying_object import FlyingObject

class Rock(ABC, FlyingObject):
    """Base class. Inherited by large, medium, and small rock classes."""
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
    def rotate(self):
        pass

    @abstractmethod
    def hit(self, obj):
        super().hit(obj)
