odds = []
evens = []
replay = True

def updateArray():
    """ Add numbers to the appropriate array (odds/evens) """

    global replay

    number = int(input("Enter a number (0 to quit): "))

    if number == 0:
        replay = False
        return
    elif (number % 2) == 0:
        evens.append(number)
    else:
        odds.append(number)

def main():
    """ Main """

    while replay:
        updateArray()

    print("\nEven numbers:")

    for even in evens:
        print(even)

    print("\nOdd numbers:")

    for odd in odds:
        print(odd)

if __name__ == "__main__":
    main()
