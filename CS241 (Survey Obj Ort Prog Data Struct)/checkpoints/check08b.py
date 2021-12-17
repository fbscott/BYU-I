###############################################################################
# Assignment:
#   Checkpoint 08b
#   curtis mellor, cs241
###############################################################################

class GPA:
    def __init__(self, gpa = 0.0):
        self.__gpa = float(gpa)

    def __get_gpa(self):
        return self.__gpa

    def __set_gpa(self, gpa):
        if gpa < 0:
            self.__gpa = 0
        elif gpa > 4:
            self.__gpa = 4.0
        else:
            self.__gpa = gpa

    def __get_letter(self):
        if self.__gpa <= 0.99:
            return 'F'
        elif self.__gpa <= 1.99:
            return 'D'
        elif self.__gpa <= 2.99:
            return 'C'
        elif self.__gpa <= 3.99:
            return 'B'
        else:
            return 'A'

    def __set_letter(self, letter):
        if letter == 'F':
            self.__set_gpa(0.0)
        elif letter == 'D':
            self.__set_gpa(1.0)
        elif letter == 'C':
            self.__set_gpa(2.0)
        elif letter == 'B':
            self.__set_gpa(3.0)
        else:
            self.__set_gpa(4.0)

    gpa = property(__get_gpa, __set_gpa)

    @property
    def letter(self):
        return self.__get_letter()

    @letter.setter
    def letter(self, letter):
        self.__set_letter(letter)

def main():
    student = GPA()

    print("Initial values:")
    print("GPA: {:.2f}".format(student.gpa))
    print("Letter: {}".format(student.letter))

    value = float(input("Enter a new GPA: "))

    student.gpa = value

    print("After setting value:")
    print("GPA: {:.2f}".format(student.gpa))
    print("Letter: {}".format(student.letter))

    letter = input("Enter a new letter: ")

    student.letter = letter

    print("After setting letter:")
    print("GPA: {:.2f}".format(student.gpa))
    print("Letter: {}".format(student.letter))

if __name__ == "__main__":
    main()
