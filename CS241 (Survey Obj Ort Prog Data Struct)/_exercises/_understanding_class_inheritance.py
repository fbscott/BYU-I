# source: https://www.digitalocean.com/community/tutorials/understanding-class-inheritance-in-python-3

"""
Inheritance
"""
class Fish:
    """Parent Class"""
    def __init__(self, first_name, last_name="Fish",
                 skeleton="bone", eyelids=False):
        self.first_name = first_name
        self.last_name = last_name
        self.skeleton = skeleton
        self.eyelids = eyelids

    def swim(self):
        print("The fish is swimming.")

    def swim_backwards(self):
        print("The fish can swim backwards.")

class Clownfish(Fish):
    """Child Class"""
    def live_with_anemone(self):
        print("The clownfish is coexisting with sea anemone.")

class Trout(Fish):
    """Child Class"""
    def __init__(self, water = "freshwater"):
        self.water = water
        super().__init__(self)

class Shark(Fish):
    """Child Class"""
    def __init__(self, first_name, last_name="Shark",
                 skeleton="cartilage", eyelids=True):
        self.first_name = first_name
        self.last_name = last_name
        self.skeleton = skeleton
        self.eyelids = eyelids

    def swim_backwards(self):
        print("The shark cannot swim backwards, but can sink backwards.")

# casey = Clownfish("Casey")
# print(casey.first_name + " " + casey.last_name)
# casey.swim()
# casey.live_with_anemone()
# print()

# terry = Trout()
# # No longer pass "first_name" because the "Trout" class is overriding the
# # parent "Fish" class. Instead, initialize the "first_name" attribute on the
# # "Terry" instance.
# terry.first_name = "Terry"
# print(terry.first_name + " " + terry.last_name)
# print(terry.skeleton)
# print(terry.eyelids)
# print(terry.water)
# terry.swim()
# terry.swim_backwards()
# print()

# sammy = Shark("Sammy")
# print(sammy.first_name + " " + sammy.last_name)
# sammy.swim()
# sammy.swim_backwards()
# print(sammy.eyelids)
# print(sammy.skeleton)

"""
Multiple Inheritance
"""
class Coral:
    """Parent Class 1"""
    def community(self):
        print("Coral lives in a community.")

class Anemone:
    """Parent Class 2"""
    def protect_clownfish(self):
        print("The anemone is protecting the clownfish.")

class CoralReef(Coral, Anemone):
    pass

great_barrier = CoralReef()
great_barrier.community()
great_barrier.protect_clownfish()
