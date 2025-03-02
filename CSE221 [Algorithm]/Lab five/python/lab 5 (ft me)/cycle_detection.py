def dfs(u, p,adj,visited):
    visited[u] = True
    cycle_exist = False
    for v in adj[u]:
        if v == p:
            continue
        if visited[v]:
            return True
        cycle_exist = cycle_exist or dfs(v, u,adj,visited)
    return cycle_exist

n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]
visited = [False] * (n+1)

for _ in range(m):
    a,b = map(int,input().split())
    adj[a].append(b)

is_cycle = False
for i in range(1, n + 1):
    if visited[i]:
        continue
    is_cycle = is_cycle or dfs(i, -1,adj,visited)

if is_cycle:
    print("Cycle Detected!")
else:
    print("No Cycle Detected!")