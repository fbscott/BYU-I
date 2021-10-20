###############################################################################
# Assignment:
#   Checkpoint 06a
#   curtis mellor, cs241
###############################################################################

class Book:
    def __init__(self):
        self.title = ""
        self.author = ""
        self.publication_year = ""

    def prompt_book_info(self):
        self.title = input("Title: ")
        self.author = input("Author: ")
        self.publication_year = input("Publication Year: ")

    def display_book_info(self):
        print(f"{self.title} ({self.publication_year}) by {self.author}")

class TextBook(Book):
    def __init__(self):
        self.subject = ""

    def prompt_subject(self):
        self.subject = input("Subject: ")

    def display_subject(self):
        print(f"Subject: {self.subject}")

class PictureBook(Book):
    def __init__(self):
        self.illustrator = ""

    def prompt_illustrator(self):
        self.illustrator = input("Illustrator: ")

    def display_illustrator(self):
        print(f"Illustrated by {self.illustrator}")

def main():
    book = Book()
    book.prompt_book_info()
    print()
    book.display_book_info()
    print()

    textbook = TextBook()
    textbook.prompt_book_info()
    textbook.prompt_subject()
    print()
    textbook.display_book_info()
    textbook.display_subject()
    print()

    picturebook = PictureBook()
    picturebook.prompt_book_info()
    picturebook.prompt_illustrator()
    print()
    picturebook.display_book_info()
    picturebook.display_illustrator()

if __name__ == "__main__":
    main()
