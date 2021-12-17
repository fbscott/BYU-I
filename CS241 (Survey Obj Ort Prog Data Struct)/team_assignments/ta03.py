class RationalNumber():
    def __init__(self):
        self.numerator = 0
        self.denominator = 1

    def display(self):
        print(f"{self.numerator}/{self.denominator}")

    def prompt(self):
        self.numerator = input("Enter the numerator: ")
        self.denominator = input("Enter the denominator: ")

    def display_decimal(self):
        decimal = float(self.numerator) / float(self.denominator)
        
        print(decimal)

def main():
    rationalNumber = RationalNumber()

    rationalNumber.display()

    rationalNumber.prompt()

    rationalNumber.display()

    rationalNumber.display_decimal()

if __name__ == "__main__":
    main()
