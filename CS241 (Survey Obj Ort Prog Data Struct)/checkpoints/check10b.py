###############################################################################
# Assignment:
#   Checkpoint 10b
#   curtis mellor, cs241
###############################################################################

"""
File: sorting.py
Original Author: Br. Burton, designed to be completed by others.

Sorts a list of numbers.
"""

def insertionSort(numbers):
    """
    Fill in this method to sort the list of numbers
    """
    # range(start, stop)
    for i in range(1, len(numbers)):

        current_value = numbers[i]

        while i > 0 and numbers[i - 1] > current_value:
            numbers[i] = numbers[i - 1]
            i -= 1

        numbers[i] = current_value

def prompt_for_numbers():
    """
    Prompts the user for a list of numbers and returns it.
    :return: The list of numbers.
    """

    numbers = []
    print("Enter a series of numbers, with -1 to quit")

    num = 0

    while num != -1:
        num = int(input())

        if num != -1:
            numbers.append(num)

    return numbers

def display(numbers):
    """
    Displays the numbers in the list
    """
    print("The list is:")
    for num in numbers:
        print(num)

def main():
    """
    Tests the sorting process
    """
    numbers = prompt_for_numbers()
    insertionSort(numbers)
    display(numbers)

if __name__ == "__main__":
    main()