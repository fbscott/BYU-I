import random
from random import randint

# welcome message
print("Welcome to the number guessing game!")

# get the random seed
seed_value = input("Enter random seed: ")
random.seed(seed_value)
can_play = True

def play():

    random_number = randint(1, 100)
    number_of_guesses = 1
    guess_value = ""

    while guess_value != random_number:

        # prompt the user for a guess
        guess_value = int(input("\nPlease enter a guess: "))

        # provide higher/lower hint
        if guess_value == random_number:
            print(f"Congratulations. You guessed it!\nIt took you {number_of_guesses} guesses.")
        elif guess_value > random_number:
            print("Lower")
        else:
            print("Higher")

        # increment the count
        number_of_guesses += 1

def replay():

    global can_play
    
    play_again = input("\nWould you like to play again (yes/no)? ")

    if play_again == "no":
        can_play = False
        print("Thank you. Goodbye.")

while can_play == True:
    play()
    replay()
