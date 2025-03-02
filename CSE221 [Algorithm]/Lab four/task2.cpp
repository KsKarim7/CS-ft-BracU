// #include <fstream>
// #include <vector>
// #include <queue>
// #include <map>
// #include <iostream>

// class Queue {
// private:
//     std::queue<int> q;
// public:
//     bool isEmpty() {
//         return q.empty();
//     }
//     void enqueue(int val) {
//         q.push(val);
//     }
//     int dequeue() {
//         if (isEmpty()) {
//             return -1; // or throw an exception
//         }
//         int val = q.front();
//         q.pop();
//         return val;
//     }
// };

// std::vector<int> bfs(std::map<int, std::vector<std::vector<int>>>& graph, int start) {
//     for (auto& pair : graph) {
//         pair.second.push_back(0);
//     }
//     Queue Q;
//     graph[start][1] = 1;
//     Q.enqueue(start);
//     std::vector<int> bfs_arr;

//     while (!Q.isEmpty()) {
//         int ele = Q.dequeue();
//         bfs_arr.push_back(ele);
//         for (int val : graph[ele][0]) {
//             if (graph[val][1] == 0) {
//                 graph[val][1] = 1;
//                 Q.enqueue(val);
//             }
//         }
//     }
//     return bfs_arr;
// }

// void traversal() {
//     for (int n = 1; n < 5; n++) {
//         std::ifstream f1("input2_" + std::to_string(n) + ".txt");
//         int vertices, edges;
//         f1 >> vertices >> edges;
//         std::map<int, std::vector<std::vector<int>>> graph;
//         for (int i = 1; i <= vertices; i++) {
//             graph[i] = {{}};
//         }
//         for (int i = 0; i < edges; i++) {
//             int u, v;
//             f1 >> u >> v;
//             graph[u].push_back({v});
//         }
//         f1.close();
//         std::vector<int> bfs_arr = bfs(graph, 1);
//         std::ofstream f2("output2_" + std::to_string(n) + ".txt");
//         for (int val : bfs_arr) {
//             f2 << val << " ";
//         }
//         f2.close();
//     }
// }

// int main() {
//     traversal();
//     return 0;
// }