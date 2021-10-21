class Point():
    def __init__(self):
        self.x = 0
        self.y = 0

    def prompt_for_point(self):
        self.x = float(input("Enter x: "))
        self.y = float(input("Enter y: "))

    def display(self):
        print("({:.0f}, {:.0f})".format(self.x, self.y))

# Circle class for Core Requirements (IS-A)
# class Circle(Point):
#     def __init__(self):
#         super().__init__()
#         self.radius = 0

#     def prompt_for_circle(self):
#         self.prompt_for_point()
#         self.radius = float(input("Enter radius: "))

#     def display(self):
#         print("Center:")
#         super().display()
#         print("Radius: {:.0f}".format(self.radius))

# Circle class for Stretch Challenges (HAS-A)
class Circle():
    def __init__(self):
        self.center = Point()
        self.radius = 0

    def prompt_for_circle(self):
        self.center.prompt_for_point()
        self.radius = float(input("Enter radius: "))

    def display(self):
        print("Center:")
        self.center.display()
        print("Radius: {:.0f}".format(self.radius))

def main():
    circle = Circle()
    # circle.prompt_for_point()
    circle.prompt_for_circle()
    circle.display()

if __name__ == "__main__":
    main()
