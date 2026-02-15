from constraint import Problem

problem = Problem()

regions = ["WA", "NT", "SA", "Q", "NSW", "V", "T"]
colors = ["Red", "Green", "Blue"]

problem.addVariables(regions, colors)

problem.addConstraint(lambda a, b: a != b, ("WA", "NT"))
problem.addConstraint(lambda a, b: a != b, ("WA", "SA"))
problem.addConstraint(lambda a, b: a != b, ("NT", "SA"))
problem.addConstraint(lambda a, b: a != b, ("NT", "Q"))
problem.addConstraint(lambda a, b: a != b, ("SA", "Q"))
problem.addConstraint(lambda a, b: a != b, ("SA", "NSW"))
problem.addConstraint(lambda a, b: a != b, ("SA", "V"))
problem.addConstraint(lambda a, b: a != b, ("Q", "NSW"))
problem.addConstraint(lambda a, b: a != b, ("NSW", "V"))

solutions = problem.getSolutions()
for solution in solutions:
    print(solution)
