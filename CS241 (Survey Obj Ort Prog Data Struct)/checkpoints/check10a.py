###############################################################################
# Assignment:
#   Checkpoint 10a
#   curtis mellor, cs241
###############################################################################

"""
File: sorting.py
Original Author: Br. Burton, designed to be completed by others.

Sorts a list of numbers.
"""

def selectionSort(numbers):
    """
    Fill in this method to sort the list of numbers
    """
    # range(start, stop, step)
    for i in range(len(numbers) -1, 0, -1):

        max_pos = 0

        for j in range(1, i + 1):
            if numbers[j] > numbers[max_pos]:
                max_pos = j

        # simultaneous assignment
        numbers[i], numbers[max_pos] = numbers[max_pos], numbers[i]

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
    selectionSort(numbers)
    display(numbers)

if __name__ == "__main__":
    main()