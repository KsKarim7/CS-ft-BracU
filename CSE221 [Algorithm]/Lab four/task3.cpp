// #include <fstream>
// #include <vector>
// #include <map>
// #include <iostream>

// std::map<int, std::vector<std::vector<int>>> colour_init(std::map<int, std::vector<std::vector<int>>> &graph)
// {
//     for (auto &pair : graph)
//     {
//         pair.second.push_back(0);
//     }
//     return graph;
// }

// std::vector<int> dfs(std::map<int, std::vector<std::vector<int>>> &graph, int node, std::vector<int> &path)
// {
//     graph[node][1] = 1;
//     path.push_back(node);

//     for (int val : graph[node][0])
//     {
//         if (graph[val][1] == 0)
//         {
//             dfs(graph, val, path);
//         }
//     }

//     return path;
// }

// void traversal()
// {
//     for (int n = 1; n < 5; n++)
//     {
//         std::ifstream f1("input3_" + std::to_string(n) + ".txt");
//         int vertices, edges;
//         f1 >> vertices >> edges;
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

//         graph = colour_init(graph);
//         std::vector<int> dfs_arr;
//         dfs_arr = dfs(graph, 1, dfs_arr);

//         std::ofstream f2("output3_" + std::to_string(n) + ".txt");
//         for (int val : dfs_arr)
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