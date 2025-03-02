// #include <fstream>
// #include <vector>
// #include <queue>
// #include <iostream>

// class Queue {
// public:
//     std::vector<std::pair<int, int>> queue;

//     bool isEmpty() {
//         return queue.empty();
//     }

//     void enqueue(std::pair<int, int> val) {
//         queue.push_back(val);
//     }

//     std::pair<int, int> dequeue() {
//         if (isEmpty()) {
//             return {-1, -1};
//         }
//         std::pair<int, int> val = queue[0];
//         queue.erase(queue.begin());
//         return val;
//     }
// };

// std::pair<int, std::vector<std::pair<int, int>>> bfs(std::vector<std::vector<std::vector<std::string>>>& graph, std::pair<int, int> start, int row, int col) {
//     Queue Q;
//     graph[start.first][start.second][1] = "1";
//     Q.enqueue(start);
//     int diamonds = 0;
//     if (graph[start.first][start.second][0] == "D") {
//         diamonds++;
//     }
//     std::vector<std::pair<int, int>> block;

//     while (!Q.isEmpty()) {
//         std::pair<int, int> ele = Q.dequeue();
//         std::vector<std::pair<int, int>> ways = {
//             {ele.first, ele.second + 1},
//             {ele.first + 1, ele.second},
//             {ele.first - 1, ele.second},
//             {ele.first, ele.second - 1},
//         };
//         for (std::pair<int, int> way : ways) {
//             if (0 <= way.first && way.first < row && 0 <= way.second && way.second < col) {
//                 if (graph[way.first][way.second][0] == "#") {
//                     block.push_back(way);
//                     continue;
//                 }
//                 if (graph[way.first][way.second][1] == "1") {
//                     continue;
//                 }
//                 graph[way.first][way.second][1] = "1";
//                 Q.enqueue(way);
//                 if (graph[way.first][way.second][0] == "D") {
//                     diamonds++;
//                 }
//             }
//         }
//     }

//     return {diamonds, block};
// }

// std::tuple<std::vector<std::vector<std::vector<std::string>>>, int, int> matrix(std::ifstream& f1) {
//     int row, col;
//     f1 >> row >> col;
//     std::vector<std::vector<std::vector<std::string>>> matrix(row, std::vector<std::vector<std::string>>(col, std::vector<std::string>(2)));
//     for (int i = 0; i < row; i++) {
//         std::string line;
//         std::getline(f1, line);
//         for (int j = 0; j < col; j++) {
//             matrix[i][j][0] = line[j];
//             matrix[i][j][1] = "0";
//         }
//     }
//     return {matrix, row, col};
// }

// void dungeon() {
//     for (int n = 1; n < 8; n++) {
//         std::ifstream f1("input6_" + std::to_string(n) + ".txt");
//         std::tuple<std::vector<std::vector<std::vector<std::string>>>, int, int> matrix_arr = matrix(f1);
//         std::pair<int, std::vector<std::pair<int, int>>> result = bfs(std::get<0>(matrix_arr), {0, 0}, std::get<1>(matrix_arr), std::get<2>(matrix_arr));
//         int diamonds = result.first;
//         std::vector<std::pair<int, int>> blocks = result.second;
//         for (std::pair<int, int> block : blocks) {
//             std::vector<std::pair<int, int>> ways = {
//                 {block.first, block.second + 1},
//                 {block.first + 1, block.second},
//                 {block.first - 1, block.second},
//                 {block.first, block.second - 1},
//             };
//             for (std::pair<int, int> way : ways) {
//                 if (0 <= way.first && way.first < std::get<1>(matrix_arr) && 0 <= way.second && way.second < std::get<2>(matrix_arr)) {
//                     if (std::get<0>(matrix_arr)[way.first][way.second][0]!= "#" && std::get<0>(matrix_arr)[way.first][way.second][1] == "0") {
//                         std::pair<int, std::vector<std::pair<int, int>>> new_result = bfs(std::get<0>(matrix_arr), way, std::get<1>(matrix_arr), std::get<2>(matrix_arr));
//                         if (new_result.first