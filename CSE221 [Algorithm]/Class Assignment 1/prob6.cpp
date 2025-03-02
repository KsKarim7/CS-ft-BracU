// a)
// A -- B -- F
// |    |    |
// |    |    G
// |    C -- |
// |  / | \  |
// |/  |  \ |
// D -- E -- H

// b)B. Adjacency List and Adjacency Matrix

// Here is the adjacency list representation of the graph:
//  vector<vector<int>> adjList = {
//     {1, 2, 3, 4},  // A
//     {0, 2, 5},  // B
//     {0, 1, 3, 6},  // C
//     {0, 2, 4, 6, 7},  // D
//     {0, 3, 7},  // E
//     {1, 6},  // F
//     {2, 3, 5, 7},  // G
//     {3, 4, 6}  // H
// };
// adjacency matrix representation of the graph:
// int adjMatrix[8][8] = {
//     {0, 1, 1, 1, 1, 0, 0, 0},  // A
//     {1, 0, 1, 0, 0, 1, 0, 0},  // B
//     {1, 1, 0, 1, 0, 0, 1, 0},  // C
//     {1, 0, 1, 0, 1, 0, 1, 1},  // D
//     {1, 0, 0, 1, 0, 0, 0, 1},  // E
//     {0, 1, 0, 0, 0, 0, 1, 0},  // F
//     {0, 0, 1, 1, 0, 1, 0, 1},  // G
//     {0, 0, 0, 1, 1, 0, 1, 0}  // H
// };

// c)Mutual Friends

// Here is the calculation of mutual friends for each pair of users:
// Mutual friends for each pair of users
// vector<vector<int>> mutualFriends = {
//     {3, 2, 2, 2, 2},  // A
//     {2, 2, 1, 0, 0},  // B
//     {2, 1, 3, 2, 0},  // C
//     {2, 0, 2, 4, 2},  // D
//     {2, 0, 0, 2, 2},  // E
//     {0, 1, 1, 0, 0},  // F
//     {0, 1, 2, 2, 0},  // G
//     {0, 0, 2, 2, 2}  // H
// };

// d) D. Post Display System

// The algorithm I would use to implement the post display system is called Breadth-First Search (BFS). The idea is to traverse the graph level by level, starting from the user who is scrolling their feed.

// For person F, the BFS traversal would be:

// Level 0: F
// Level 1: B, G
// Level 2: A, C, E, H
// So, person F can see the posts of users B, G, A, C, E, and H in their feed.

// Here is the C++ implementation of the BFS algorithm:
// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// vector<vector<int>> adjList = {
//     {1, 2, 3, 4},  // A
//     {0, 2, 5},  // B
//     {0, 1, 3, 6},  // C
//     {0, 2, 4, 6, 7},  // D
//     {0, 3, 7},  // E
//     {1, 6},  // F
//     {2, 3, 5, 7},  // G
//     {3, 4, 6}  // H
// };

// void bfs(int start) {
//     vector<bool> visited(8, false);
//     queue<int> q;

//     q.push(start);
//     visited[start]