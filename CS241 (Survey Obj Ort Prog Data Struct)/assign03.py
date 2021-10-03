###############################################################################
# Assignment:
#   Assignment 03
#   curtis mellor, cs241
###############################################################################

'''ROBOT CONSTRUCTOR'''
class Robot:
    # initialize the robot at coordinates (10, 10) and with 100 units of fuel
    def __init__(self):
        self.x = 10
        self.y = 10
        self.fuel = 100

    '''
    MOVE ROBOT
    Move one unit in the specified direction: left, right, up, down.
    Each movement will decrease fuel reserves by 5.
    '''
    def move(self, direction):
        if self.fuel >= 5:
            if direction == 'left':
                self.x -= 1
            elif direction == 'right':
                self.x += 1
            elif direction == 'up':
                self.y -= 1
            elif direction == 'down':
                self.y += 1

            # decrease fuel on move
            self.fuel -= 5
        else:
            # when fuel reserves are depleted
            self.insufficient_fuel()

        return False

    '''
    FIRE LASER
    Each time the laser is fired, fuel reserves decrease by 15.
    '''
    def fire_laser(self):
        if self.fuel >= 15:
            print('Pew! Pew!')
            self.fuel -= 15
        else:
            self.insufficient_fuel()

        return False

    '''DISPLAY STATUS MESSAGE'''
    def display_status(self):
        print(f'({self.x}, {self.y}) - Fuel: {self.fuel}')

    '''INSUFFICIENT FUEL MESSAGE'''
    def insufficient_fuel(self):
        print('Insufficient fuel to perform action')

'''
Prompt the user for a command: left, right, up, down, fire, status, quit
'''
def prompt_for_command():
    return input('Enter command: ')

'''Initialize the program.'''
def main():
    # new instance of Robot
    robot = Robot()
    # user-provide command
    command = ''

    # continue prompting the uer until s/he enters "quit"
    while command != 'quit':
        command = prompt_for_command()

        if command == 'left' or command == 'right' or command == 'up' or command == 'down':
            robot.move(command)
        elif command == 'fire':
            robot.fire_laser()
        elif command == 'status':
            robot.display_status()

    # quit the game
    print('Goodbye.')

if __name__ == '__main__':
    main()
