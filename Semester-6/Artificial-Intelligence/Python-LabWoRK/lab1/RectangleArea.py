# Define Rectangle class
class Rectangle:
    def __init__(self, length, width):
        self.length = length
        self.width = width

    # Method to calculate area
    def area(self):
        return self.length * self.width


# Take input from user
length = float(input("Enter length: "))
width = float(input("Enter width: "))

# Create object
rect = Rectangle(length, width)

# Print area
print("Area =", rect.area())
