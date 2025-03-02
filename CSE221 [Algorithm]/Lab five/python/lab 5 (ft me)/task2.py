
def dfs(graph,visited,res,node):
    visited[node] = True
    # lst = graph[node]
    # lst.sort()
    for neighbor in graph[node]:

        if not visited[neighbor]:
            dfs(graph,visited,res,neighbor)
    res.append(node)



def topological_sort(graph, n):
    visited = [False] * (n + 1)
    res = []
    nodes = list(range(n, 0, -1))
    # print('node', nodes)
    for node in nodes:
        if not visited[node]:
            # print('notv', node)
            dfs(graph, visited, res, node)
    return res[::-1]



n,m = map(int,input().split())
graph = [[] for _ in range(n+1)]

for _ in range(m):
    a,b = map(int,input().split())
    graph[a].append(b)

order = topological_sort(graph,n)
print(order)
