class BalanceError(Exception):
    """Custom balance exception constructor"""
    def __init__(self, message):
        super().__init__(message)

class OutOfChecksError(Exception):
    """Custom out of checks exception constructor"""
    def __init__(self, message):
        super().__init__(message)

class CheckingAccount():
    def __init__(self, starting_balance, num_checks):

        if starting_balance < 0:
            raise BalanceError("Starting balance cannot be negative.")

        self.balance = float(starting_balance)
        self.check_count = int(num_checks)

    def deposit(self, amount):
        self.balance += float(amount)

    def write_check(self, amount):
        if self.balance - float(amount) < 0:
            raise BalanceError("Insufficient funds.")

        if self.check_count <= 0:
            raise OutOfChecksError("Out of checks.")

        self.balance -= amount
        self.check_count -= 1

    def display(self):
        print("\nBalance: ${:.2f}".format(self.balance))
        print(f"Number of checks: {self.check_count}")

    def apply_for_credit(self, amount):
        pass

def get_more_checks(account):
    more_checks = input("\nBuy checks (y/n)? ")
    if more_checks == "y":
        account.balance -= 5
        account.check_count += 25

def display_menu():
    """
    Displays the available commands.
    """
    print()
    print("Commands:")
    print("  quit - Quit")
    print("  new - Create new account")
    print("  display - Display account information")
    print("  deposit - Desposit money")
    print("  check - Write a check")

def main():
    """
    Used to test the CheckingAccount class.
    """
    acc = None
    command = ""

    while command != "quit":
        display_menu()
        command = input("Enter a command: ")

        if command == "new":
            try:
                balance = float(input("Starting balance: "))
                num_checks = int(input("Numbers of checks: "))
                acc = CheckingAccount(balance, num_checks)
            except BalanceError as ex:
                print(f"Error: {str(ex)}")
        elif command == "display":
            acc.display()
        elif command == "deposit":
            amount = float(input("Amount: "))
            acc.deposit(amount)
        elif command == "check":
            try:
                amount = float(input("Amount: "))
                acc.write_check(amount)
            except BalanceError as ex:
                print(f"Error: {str(ex)}")
            except OutOfChecksError as ex:
                print(f"Error: {str(ex)}")
                get_more_checks(acc)
        elif command == "credit":
            amount = float(input("Amount: "))
            acc.apply_for_credit(amount)

if __name__ == "__main__":
    main()
