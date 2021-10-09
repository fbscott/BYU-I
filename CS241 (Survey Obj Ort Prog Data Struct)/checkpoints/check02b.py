user_provide_file = input("Enter file: ")

num_lines = 0
num_words = 0

# method for opening file and assigning its contents to a var
# resource: https://runestone.academy/runestone/books/published/thinkcspy/Files/Iteratingoverlinesinafile.html
# file = open(user_provide_file, "r")

# best practice is to use "with" to ensure the file is properly closed
# resource: https://docs.python.org/3/tutorial/inputoutput.html#reading-and-writing-files
with open(user_provide_file, "r") as file:

    for lines in file:
        words = lines.split()

        num_lines += 1
        num_words += len(words)

print(f"The file contains {num_lines} lines and {num_words} words.")

file.close()
