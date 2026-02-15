# Take input from user
number = int(input("Enter the number: "))
start = int(input("Enter the starting range: "))
end = int(input("Enter the ending range: "))

# Print multiplication table
for i in range(start, end + 1):
    print(number, "x", i, "=", number * i)
