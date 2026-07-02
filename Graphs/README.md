# Graphs

This folder focuses on graph traversal fundamentals (DFS/BFS), adjacency list construction, topological sort, and shortest-path algorithms. Use this as a quick revision guide for graph search, cloning patterns, bipartite checking, and Dijkstra variants.

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

### Jump Game III
- File: [Graphs/BFS/JumpGame3.cpp](Graphs/BFS/JumpGame3.cpp)
- Approach used: BFS with visited array; explore all reachable indices by allowed jumps.
- Time: O(n). Space: O(n).

### Jump Game IV
- File: [Graphs/BFS/JumpGame4.cpp](Graphs/BFS/JumpGame4.cpp)
- Approach used: BFS level-by-level; map values to indices for same-value jumps; clear map after processing each level to avoid revisits.
- Time: O(n). Space: O(n).
- Better approach: instead of revisiting same-value indices, precompute and clear adjacency to O(n) total.

### Course Schedule IV
- File: [Graphs/CourseSchedule4.cpp](Graphs/CourseSchedule4.cpp)
- Approach used: build reachability using Floyd-Warshall-style BFS; for each query `[u, v]`, answer true if u can reach v.
- Time: O(V^2 + Q). Space: O(V^2).

### Find the City With the Smallest Number of Neighbours at a Threshold Distance
- File: [Graphs/FindTheCityWithTheSmallestNumberOfNeighboursAtAThresholdDistance.cpp](Graphs/FindTheCityWithTheSmallestNumberOfNeighboursAtAThresholdDistance.cpp)
- Approach used: Floyd-Warshall all-pairs shortest paths; for each city count cities reachable within threshold; pick the city with fewest reachable cities, breaking ties by highest city number.
- Time: O(V^3). Space: O(V^2).

---

## BFS sub-folder

### 01-Matrix (Distance to Nearest Zero)
- File: [Graphs/BFS/01-Matrix.cpp](Graphs/BFS/01-Matrix.cpp)
- Approach used: multi-source BFS starting from all 0 cells simultaneously; visit unvisited cells and assign distance = previous distance + 1.
- Time: O(m*n). Space: O(m*n).

### Is Graph Bipartite
- File: [Graphs/BFS/IsGraphBipartite.cpp](Graphs/BFS/IsGraphBipartite.cpp)
- Approach used: BFS 2-colouring; colour each node alternately; if two adjacent nodes share the same colour, return false.
- Time: O(V+E). Space: O(V).

### Map of Highest Peak
- File: [Graphs/BFS/MapOfHighestPeak.cpp](Graphs/BFS/MapOfHighestPeak.cpp)
- Approach used: identical to 01-Matrix — multi-source BFS from all water cells (value 1); assign `height[cell] = height[parent] + 1`.
- Time: O(m*n). Space: O(m*n).
- Note: file comment links this as a simplification of 01-Matrix.

### Rotting Oranges
- File: [Graphs/BFS/RottingOranges.cpp](Graphs/BFS/RottingOranges.cpp)
- Approach used: multi-source BFS from all rotten oranges; spread rot with time counter; check if fresh oranges remain. File includes both an initial approach and a cleaner BFS using direction arrays.
- Time: O(m*n). Space: O(m*n).
- Better approach: use direction arrays instead of four separate boundary checks.

| Aspect | Initial approach | Better approach |
| --- | --- | --- |
| Clarity | Manual 4-directional checks | Direction array loop |
| Boundary safety | Checks before push | Checks in loop condition |

### Word Ladder
- File: [Graphs/BFS/WordLadder.cpp](Graphs/BFS/WordLadder.cpp)
- Approach used: BFS; for each word, try replacing each character with 'a'–'z'; if result in word set, enqueue with step+1; erase used words to avoid cycles.
- Time: O(N * L * 26). Space: O(N).

### Word Ladder II (All Shortest Paths)
- File: [Graphs/BFS/WordLadder2.cpp](Graphs/BFS/WordLadder2.cpp)
- Approach used: two implementations — (1) Memory-efficient: BFS with parent map + levels, then DFS to reconstruct all paths. (2) Memory-expensive: BFS storing full path vectors in queue.
- Time: O(N * L * 26 + paths). Space: O(N^2) worst case.
- Better approach (included): parent-map + level approach uses significantly less memory than storing full path copies.

| Aspect | Path-vector BFS | Parent-map + DFS |
| --- | --- | --- |
| Space | O(N * path_length) | O(N + paths) |
| Clarity | Simple but heavy | More complex, lighter |

---

## DFS sub-folder

### Course Schedule (Cycle Detection)
- File: [Graphs/DFS/CourseSchedule.cpp](Graphs/DFS/CourseSchedule.cpp)
- Approach used: DFS with three states — 0 (unvisited), 1 (in stack), 2 (fully processed); if a node in stack is revisited, a cycle exists.
- Time: O(V+E). Space: O(V).

### Course Schedule II (Topological Order)
- File: [Graphs/DFS/CourseSchedule2.cpp](Graphs/DFS/CourseSchedule2.cpp)
- Approach used: same three-state DFS; push to stack when all neighbours done; reverse stack gives topological order; return empty if cycle detected.
- Time: O(V+E). Space: O(V).

