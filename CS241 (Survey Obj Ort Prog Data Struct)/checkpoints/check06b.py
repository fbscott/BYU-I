###############################################################################
# Assignment:
#   Checkpoint 06b
#   curtis mellor, cs241
###############################################################################

class Phone():
    """Parent Class"""
    def __init__(self):
        self.area_code = 0
        self.prefix = 0
        self.suffix = 0

    def prompt_number(self):
        self.area_code = int(input("Area Code: "))
        self.prefix = int(input("Prefix: "))
        self.suffix = int(input("Suffix: "))

    def display(self):
        print("\nPhone info:")
        print(f"({self.area_code}){self.prefix}-{self.suffix}")

class SmartPhone(Phone):
    """Child Class"""
    def __init__(self):
        super().__init__()
        self.email = ""

    def prompt(self):
        self.prompt_number()
        self.email = input("Email: ")

    def display(self):
        super().display()
        print(f"{self.email}")

def main():
    print("Phone:")
    phone = Phone()
    phone.prompt_number()
    phone.display()

    print("\nSmart phone:")
    smart_phone = SmartPhone()
    smart_phone.prompt()
    smart_phone.display()

if __name__ == "__main__":
    main()
