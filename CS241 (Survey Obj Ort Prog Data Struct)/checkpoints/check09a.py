###############################################################################
# Assignment:
#   Checkpoint 09a
#   curtis mellor, cs241
###############################################################################

def prompt_for_int():
    is_number = False

    while not is_number:
        try:
            n = int(input("Enter a number: "))
            print(f"The result is: {n * 2}")
            is_number = True
        except ValueError:
            print("The value entered is not valid")

def main():
    prompt_for_int()

if __name__ == "__main__":
    main()
