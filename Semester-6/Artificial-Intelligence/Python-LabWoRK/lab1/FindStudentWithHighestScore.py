# Function to find student with highest score
def highest_score(students):
    top_student = max(students, key=students.get)
    print(f"{top_student} has the highest score of {students[top_student]}")


# Create empty dictionary
students = {}

# Take input for 3 students
for i in range(3):
    name = input(f"Enter name of student {i+1}: ")
    score = int(input(f"Enter score of {name}: "))
    students[name] = score

# Call function
highest_score(students)
