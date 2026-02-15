# Create an empty list
numbers = []

# Take at least 5 numbers from user
print("Enter at least 5 numbers:")

for i in range(5):
    num = int(input(f"Enter number {i+1}: "))
    numbers.append(num)

# Convert list to set to remove duplicates
unique_numbers = set(numbers)

# Convert back to list and sort
sorted_list = sorted(list(unique_numbers))

# Display result
print("Unique numbers in sorted order:", sorted_list)
