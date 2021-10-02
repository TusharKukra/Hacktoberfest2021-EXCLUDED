class graph:
    def __init__(self, gd=None):
        if gd is None:
            gd = {}
        self.gd = gd

# Check for the nodes which are visisted and unvisited


def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    print(start)
    for next in graph[start] - visited:
        dfs(graph, next, visited)
    return visited


gd = {
    "1": set(["2", "3"]),
    "2": set(["1", "4"]),
    "3": set(["1", "4"]),
    "4": set(["5"]),
    "5": set(["1"])
}
dfs(gd, '1')
