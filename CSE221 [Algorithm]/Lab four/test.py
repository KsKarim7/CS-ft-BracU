# # def build_graph():
# #     num_nodes, num_edges = map(int, input().split())
# #     graph = {i: [] for i in range(num_nodes)}

# #     for _ in range(num_edges):
# #         u, v, weight = map(int, input().split())
# #         graph[u].append((v, weight))

# #     for node in range(num_nodes):
# #         if graph[node]:
# #             print(f"{node} : {', '.join(f'({v},{w})' for v, w in graph[node])}")
# #         else:
# #             print(f"{node} :")

# # build_graph()


# #bfs traversal  

# # class Queue:
# #     def __init__(self):
# #         self.queue = []
        
# #     def _is_empty(self):
# #         return len(self.queue) == 0
        
# #     def enqueue(self, val):
# #         self.queue.append(val)
        
# #     def dequeue(self):
# #         if self._is_empty():
# #             return False
# #         return self.queue.pop(0)

# # def bfs(graph, start):
# #     for key in graph.keys():
# #         graph[key].append(0)
# #     print(graph)
# #     Q = Queue()
# #     graph[start][1] = 1
# #     Q.enqueue(start)
# #     bfs_arr = []
    
# #     while not Q._is_empty():
# #         ele = Q.dequeue()
# #         bfs_arr.append(ele)
# #         for val in graph[ele][0]:
# #             if graph[val][1] == 0:
# #                 graph[val][1] = 1
# #                 Q.enqueue(val)
                
# #     return bfs_arr

# # veritces = 4
# # edges = 3
# # diction = {i:[[]] for i in range(1, int(veritces) + 1)}

# # # print(diction)
# # for i in range(int(edges)):
# #     u, v = input().strip().split()
# #     diction[int(u)][0].append(int(v))
# # # print(diction)
# # bfs_arr = bfs(diction, 1)




# # class Queue:
# #     def __init__(self):
# #         self.queue = []

# #     def is_empty(self):
# #         return len(self.queue) == 0
# #     def enqueue(self,val):
# #         self.queue.append(val)
# #     def dequeue(self):
# #         if(self.is_empty()):
# #             return False
# #         return self.queue.pop(0)

# # def bfs(graph,start):
# #     for key in graph.keys():
# #         graph[key].append(0)

# #     # print(graph)
# #     Q = Queue()
# #     graph[start][1] = 1
# #     Q.enqueue(start)
# #     bfs_arr = []

# #     while not Q.is_empty():
# #           elem = Q.dequeue()
# #           bfs_arr.append(elem)
# #           for val in graph[elem][0]:
# #               if(graph[val][1] == 0):
# #                   graph[val][1] = 1
# #                   Q.enqueue(val)

# #     return bfs_arr

# # vertices,edges = map(int,input().strip().split())



# # dictt = {i:[[]] for i in range(1,vertices + 1)}
# # print(dictt)
# # for i in range(edges):
# #     u,v = map(int,input().strip().split())
# #     dictt[u][0].append(v)

# # bfs_arr = bfs(dictt,1)

# # print(dictt)

# def colour_init(graph):
#     for key in graph.keys():
#         graph[key].append(0)
        
#     return graph
    
    
# def dfs(graph, node, path):
#     graph[node][1] = 1
#     path.append(node)
    
#     for val in graph[node][0]:
#         if graph[val][1] == 0:
#             path = dfs(graph, val, path)
        
#     return path


# vertices,edges = map(int,input().strip().split())
# dictt = {i:[[]] for i in range(1,vertices + 1)}
# print(dictt)
# for i in range(edges):
#     u,v = map(int,input().strip().split())
#     dictt[u][0].append(v)

# diction = colour_init(dictt)
# dfs_arr = dfs(diction,1)

