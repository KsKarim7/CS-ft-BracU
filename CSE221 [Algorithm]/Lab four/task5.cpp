// #include <fstream>
// #include <vector>
// #include <queue>
// #include <map>
// #include <iostream>

// class Queue
// {
// public:
//     std::vector<int> queue;

//     bool is_empty()
//     {
//         return queue.empty();
//     }

//     void enqueue(int val)
//     {
//         queue.push_back(val);
//     }

//     int dequeue()
//     {
//         if (is_empty())
//         {
//             return -1;
//         }
//         int val = queue[0];
//         queue.erase(queue.begin());
//         return val;
//     }
// };

// std::vector<int> bfs(std::map<int, std::vector<std::vector<int>>> &graph, int start, int end)
// {
//     for (auto &pair : graph)
//     {
//         pair.second.push_back(0);
//     }

//     Queue Q;
//     graph[start][1] = 1;
//     Q.enqueue(start);
//     return _bfs(graph, Q, start, end);
// }

// std::vector<int> _bfs(std::map<int, std::vector<std::vector<int>>> &graph, Queue &Q, int start, int end)
// {
//     std::map<int, std::vector<int>> parent_dict;
//     parent_dict[start] = {};
//     bool flag = false;
//     while (!Q.is_empty())
//     {
//         int node = Q.dequeue();
//         for (int val : graph[node][0])
//         {
//             if (parent_dict.find(val) == parent_dict.end())
//             {
//                 parent_dict[val] = {node};
//             }
//             else
//             {
//                 parent_dict[val].push_back(node);
//             }
//             Q.enqueue(val);
//             if (val == end)
//             {
//                 flag = true;
//                 break;
//             }
//             graph[val][1] = 1;
//         }
//         if (flag)
//         {
//             break;
//         }
//     }
//     std::vector<int> path = {end};
//     while (true)
//     {
//         if (parent_dict[path[0]].empty())
//         {
//             break;
//         }
//         if (parent_dict[path[0]].size() > 1)
//         {
//             path.insert(path.begin(), parent_dict[path[0]][0]);
//         }
//         else
//         {
//             path.insert(path.begin(), parent_dict[path[0]][0]);
//         }
//     }
//     return path;
// }

// void traversal()
// {
//     for (int n = 1; n < 6; n++)
//     {
//         std::ifstream f1("input5_" + std::to_string(n) + ".txt");
//         int vertices, edges, end;
//         f1 >> vertices >> edges >> end;
//         std::map<int, std::vector<std::vector<int>>> graph;
//         for (int i = 1; i <= vertices; i++)
//         {
//             graph[i] = {{}};
//         }
//         for (int i = 0; i < edges; i++)
//         {
//             int u, v;
//             f1 >> u >> v;
//             graph[u].push_back({v});
//         }
//         f1.close();

//         std::vector<int> bfs_arr = bfs(graph, 1, end);

//         std::ofstream f2("output5_" + std::to_string(n) + ".txt");
//         f2 << "Time: " << bfs_arr.size() - 1 << "\n";
//         f2 << "Shortest Path: ";
//         for (int val : bfs_arr)
//         {
//             f2 << val << " ";
//         }
//         f2.close();
//     }
// }

// int main()
// {
//     traversal();
//     return 0;
// }