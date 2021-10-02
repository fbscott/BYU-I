class Robot:
    """ Robot constructor """

    def __init__(self):
        self.x = 10
        self.y = 10
        self.fuel = 100

    def move(self, direction):
        """ Move robot """

        if self.fuel >= 5:
            if direction == "left":
                self.x -= 1
            elif direction == "right":
                self.x += 1
            elif direction == "up":
                self.y -= 1
            elif direction == "down":
                self.y += 1

            self.fuel -= 5
        else:
            self.insufficient_fuel()

        return False

    def fire(self):
        """ Fire weapon """

        if self.fuel >= 15:
            print("Pew! Pew!")

            self.fuel -= 15
        else:
            self.insufficient_fuel()

        return False

    def display_status(self):
        """ Display status message """

        print(f"({self.x}, {self.y}) - Fuel: {self.fuel}")

    def insufficient_fuel(self):
        """ Insufficient fuel message """

        print("Insufficient fuel to perform action")

def main():
    """ Do all the things """

    # new instance of Robot
    robot = Robot()

    # game will contine while this value is "True"
    can_replay = True

    while can_replay:
        # did not include this input "prompt" in the Robot class because it's
        # specific to the game, not the Robot
        command = input("Enter command: ")

        if command == "left" or command == "right" or command == "up" or command == "down":
            robot.move(command)
        elif command == "fire":
            robot.fire()
        elif command == "status":
            robot.display_status()
        # did not include the "quit" command in the Robot class because it's
        # specific to the game, not the Robot
        elif command == "quit":
            print('Goodbye.')
            # end game
            can_replay = False

if __name__ == "__main__":
    main()
