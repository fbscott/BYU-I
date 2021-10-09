###############################################################################
# Assignment:
#   Checkpoint 04a
#   curtis mellor, cs241
###############################################################################

class Person:

    def __init__(self):
        self.name = 'anonymous'
        self.birth_year = 'unknown'

    def display(self):
        print (f'{self.name} (b. {self.birth_year})')

class Book:

    def __init__(self):
        self.title = 'untitled'
        self.author = Person()
        self.publisher = 'unpublished'

    def display(self):
        print(self.title)
        print('Publisher:')
        print(self.publisher)
        print('Author:')
        self.author.display()

def main():
    book = Book()

    book.display()

    print('\nPlease enter the following:')

    book.author.name = input('Name: ')
    book.author.birth_year = input('Year: ')
    book.title = input('Title: ')
    book.publisher = input('Publisher: ')

    print()

    book.display()

if __name__ == '__main__':
    main()
