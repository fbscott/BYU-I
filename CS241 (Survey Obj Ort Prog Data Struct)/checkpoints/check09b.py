###############################################################################
# Assignment:
#   Checkpoint 09b
#   curtis mellor, cs241
###############################################################################

class NegativeNumberError(Exception):
    """Custom error type constructor"""
    def __init__(self, message):
        super().__init__(message)

def get_inverse(n):
    n = int(n)

    """
    Check for the following rules and raise an appropriate exception.
    Do not display any error messages in this function, simply raise the exception.
    """
    if isinstance(n, str):
        raise ValueError(n)
    elif n == 0:
        raise ZeroDivisionError(n)
    elif n < 0:
        raise NegativeNumberError(n)

    return 1 / n

def main():
    number = input("Enter a number: ")

    """Catch each exception and display the following error messages."""
    try:
        inverse = get_inverse(number)
        print(f"The result is: {inverse}")
    except ValueError:
        print("Error: The value must be a number")
    except ZeroDivisionError:
        print("Error: Cannot divide by zero")
    except NegativeNumberError:
        print("Error: The value cannot be negative")

if __name__ == "__main__":
    main()
