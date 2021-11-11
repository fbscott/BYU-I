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
    # if string contains a minus sign, strip it off
    # then determine if it's a numeric value
    if n.lstrip('-').isnumeric():
        num = int(n)
    else:
        num = n

    # Check for the following rules and raise an appropriate exception. Do not
    # display any error messages in this function, simply raise the exception.
    if isinstance(num, str):
        raise ValueError("The value must be a number")
    elif num == 0:
        raise ZeroDivisionError("Cannot divide by zero")
    elif num < 0:
        raise NegativeNumberError("The value cannot be negative")

    return 1 / num

def main():
    number = input("Enter a number: ")

    # Catch each exception and display the following error messages.
    try:
        inverse = get_inverse(number)
        print(f"The result is: {inverse}")
    except ValueError as e:
        print(f"Error: {e}")
    except ZeroDivisionError as e:
        print(f"Error: {e}")
    except NegativeNumberError as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
