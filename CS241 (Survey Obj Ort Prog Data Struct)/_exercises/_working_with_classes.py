class Person:
    def __init__(self, **options):
        self.f_name = options["f_name"]
        self.l_name = options["l_name"]
    
    def printName(self):
        print(f"\nHello! My name is {self.f_name}.")

class Student(Person):
    def __init__(self, **options):
        super().__init__(**options)
        self.graduation_year = options["graduation_year"]

    def printGradYear(self):
        print(f"I will graduate in {self.graduation_year}")

student = {
    "f_name": input("First name: "),
    "l_name": input("Last name: "),
    "graduation_year": input("What year will you graduate?: ")
}

def main():
    new_student = Student(f_name = student["f_name"], l_name = student["l_name"], graduation_year = student["graduation_year"])

    # print(f"Hello, {student.f_name} {student.l_name}")
    new_student.printName()
    new_student.printGradYear()

if __name__ == "__main__":
    main()
