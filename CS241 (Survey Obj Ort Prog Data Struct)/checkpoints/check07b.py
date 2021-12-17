###############################################################################
# Assignment:
#   Checkpoint 07b
#   curtis mellor, cs241
###############################################################################

"""
File: check07b.py
Author: Br. Burton

Demonstrates abstract base classes.
"""

#TODO: Import anything you need for Abstract Base Classes / methods
from abc import ABC
from abc import abstractmethod

#TODO: convert this to an ABC 
class Shape(ABC):
    def __init__(self):
        self.name = ""
    
    def display(self):
        print("{} - {:.2f}".format(self.name, self.get_area()))

    #TODO: Add an abstractmethod here called get_area
    @abstractmethod
    def get_area(self):
        pass


#TODO: Create a Circle class here that derives from Shape
class Circle(Shape):
    def __init__(self, radius = 0.0):
        super().__init__()
        self.name = "Circle"
        self.radius = radius

    def get_area(self):
        super().get_area()
        return 3.14 * self.radius * self.radius


#TODO: Create a Rectangle class here that derives from Shape
class Rectangle(Shape):
    def __init__(self, width = 0.0, length = 0.0):
        super().__init__()
        self.name = "Rectangle"
        self.width = width
        self.length = length

    def get_area(self):
        super().get_area()
        return self.length * self.width

def main():

    #TODO: Declare your list of shapes here
    shapes = []

    command = ""

    while command != "q":
        command = input("Please enter 'c' for circle, 'r' for rectangle or 'q' to quit: ")

        if command == "c":
            radius = float(input("Enter the radius: "))
            #TODO: Declare your Circle here, set its radius, and
            # add it to the list
            circle = Circle(radius)
            shapes.append(circle)
        
        elif command == "r":
            length = float(input("Enter the length: "))
            width = float(input("Enter the width: "))
            #TODO: Declare your Rectangle here, set its length
            # and width, and add it to the list
            rectangle = Rectangle(width, length)
            shapes.append(rectangle)

    # Done entering shapes, now lets print them all out:

    #TODO: Loop through each shape in the list, and call its display function
    for shape in shapes:
        shape.display()

if __name__ == "__main__":
    main()
