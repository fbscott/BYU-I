S = [x**2 for x in range(10)]    # [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
V = [2**i for i in range(13)]    # [1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096]
M = [x for x in S if x % 2 == 0] # [0, 4, 16, 36, 64]
Q = [x**3 for x in range(11)]    # [0, 1, 8, 27, 64, 125, 216, 343, 512, 729, 1000]
X = [x**x for x in range(6)]     # [1, 1, 4, 27, 256, 3125]

# print(f'S: {S}')
# print(f'V: {V}')
# print(f'M: {M}')
# print(f'Q: {Q}')
# print(f'X: {X}')

# if with an else
print([i if i % 2 == 0 else 0 for i in range(10)])

"""
Purpose: This file is a starting point to help you practice list comprehensions.
"""

def get_part1_list():
    """
    Returns a list of the squares of the numbers [0-99], e.g., 0, 1, 4, 9, 16, 25 ...]
    """
    numbers = [x**2 for x in range(100)]

    return numbers

def get_part2_list():
    """
    Returns a list of the the numbers [0-99] that are divisible by either 5 or 7
    """
    numbers = [x for x in range(100) if x % 5 == 0 or x % 7 == 0]

    return numbers

def get_part3_list():
    """
    Filters a list of words to return only those that are at least 4 letters long and contain an 'e'
    """
    old_words = ["tacos", "knowledge", "water", "on", "the", "I", "is", "hilarious", "tie", "coat", "white", "covenants", "phone", "rubric", "send", "restrictions"]

    new_words = [w for w in old_words if len(w) > 4 and 'e' in w]

    return new_words

def main():
    """
    This function calls the above functions and displays their result.
    """
    # print(get_part1_list())
    # print(get_part2_list())
    # print(get_part3_list())


if __name__ == "__main__":
    main()
