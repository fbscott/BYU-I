from collections import deque

class Student:
    def __init__(self):
        self.name = ''
        self.course = ''

    def prompt(self):
        self.name = input('Enter name: ')
        self.course = input('Enter course: ')

    def display(self):
        print(f'Now helping {self.name} with {self.course}')

class HelpSystem():
    def __init__(self):
        self.waiting_list = deque()

    def is_student_waiting(self):
        return True if len(self.waiting_list) > 0 else False

    def add_to_waiting_list(self, student):
        self.waiting_list.append(student)

    def help_next_student(self):
        if self.is_student_waiting():
            current_student = self.waiting_list.popleft()
            current_student.display()
        else:
            print('No one to help.')

def main():
    help_system = HelpSystem()

    option = 0

    while option != 3:
        print('Options:\n1. Add a new student\n2. Help next student\n3. Quit')

        option = int(input('Enter Selection: '))

        print()

        if option == 1:
            student = Student()
            student.prompt()
            print()
            help_system.add_to_waiting_list(student)
        elif option == 2:
            help_system.help_next_student()
            print()

    print('Goodbye')

if __name__ == '__main__':
    main()
