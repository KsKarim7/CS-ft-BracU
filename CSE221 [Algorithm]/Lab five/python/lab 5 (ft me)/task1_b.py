def bfs(graph, in_degree, n):
    queue = []  # Initialize an empty list to serve as a queue
    order = []
    for node in range(1, n + 1):
        if in_degree[node] == 0:
            queue.append(node)  # Add nodes with in-degree 0 to the queue
    while queue:
        node = queue.pop(0)  # Remove the front element from the queue
        order.append(node)
        for neighbor in graph[node]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)  # Add neighbors with in-degree 0 to the queue
    return order


n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
in_degree = [0] * (n + 1)
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    in_degree[b] += 1

# check cycle detection of graph like we have discussed in the previous problem, if there is a cycle print impossible or else just call bfs like this: 
order = bfs(graph, in_degree, n)

# if len(order) == n:
#     print(' '.join(map(str, order)))
# else:
#     print("IMPOSSIBLE")
