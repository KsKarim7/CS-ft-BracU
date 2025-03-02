import sys
import heapq

def dijkstra(graph, source):

    distances = [sys.maxsize] * len(graph)
    distances[source - 1] = 0  # subtract 1 because node indices are 1-based

    pq = [(0, source)] 

    while pq:
        dist, node = heapq.heappop(pq)
        if dist > distances[node - 1]:
            continue
        for neighbor, weight in graph[node - 1]:
            old_dist = distances[neighbor - 1]
            new_dist = distances[node - 1] + weight
            if new_dist < old_dist:
                distances[neighbor - 1] = new_dist
                heapq.heappush(pq, (new_dist, neighbor))

    return distances

# Read input
N, M = map(int, input().split())
graph = [[] for _ in range(N)]
for _ in range(M):
    u, v, w = map(int, input().split())
    graph[u - 1].append((v, w))
S = int(input())

# Run Dijkstra's algorithm
distances = dijkstra(graph, S)

# Output results
print(' '.join(str(d) if d != sys.maxsize else '-1' for d in distances))




# def find_meeting_point(graph, S, T):
#     """
#     Find the meeting point of Alice and Bob in the graph.

#     Args:
#         graph (list of lists): Adjacency list representation of the graph, where each inner list represents a node and its edges.
#         S (int): Starting node of Alice.
#         T (int): Starting node of Bob.

#     Returns:
#         meeting_point (tuple): A tuple containing the minimum time it takes for Alice and Bob to meet and the vertex where they will meet.
#     """
#     alice_distances = dijkstra(graph, S)
#     bob_distances = dijkstra(graph, T)

#     min_time = sys.maxsize
#     meeting_point = None

#     for i in range(len(graph)):
#         time = alice_distances[i] + bob_distances[i]
#         if time < min_time:
#             min_time = time
#             meeting_point = i + 1  # add 1 because node indices are 1-based

#     if meeting_point is None:
#         return "Impossible"
#     else:
#         return (min_time, meeting_point)

# # Read input
# N, M = map(int, input().split())
# graph = [[] for _ in range(N)]
# for _ in range(M):
#     u, v, w = map(int, input().split())
#     graph[u - 1].append((v, w))
# S, T = map(int, input().split())

# # Find the meeting point
# meeting_point = find_meeting_point(graph, S, T)

# # Output result
# if meeting_point == "Impossible":
#     print(meeting_point)
# else:
#     print(meeting_point[0], meeting_point[1])

# import sys
# import heapq

# def safest_path(graph, N):
#     """
#     Find the safest path from node 1 to node N.

#     Args:
#         graph (list of lists): Adjacency list representation of the graph, where each inner list represents a node and its edges.
#         N (int): Destination node.

#     Returns:
#         min_danger (int): Minimum danger level of the safest path from node 1 to node N, or "Impossible" if no path exists.
#     """
#     distances = [sys.maxsize] * len(graph)
#     distances[0] = 0  # node 1 is the source node

#     pq = [(0, 1)]  # priority queue to store nodes to be processed

#     while pq:
#         danger, node = heapq.heappop(pq)
#         if danger > distances[node - 1]:
#             continue
#         for neighbor, weight in graph[node - 1]:
#             old_danger = distances[neighbor - 1]
#             new_danger = max(danger, weight)
#             if new_danger < old_danger:
#                 distances[neighbor - 1] = new_danger
#                 heapq.heappush(pq, (new_danger, neighbor))

#     if distances[N - 1] == sys.maxsize:
#         return "Impossible"
#     else:
#         return distances[N - 1]

# # Read input
# N, M = map(int, input().split())
# graph = [[] for _ in range(N)]
# for _ in range(M):
#     u, v, w = map(int, input().split())
#     graph[u - 1].append((v, w))

# # Find the safest path
# min_danger = safest_path(graph, N)

# # Output result
# print(min_danger)