class Complex:
    """ Complex constructor """

    def __init__(self):
        self.real = 0
        self.imaginary = 0

    def prompt(self):
        """ Prompt the user for complex values """

        self.real = input("Please enter the real part: ")
        self.imaginary = input("Please enter the imaginary part: ")

    def display(self):
        """ Display user-provided values """

        print(f"{self.real} + {self.imaginary}i")

def main():
    """
    This function tests your Complex class. It should have a prompt
    and a display member function to be called.

    You should not need to change this main function at all.
    """
    c1 = Complex()
    c2 = Complex()

    print("The values are:")
    c1.display()
    c2.display()

    print()
    c1.prompt()

    print()
    c2.prompt()

    print("\nThe values are:")
    c1.display()
    c2.display()

# If this is the main program being run, call our main function above
if __name__ == "__main__":
    main()
