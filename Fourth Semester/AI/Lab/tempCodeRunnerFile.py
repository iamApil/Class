adj_list = {
    "a": ["b", "c"],
    "b": ["d", "e"],
    "c": ["f", "g"],
    "d": ["h"],
    "e": [],
    "f": [],
    "g": ["i"],
    "h": [],
    "i": []
}

closed_list = {}
traversed_output = []

for node in adj_list.keys():
    closed_list[node] = "not visited"


def dfs(u):
    closed_list[u] = "visited"
    traversed_output.append(u)

    for v in adj_list[u]:
        if closed_list[v] != "visited":
            dfs(v)


print("----DFS---")
startNode = input("Enter the root node")
dfs(startNode)

print(traversed_output, startNode)
