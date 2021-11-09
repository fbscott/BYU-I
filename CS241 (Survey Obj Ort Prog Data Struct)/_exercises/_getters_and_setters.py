class Getter_Setter:
    """Utilizing getters and setters"""
    def __init__(self, x = 0):
        self.__x = x

    def get_x(self):
        return self.__x
    
    def set_x(self, x):
        if x < 0:
            self.__x = 0
        elif x > 10:
            self.__x = 10
        else:
            self.__x = x

class Property:
    """Utilizing properties - Pythonic way"""
    def __init__(self, x = 0):
        self.x = x

    @property # decorator
    def x(self):
        return self.__x

    @x.setter # decorator
    def x(self, x):
        if x < 0:
            self.__x = 0
        elif x > 10:
            self.__x = 10
        else:
            self.__x = x

class Alternate:
    """Alternative method utilizing getters/setters but w/o decorators"""
    def __init__(self, x = 0):
        self.__set_x(x)

    def __get_x(self):
        return self.__x

    def __set_x(self, x):
        if x < 0:
            self.__x = 0
        elif x > 10:
            self.__x = 10
        else:
            self.__x = x

    x = property(__get_x, __set_x)

def main():
    gs = Getter_Setter()
    p = Property()
    alt = Alternate()

    gs.set_x(12)
    p.x = 24
    alt.x = 36

    print(gs.get_x())
    print(p.x)
    print(alt.x)

if __name__ == "__main__":
    main()
