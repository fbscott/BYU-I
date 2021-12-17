def prompt_for_int():
    valid_input = False

    while not valid_input:
        try:
            n = int(input("Please enter an integer: "))
            valid_input = True
        except ValueError:
            print("Not a valid integer, please try again.")

    print("Successfully entered an integer.")

def main():
    prompt_for_int()

if __name__ == "__main__":
    main()
