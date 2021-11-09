from abc import ABC
from abc import abstractmethod
from flying_object import FlyingObject

class Rock(ABC, FlyingObject):
    def __init__(self, img):
        self.rotation = float(0.0)
        self.image = img

    @abstractmethod
    def hit():
        pass
