import queue

adj_list = (
    "a": ["b", "c"],
    "b": ["d", "e"],
    "c": ["f"],
    "d": [],
    "e": ["g"],
    "f": ["h", "i"],
    "g": [],
    "h": [],
    "i": []
)

visited = []
queue = []
traversed_output = []


def bfs(visited, graph, node)


visited.append(node)
queue.append(node)
while queue:
    m = queue.pop(0)
    traversed_output.append(m)
    for neighbour in graph[m]:
        visited.append(neighbour)
        queue.append(neighbour)


print(traversed_output)


print("----BFS----")
root = input("Enter the root node:")

bfs(visited, adj_list, root)
