# Graphs

This folder focuses on graph traversal fundamentals (DFS/BFS), adjacency list construction, and connected components. Use this as a quick revision guide for graph search and cloning patterns.

## Problems and approaches

### Clone Graph
- File: [Graphs/CloneGraph.cpp](Graphs/CloneGraph.cpp)
- Approach used: DFS with hash map from original node to cloned node.
- Time: O(V+E). Space: O(V).

### Find if Path Exists in Graph
- File: [Graphs/FindIfPathExistsInGraph.cpp](Graphs/FindIfPathExistsInGraph.cpp)
- Approach used: build adjacency list; DFS from source with visited array.
- Time: O(V+E). Space: O(V+E).
- Better approach: iterative BFS/DFS to avoid recursion depth on large graphs.

### Number of Provinces
- File: [Graphs/NumberOfProvinces.cpp](Graphs/NumberOfProvinces.cpp)
- Approach used: DFS on adjacency matrix; count connected components.
- Time: O(n^2). Space: O(n).
- Better approach: Union-Find can be used for iterative component counting.
