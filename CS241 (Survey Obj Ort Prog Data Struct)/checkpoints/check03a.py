class Student:
    """ Student constructor """

    def __init__(self):
        self.f_name = ""
        self.l_name = ""
        self.id = 0

def prompt_student():
    """ Prompt the student for his/her information """

    student = Student()

    student.f_name = input("Please enter your first name: ")
    student.l_name = input("Please enter your last name: ")
    student.id     = input("Please enter your id number: ")

    return student

def display_student(user):
    """ Display student information """

    print(f"\nYour information:\n{user.id} - {user.f_name} {user.l_name}")

def main():
    """ Main function """

    user = prompt_student()

    display_student(user)

if __name__ == "__main__":
    main()
