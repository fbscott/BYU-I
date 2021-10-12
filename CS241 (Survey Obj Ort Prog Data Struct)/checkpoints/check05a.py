###############################################################################
# Assignment:
#   Checkpoint 05a
#   curtis mellor, cs241
###############################################################################

"""
File: check05a.py

To this file you need to add:

A Ship class with member variables: x, y, dx, dy
It should have two simple method: advance and draw

Then to the provided Game class, add calls to your draw
and advance.

You should not need to modify the main function.
"""

import random

class Ship():
    """
    Ship Constructor
    ship will fly around in a 2-D plain containing coordinate {x, y} and
    velocities {dx, dy}.
    """
    def __init__(self):
        """initialize all variables to '0'"""
        self.x  = 0
        self.y  = 0
        self.dx = 0
        self.dy = 0

    def advance(self):
        """
        Move the ship forward one unit in time.
        Adds 'dx' to 'x', and 'dy' to 'y'
        """
        self.x += self.dx
        self.y += self.dy

    def draw(self):
        """
        Outputs the following: 'Drawing the ship at (x, y)'
        Where x and y represent the current location of the ship.
        """
        print(f'Drawing ship at ({self.x}, {self.y})')

class Game:
    def __init__(self, dx, dy):
        self.ship = Ship()

        # Set the ship's initial velocity
        self.ship.dx = dx
        self.ship.dy = dy

    def on_draw(self):
        """Call the ship's draw() function"""
        self.ship.draw()


    def update(self):
        """Call the ship's advance() function"""
        self.ship.advance()

def main():
    """
    The main function sets up the game class and calls its
    methods repeatedly, just like will happen in actual games.
    
    You should not need to change anything here:
    """

    seed = input("Enter a random seed: ")
    random.seed(seed)

    dx = random.randint(-4, 4)
    dy = random.randint(-4, 4)

    print("Starting the ship with velocity ({}, {})".format(dx, dy))

    game = Game(dx, dy)

    for i in range(20):
        game.update()
        game.on_draw()

if __name__ == "__main__":
    main()
