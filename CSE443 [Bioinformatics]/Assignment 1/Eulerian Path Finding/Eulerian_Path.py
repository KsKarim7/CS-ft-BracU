from collections import defaultdict, deque

def parse_graph_from_file(filename):
    graph = defaultdict(deque)
    with open(filename, 'r') as file:
        for line in file:
            if '->' in line:
                src, dsts = line.strip().split("->")
                src = int(src.strip())
                for dst in dsts.strip().split(","):
                    graph[src].append(int(dst.strip()))
    return graph

def find_start_node(graph):
    out_deg = defaultdict(int)
    in_deg = defaultdict(int)

    for u in graph:
        for v in graph[u]:
            out_deg[u] += 1
            in_deg[v] += 1

    start = None
    for node in set(list(out_deg.keys()) + list(in_deg.keys())):
        if out_deg[node] - in_deg[node] == 1:
            return node
    return next(iter(graph))  # fallback to any node with outgoing edges

def find_eulerian_path(graph):
    graph = {u: deque(v) for u, v in graph.items()}
    path = []
    stack = []

    current = find_start_node(graph)
    stack.append(current)

    while stack:
        if graph.get(current) and graph[current]:
            stack.append(current)
            current = graph[current].popleft()
        else:
            path.append(current)
            current = stack.pop()

    return path[::-1]

# Update this path to the file location if needed
input_file = 'rosalind_ba3g (1).txt'
graph = parse_graph_from_file(input_file)
eulerian_path = find_eulerian_path(graph)

# Output the result
print("->".join(map(str, eulerian_path)))
