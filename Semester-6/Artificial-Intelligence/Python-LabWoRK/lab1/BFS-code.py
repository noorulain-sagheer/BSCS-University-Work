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

# Initialize visited list and queue
visited = []
queue = []

# BFS function
def bfs(visited, graph, node):
    visited.append(node)
    queue.append(node)

    while queue:
        m = queue.pop(0)
        print(m, end=" --> ")

        for neighbour in graph[m]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)


# Run BFS
print("Following is BFS")
bfs(visited, graph, 'w')
