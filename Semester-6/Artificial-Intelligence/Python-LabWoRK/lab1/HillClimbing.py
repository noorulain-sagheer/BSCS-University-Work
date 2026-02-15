import random

def hill_climb(fitness, x_start, iterations, step_size):
    x = x_start
    for _ in range(iterations):
        neighbor = x + random.uniform(-step_size, step_size)
        if fitness(neighbor) > fitness(x):
            x = neighbor
    return x

def fitness(x):
    return -(x-3)**2 + 9

result = hill_climb(fitness, x_start=0, iterations=1000, step_size=0.1)
print("Maximum at:", result, "with value:", fitness(result))