### Find Eventual Safe States
- File: [Graphs/DFS/FindEventualSafeStates.cpp](Graphs/DFS/FindEventualSafeStates.cpp)
- Approach used: DFS with four states — (-1: not explored), (1: in progress), (0: unsafe / cycle), (2: safe); a node is safe if all its neighbours are safe.
- Time: O(V+E). Space: O(V).

### Island Perimeter
- File: [Graphs/DFS/IslandPerimeter.cpp](Graphs/DFS/IslandPerimeter.cpp)
- Approach used: DFS from the first land cell; mark visited with -1; each DFS call counts exposed edges (out-of-bounds or water neighbour contributes 1).
- Time: O(m*n). Space: O(m*n) recursion.
- Better approach: count land cells and shared edges directly in O(1) extra space.

### Number of Enclaves
- File: [Graphs/DFS/NumberOfEnclaves.cpp](Graphs/DFS/NumberOfEnclaves.cpp)
- Approach used: DFS from all border land cells, marking them 0; remaining 1s are enclaves — count them.
- Time: O(m*n). Space: O(m*n) recursion.

### Number of Islands
- File: [Graphs/DFS/NumberOfIslands.cpp](Graphs/DFS/NumberOfIslands.cpp)
- Approach used: DFS flood fill — when a '1' is found, increment count and DFS mark all connected '1's as '0' to avoid revisiting.
- Time: O(m*n). Space: O(m*n) recursion.

### Number of Ways to Assign Edge Weights
- File: [Graphs/DFS/NumberOfWaysToAssignEdgeWeights1.cpp](Graphs/DFS/NumberOfWaysToAssignEdgeWeights1.cpp)
- Approach used: DFS from node 1 computing the depth of all nodes; the answer is `2^(max_depth - 1)` modulo 1e9+7, because only edges at odd depths can independently be assigned weight 1 or 2.
- Time: O(V+E). Space: O(V).

### Surrounded Regions
- File: [Graphs/DFS/SurroundedRegions.cpp](Graphs/DFS/SurroundedRegions.cpp)
- Approach used: DFS from all border 'O' cells, marking them '.'; then flip all remaining 'O' to 'X' and all '.' back to 'O'.
- Time: O(m*n). Space: O(m*n) recursion.

---

## ShortestPath sub-folder

### Cheapest Flights Within K Stops
- File: [Graphs/ShortestPath/CheapestFlightsWithinKStops.cpp](Graphs/ShortestPath/CheapestFlightsWithinKStops.cpp)
- Approach used: modified Dijkstra with a 2D visited matrix `visited[stops][node]`; priority queue ordered by cost; skip if stops > k+1.
- Time: O(E * k * log(V*k)). Space: O(V*k).
- Better approach: Bellman-Ford relaxed exactly k+1 times is cleaner for this problem.

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Algorithm | Modified Dijkstra | Bellman-Ford (k iterations) |
| Space | O(V*k) visited table | O(V) distance array |

### Network Delay Time
- File: [Graphs/ShortestPath/NetworkDelayTime.cpp](Graphs/ShortestPath/NetworkDelayTime.cpp)
- Approach used: Dijkstra's algorithm from source node; min-heap `{dist, node}`; find maximum of all shortest distances; return -1 if any node unreachable.
- Time: O((V+E) log V). Space: O(V+E).

### Number of Ways to Arrive at Destination
- File: [Graphs/ShortestPath/NumberOfWaysToArriveAtDestination.cpp](Graphs/ShortestPath/NumberOfWaysToArriveAtDestination.cpp)
- Approach used: Dijkstra with an extra `ways[]` array; when a shorter path is found, update ways = parent ways; when equal path found, add parent ways; answer is `ways[n-1]`.
- Time: O((V+E) log V). Space: O(V+E).

### Path With Minimum Effort
- File: [Graphs/ShortestPath/PathWithMinimumEffort.cpp](Graphs/ShortestPath/PathWithMinimumEffort.cpp)
- Approach used: modified Dijkstra where edge weight = absolute height difference; `v[x][y]` = minimum maximum effort to reach (x,y); min-heap ordered by effort.
- Time: O(m*n * log(m*n)). Space: O(m*n).

### Shortest Path in Binary Matrix
- File: [Graphs/ShortestPath/ShortestPathInBinaryMatrix.cpp](Graphs/ShortestPath/ShortestPathInBinaryMatrix.cpp)
- Approach used: BFS from top-left; 8-directional movement; mark visited by setting cell to 1; return dist when reaching bottom-right.
- Time: O(n^2). Space: O(n^2).

### Shortest Path With At Most K Consecutive Identical Characters
- File: [Graphs/ShortestPath/ShortestPathWithAtMostKConsecutiveIdenticalCharacters.cpp](Graphs/ShortestPath/ShortestPathWithAtMostKConsecutiveIdenticalCharacters.cpp)
- Approach used: Dijkstra with state `{dist, node, consecutive_count}`; skip transitions where consecutive same-label count exceeds k; 2D visited `visited[node][count]`.
- Time: O(E * k * log(V*k)). Space: O(V*k).

