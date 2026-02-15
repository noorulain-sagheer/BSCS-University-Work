# Function to check prime number
def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True


# Function to count even, odd, and prime numbers
def count_numbers(numbers):
    even_count = 0
    odd_count = 0
    prime_count = 0

    for num in numbers:
        if num % 2 == 0:
            even_count += 1
        else:
            odd_count += 1

        if is_prime(num):
            prime_count += 1

    return even_count, odd_count, prime_count


# Take 20 integers from user
nums = []
print("Enter 20 integers:")

for i in range(20):
    value = int(input(f"Enter number {i+1}: "))
    nums.append(value)

# Call function
even, odd, prime = count_numbers(nums)

# Display results
print("\nResults:")
print("Even numbers:", even)
print("Odd numbers:", odd)
print("Prime numbers:", prime)
