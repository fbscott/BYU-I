# example one
class Bear(object):
    def sound(self):
        print("Groarrr")
    
class Dog(object):
    def sound(self):
        print("Woof woof!")
    
def makeSound(animalType):
    # abstraction of the "sound" method
    # no specific implementation is configured
    animalType.sound()
    

bearObj = Bear()
dogObj = Dog()

makeSound(bearObj)
makeSound(dogObj)

# example two
class Document:
    """
    Abstract classes don't not have an implementation but define the structure
    (in form of functions) that all derived classes must have.
    """
    def __init__(self, name):
        self.name = name

    def show(self):
        # In user defined base classes, abstract methods should raise this
        # exception when they require derived classes to override the method,
        # or while the class is being developed to indicate that the real
        # implementation still needs to be added.
        # Source: https://docs.python.org/3/library/exceptions.html#NotImplementedError
        raise NotImplementedError("Derived classes must implement a show() method")

class Pdf(Document):
    """Implementation of the Document abstract class."""
    def show(self):
        return 'Show pdf contents!'

class Word(Document):
    """Implementation of the Document abstract class."""
    def show(self):
        return 'Show word contents!'

documents = [Pdf('Document1'),
    Pdf('Document2'),
    Word('Document3')]

for document in documents:
    print(document.name + ': ' + document.show())

# example three
class Car:
    def __init__(self, name):
        self.name = name

    def drive(self):
        raise NotImplementedError("Derived classes must implement a drive() method")

    def stop(self):
        raise NotImplementedError("Derived classes must implement a stop() method")

    def park(self):
        raise NotImplementedError("Derived classes must implement a park() method")

class Sportscar(Car):
    def drive(self):
        return 'Sportscar driving!'

    def stop(self):
        return 'Sportscar braking!'

    def park(self):
        return 'Parking the car.'

class Truck(Car):
    def drive(self):
        return 'Truck driving slowly because heavily loaded.'

    def stop(self):
        return 'Truck braking!'

    # will throw an error without the park() method
    # def park(self):
    #     return 'Parking the truck.'

cars = [Truck('Bananatruck'),
    Truck('Orangetruck'),
    Sportscar('Z3')]

for car in cars:
    print(car.name + ': ' + car.drive() + ': ' + car.park())
