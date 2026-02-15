# Function to check prime number
def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True


# Take input from user
number = int(input("Enter a number between 0 and 1000: "))

# Check range
if 0 <= number <= 1000:
    if is_prime(number):
        print("prime number")
    else:
        print("not a prime number")
else:
    print("Number out of range")
