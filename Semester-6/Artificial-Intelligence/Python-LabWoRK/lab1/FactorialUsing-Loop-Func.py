# Function to calculate factorial
def factorial(n):
    result = 1
    for i in range(1, n + 1):
        result = result * i
    return result


# Take input from user
number = int(input("Enter a number between 1 and 20: "))

# Check range
if 1 <= number <= 20:
    print("Factorial =", factorial(number))
else:
    print("Number out of range")
