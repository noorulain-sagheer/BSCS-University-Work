# Define the graph as an adjacency list
graph = {
    'w': ['p', 'p', 's', 'q'],
    's': ['u'],
    'q': ['r', 'u'],
    'u': ['p'],
    'r': ['w', 'v', 't'],
    'v': ['w', 't'],
    't': []
}

# Initialize visited list
visited = []

# DFS function using recursion
def dfs(visited, graph, node):
    visited.append(node)
    print(node, end=" --> ")
    
    for neighbour in graph[node]:
        if neighbour not in visited:
            dfs(visited, graph, neighbour)


# Run DFS
print("Following is DFS")
dfs(visited, graph, 'w')
