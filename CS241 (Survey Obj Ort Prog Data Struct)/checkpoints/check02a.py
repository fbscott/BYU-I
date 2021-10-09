###############################################################################
# Assignment:
#   Checkpoint 02a
#   curtis mellor, cs241
###############################################################################

def prompt_number():
    number_prompt = "Enter a positive number: "
    number = int(input(number_prompt))

    while number < 0:
        print("Invalid entry. The number must be positive.")
        number = int(input(number_prompt))

    print("")

    return number

def compute_sum(a, b, c):
    return a + b + c

def main():
    num_one   = int(prompt_number())
    num_two   = int(prompt_number())
    num_three = int(prompt_number())
    sum       = compute_sum(num_one, num_two, num_three)

    print(f"The sum is: {sum}")

if __name__ == "__main__":
    main()
