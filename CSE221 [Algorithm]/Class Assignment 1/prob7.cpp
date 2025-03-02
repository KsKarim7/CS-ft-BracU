// A. DFS Tree

// Here is the DFS tree based on the given information:
//       1
//      / \
//     2   5
//    / \   \
//   3   4   6
//    \
//     7

// B. Filling up the empty rows of the table

// Here is the completed table:
//       1
//      / \
//     2   5
//    / \   \
//   3   4   6
//    \
//     7

// Parent: The parent of a node is the node from which the DFS traversal reached the current node. For example, the parent of node 2 is node 1, because the DFS traversal reached node 2 from node 1.
// Distance from Root: The distance from the root node (node 1) to each node is calculated based on the DFS traversal. For example, the distance from the root to node 3 is 2, because the DFS traversal reached node 3 from node 1 via node 2.