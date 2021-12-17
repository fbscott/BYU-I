import re

###############################################################################
# PROMPT FOR FILE
###############################################################################
def prompt_filename():
    return input("Please enter the data file: ")

###############################################################################
# PARSE FILE
###############################################################################
def parse_file(file_name):

    count = 0

    with open(file_name) as f:

        for line in f:

            words = line.split()

            for word in words:

                if re.search("pride", word):

                    count += 1

    f.close()

    return count

###############################################################################
# MAIN
###############################################################################
def main():

    file_name = prompt_filename()

    print(f"Opening file {file_name}")

    print(f"The word pride occurs {parse_file(file_name)} times in this file")

if __name__ == "__main__":
    main()
