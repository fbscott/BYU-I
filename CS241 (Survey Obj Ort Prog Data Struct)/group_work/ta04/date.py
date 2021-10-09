class Date:
    def __init__(self):
        self.day = 1
        self.month = 1
        self.year = 2000

    def prompt(self):
        self.day = input('Day: ')
        self.month = input('Month: ')
        self.year = input('Year: ')

    def display(self):
        print(f'{self.month}/{self.day}/{self.year}')
