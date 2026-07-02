# Data Structures & Algorithms — Revision

---

## Table of Contents
1. [Big-O Notation & Complexity Analysis](#1-big-o-notation--complexity-analysis)
2. [Arrays](#2-arrays)
3. [Strings](#3-strings)
4. [Sorting Algorithms](#4-sorting-algorithms)
5. [Searching Algorithms](#5-searching-algorithms)
6. [Linked Lists](#6-linked-lists)
7. [Stack & Queue](#7-stack--queue)
8. [Trees & Binary Trees](#8-trees--binary-trees)
9. [Heaps (Priority Queues)](#9-heaps-priority-queues)
10. [Hashing](#10-hashing)
11. [Graphs](#11-graphs)
12. [Dynamic Programming](#12-dynamic-programming-dp)
13. [Greedy Algorithms](#13-greedy-algorithms)
14. [Backtracking](#14-backtracking)
15. [Trie (Prefix Tree)](#15-trie-prefix-tree)
16. [Bit Manipulation](#16-bit-manipulation)
17. [Recursion & Divide and Conquer](#17-recursion--divide-and-conquer)
18. [Advanced Data Structures](#18-advanced-data-structures)
19. [Master Complexity Cheat Sheet](#19-master-complexity-cheat-sheet)
20. [Problem-Solving Framework & Tips](#20-problem-solving-framework--tips)

---

## 1. Big-O Notation & Complexity Analysis

Big-O notation describes the **worst-case growth rate** of an algorithm as input size `n` approaches infinity. It tells you how time or memory scales — not the exact count, but the order of magnitude.

### Complexity Hierarchy (Fastest → Slowest)

| Notation | Name | Example | Notes |
|---|---|---|---|
| O(1) | Constant | Array access, HashMap get | Best possible — doesn't grow with input |
| O(log n) | Logarithmic | Binary Search, Balanced BST | Halves search space each step |
| O(n) | Linear | Linear search, single loop | Grows directly with input |
| O(n log n) | Linearithmic | Merge Sort, Heap Sort | Best for comparison-based sort |
| O(n²) | Quadratic | Bubble/Insertion/Selection Sort | Nested loops — avoid for large n |
| O(n³) | Cubic | Floyd-Warshall, naive matrix mult | Triple nested loops |
| O(2ⁿ) | Exponential | Fibonacci recursion, power set | Doubles each step |
| O(n!) | Factorial | Permutations, TSP brute force | Infeasible beyond n ≈ 12 |

### Key Rules for Calculating Complexity

- **Drop constants:** O(3n) → O(n), O(n/2) → O(n)
- **Drop lower order terms:** O(n² + n) → O(n²)
- **Sequential steps ADD:** O(n) + O(m) = O(n + m)
- **Nested steps MULTIPLY:** O(n) inside O(n) = O(n²)
- **Recursive calls:** use Recurrence Relations. T(n) = 2T(n/2) + O(n) → O(n log n) by Master Theorem

### Space Complexity Notes

- **Auxiliary space:** extra space used by the algorithm (not counting input)
- Recursion uses **O(depth)** stack space — O(n) for linear recursion, O(log n) for binary recursion
- **In-place algorithm:** O(1) auxiliary space (e.g., QuickSort, Selection Sort)

---

## 2. Arrays

An array is a contiguous block of memory storing elements of the same type. It is the most fundamental data structure and the basis for most interview problems.

### Core Complexity

| Operation | Time | Notes |
|---|---|---|
| Access by index | O(1) | Direct memory address calculation |
| Search (unsorted) | O(n) | Linear scan |
| Search (sorted) | O(log n) | Binary search |
| Insert/Delete at end | O(1) amortized | Dynamic array |
| Insert/Delete at position | O(n) | Must shift elements |
| Space | O(n) | |

### Must-Know Patterns

#### Two Pointer Technique
Use two pointers to solve in O(n) what would otherwise be O(n²).

- **Opposite ends:** `left=0, right=n-1`, move towards each other. Used for: pair sum in sorted array, container with most water, trapping rainwater, palindrome check.
- **Same direction:** slow and fast pointer. Used for: remove duplicates, move zeroes, cycle detection.

#### Sliding Window
Maintains a window of elements, sliding across the array. Converts O(n²) brute force to O(n). Use when you need: subarray/substring of size k, max/min subarray sum, longest substring with condition.

- **Fixed window:** maintain window of size k — remove leftmost, add rightmost each step.
- **Variable window:** expand right pointer, shrink left when condition is violated.

#### Prefix Sum
Build `prefix[i] = sum of arr[0..i]`. Range sum query `[l..r] = prefix[r] - prefix[l-1]` in O(1). Use for: range queries, count subarrays with given sum (combine with HashMap), 2D grid problems.

#### Kadane's Algorithm — Maximum Subarray Sum
Track current subarray sum. If it goes negative, reset to 0 (or current element). **Time: O(n), Space: O(1).** Key insight: a negative prefix can never help the max subarray, so discard it.

### Important Array Problems

| Problem | Pattern | Time | Space |
|---|---|---|---|
| Two Sum | HashMap / Two Pointer (sorted) | O(n) | O(n) |
| Three Sum | Sort + Two Pointer | O(n²) | O(1) |
| Maximum Subarray (Kadane) | DP / Greedy | O(n) | O(1) |
| Trapping Rainwater | Two Pointer / Prefix Max | O(n) | O(1) |
| Product of Array Except Self | Prefix & Suffix Product | O(n) | O(1) |
| Next Permutation | Array manipulation | O(n) | O(1) |
| Merge Intervals | Sort + Greedy | O(n log n) | O(n) |
| Rotate Matrix 90° | Transpose + Reverse | O(n²) | O(1) |
| Set Matrix Zeroes | Use first row/col as flags | O(n×m) | O(1) |
| Pascal's Triangle | Build row by row | O(n²) | O(n²) |

---

## 3. Strings

Strings are arrays of characters. In Java/Python they are **immutable**, making in-place modification O(n). Most array techniques (two pointer, sliding window, prefix) apply directly.

### Key Complexity Facts

| Operation | Time | Notes |
|---|---|---|
| String comparison | O(min(m,n)) | Character by character |
| Concatenation (Java) | O(n) | Creates new string — use StringBuilder |
| Hashing a string | O(n) | |
| Sorting characters | O(n log n) | |

### Critical Patterns

#### Anagram Check
Sort both strings → O(n log n), or use a frequency array of size 26 → O(n). Two strings are anagrams if they have identical character frequencies.

#### Sliding Window on Strings
Longest substring without repeating characters — expand window with right pointer, shrink from left when duplicate found. Use HashSet or frequency map. **O(n) time, O(alphabet) space.**

#### KMP Algorithm (Knuth-Morris-Pratt)
Pattern matching in O(n+m). Builds a **failure function (LPS array)** — Longest Proper Prefix which is also a Suffix. Uses this to skip re-comparing matched characters. **Time: O(n+m), Space: O(m).** Key interview topic.

#### Rabin-Karp (Rolling Hash)
Compute hash of pattern, slide window of same length over text, compare hashes. **Average O(n+m), Worst O(nm).**

### Important String Problems

| Problem | Approach | Time |
|---|---|---|
| Longest Substring No Repeat | Sliding Window + HashSet | O(n) |
| Valid Anagram | Frequency array | O(n) |
| Group Anagrams | Sort key or frequency tuple in HashMap | O(n·k log k) |
| Longest Palindromic Substring | Expand around center / DP | O(n²) |
| Minimum Window Substring | Sliding Window + 2 maps | O(n+m) |
| Palindrome Partitioning | Backtracking + DP | O(n·2ⁿ) |
| String to Integer (atoi) | Edge case handling | O(n) |

---

## 4. Sorting Algorithms

Sorting is foundational. Comparison-based sorting has a **lower bound of O(n log n)** by the comparison tree argument.

### Time & Space Complexity

| Algorithm | Best | Average | Worst | Space | Stable? | In-place? |
|---|---|---|---|---|---|---|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No | Yes |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes | No |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | No | Yes |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | No | Yes |
| Counting Sort | O(n+k) | O(n+k) | O(n+k) | O(k) | Yes | No |
| Radix Sort | O(nk) | O(nk) | O(nk) | O(n+k) | Yes | No |
| Tim Sort | O(n) | O(n log n) | O(n log n) | O(n) | Yes | No |

### Key Insights

**Merge Sort:** Divide array in half recursively, merge sorted halves. Guaranteed O(n log n). Preferred when stability matters. Recurrence: `T(n) = 2T(n/2) + O(n) → O(n log n)` by Master Theorem.

**Quick Sort:** Pick pivot, partition so left < pivot < right, recurse. Average O(n log n) with random pivot. Worst case O(n²) on already-sorted array with bad pivot. Best practical sort due to cache performance.

**Heap Sort:** Build max-heap O(n), then repeatedly extract max O(log n). Guaranteed O(n log n) in-place but poor cache performance.

**Counting Sort:** Only for integers with limited range k. Not comparison-based — beats O(n log n) lower bound.

> **Interview tip:** Prefer QuickSort for general average-case, MergeSort for stability or linked lists, Counting/Radix for integers with known range.

---

## 5. Searching Algorithms

### Linear Search
Scan every element. **O(n) time, O(1) space.** Works on unsorted arrays.

### Binary Search
Works only on **sorted arrays**. Repeatedly halve the search space. **O(log n) time, O(1) space (iterative).**

**Classic template:** `lo=0, hi=n-1`. While `lo<=hi`: `mid = lo + (hi-lo)/2` (avoids overflow). If `arr[mid]==target` return mid. If `arr[mid]<target`, `lo=mid+1`. Else `hi=mid-1`.

### Binary Search on Answer (Most Important Variant)
When the answer has a **monotonic property** — if x works, x-1 also works (or vice versa) — binary search on the answer space, not the array. Used for: minimum/maximum problems, allocating books, painter's partition, capacity to ship packages.

### Binary Search Problem Table

| Problem | Type | Time |
|---|---|---|
| Find element in sorted array | Classic | O(log n) |
| First and last position | Lower/upper bound | O(log n) |
| Search in rotated sorted array | Find pivot + binary search | O(log n) |
| Find minimum in rotated array | Modified BS | O(log n) |
| Sqrt(x) | BS on answer | O(log x) |
| Koko Eating Bananas | BS on speed range | O(n log m) |
| Allocate Minimum Pages | BS on answer | O(n log(sum)) |
| Median of two sorted arrays | BS on partition | O(log(min(m,n))) |

---

## 6. Linked Lists

A sequence of nodes where each node contains data and a pointer to the next node. **No random access** — must traverse from head.

### Types

- **Singly Linked List:** each node → next node
- **Doubly Linked List:** each node ↔ prev and next. Allows O(1) deletion given node pointer
- **Circular Linked List:** last node points back to head

### Complexity

| Operation | Time | Notes |
|---|---|---|
| Access by index | O(n) | No random access |
| Search | O(n) | |
| Insert at head | O(1) | |
| Insert at tail | O(1) with tail pointer, else O(n) | |
| Insert at position | O(n) | |
| Delete head | O(1) | |
| Delete arbitrary node | O(n) | O(1) with pointer in doubly LL |
| Space | O(n) | |

### Floyd's Cycle Detection (Tortoise & Hare)
Slow pointer moves 1 step, fast pointer moves 2 steps. If cycle exists, they will meet. If fast reaches null, no cycle. **Time: O(n), Space: O(1).** To find cycle start: after meeting, reset one pointer to head and move both 1 step — they meet at cycle start.

### Important Linked List Problems

| Problem | Key Technique | Time | Space |
|---|---|---|---|
| Reverse Linked List | Iterative: prev/curr pointers | O(n) | O(1) |
| Detect Cycle | Floyd's algorithm | O(n) | O(1) |
| Find Cycle Start | Floyd's + reset pointer | O(n) | O(1) |
| Middle of Linked List | Slow/fast pointer | O(n) | O(1) |
| Merge Two Sorted Lists | Two-pointer merge | O(n+m) | O(1) |
| Merge K Sorted Lists | Min-Heap or divide & conquer | O(n log k) | O(k) |
| Reorder List | Find mid + reverse + merge | O(n) | O(1) |
| LRU Cache | HashMap + Doubly Linked List | O(1) all ops | O(capacity) |
| Copy List with Random Pointer | HashMap or interleaving | O(n) | O(n)/O(1) |
| Add Two Numbers | Simulate addition with carry | O(max(m,n)) | O(max(m,n)) |

---

## 7. Stack & Queue

### Stack (LIFO — Last In, First Out)
All core operations are **O(1):** push, pop, peek, isEmpty. Space: O(n).

#### Classic Stack Applications
- Balanced parentheses / bracket matching
- Next Greater Element (monotonic stack)
- Previous Smaller Element
- Largest rectangle in histogram — monotonic stack O(n)
- Evaluate postfix/prefix expressions
- MinStack — use auxiliary stack to track minimums
- DFS implementation (explicit stack)

#### Monotonic Stack — Key Pattern
Maintain a stack that is always increasing or decreasing. Pop elements that violate the monotonic property. Used for: Next Greater/Smaller Element, Stock Span Problem, Largest Rectangle in Histogram, Trapping Rainwater. **Time: O(n) — each element pushed and popped at most once.**

### Queue (FIFO — First In, First Out)
All core operations are **O(1):** enqueue, dequeue, peek, isEmpty.

#### Queue Variants

| Variant | Description |
|---|---|
| Circular Queue | Fixed size, use modular arithmetic for wrap-around |
| Deque (Double-ended) | Insert/delete from both ends O(1). Used for sliding window maximum |
| Priority Queue (Heap) | Insert O(log n), extract min/max O(log n), peek O(1) |

#### Sliding Window Maximum — Deque Trick
Maintain a deque of indices. For each new element, remove from back all indices whose values are smaller (they can never be max). Remove from front if index is out of window. Deque front always has current window max. **O(n) total.**

### Stack & Queue Problem Table

| Problem | Technique | Time |
|---|---|---|
| Valid Parentheses | Stack push/pop | O(n) |
| Min Stack | Auxiliary min-stack | O(1) all ops |
| Next Greater Element | Monotonic stack | O(n) |
| Largest Rectangle in Histogram | Monotonic stack | O(n) |
| Sliding Window Maximum | Deque | O(n) |
| BFS shortest path | Queue | O(V+E) |
| Top K Frequent Elements | Min-Heap of size k | O(n log k) |
| Kth Largest Element | Min-Heap size k or QuickSelect | O(n log k) |

---

## 8. Trees & Binary Trees

A tree is a hierarchical data structure with a root node and subtrees. Most interviews focus on Binary Trees (≤2 children) and Binary Search Trees.

### Key Terminology
- **Height:** longest path from root to leaf
- **Depth:** distance from root to node
- **Full Binary Tree:** every node has 0 or 2 children
- **Complete Binary Tree:** all levels full except last, last filled left to right
- **Perfect Binary Tree:** all internal nodes have 2 children, all leaves at same level
- **Balanced Binary Tree:** height difference of left/right subtrees ≤ 1 for all nodes

### Tree Traversals — All O(n) Time, O(h) Space

| Traversal | Order | Use Case |
|---|---|---|
| Inorder (DFS) | Left → Root → Right | BST gives sorted order |
| Preorder (DFS) | Root → Left → Right | Copy tree, serialize |
| Postorder (DFS) | Left → Right → Root | Delete tree, evaluate expressions |
| Level Order (BFS) | Level by level using Queue | Shortest path, connect levels |
| Vertical Order | BFS + column index tracking | Print by column |
| Zigzag Level Order | Alternate direction each level | Common interview variant |

### Binary Search Tree (BST)
Left subtree values < root < right subtree values. Inorder traversal gives sorted sequence.

| Operation | Balanced BST | Unbalanced (Worst) |
|---|---|---|
| Search | O(log n) | O(n) |
| Insert | O(log n) | O(n) |
| Delete | O(log n) | O(n) |
| Min/Max | O(log n) | O(n) |

Balanced BSTs (AVL, Red-Black) guarantee O(log n). A plain BST can degrade to O(n) on sorted input.

### Important Tree Problems

| Problem | Approach | Time | Space |
|---|---|---|---|
| Height of Binary Tree | DFS: 1 + max(left, right) | O(n) | O(h) |
| Diameter of Binary Tree | DFS: track max(left_h + right_h) | O(n) | O(h) |
| Balanced Binary Tree | DFS: return -1 if imbalanced | O(n) | O(h) |
| Same Tree | DFS: compare each node | O(n) | O(h) |
| Invert Binary Tree | DFS: swap left & right children | O(n) | O(h) |
| Max Path Sum | DFS: track global max | O(n) | O(h) |
| LCA (Lowest Common Ancestor) | DFS: return node if found | O(n) | O(h) |
| Serialize/Deserialize | BFS or DFS with markers | O(n) | O(n) |
| Validate BST | Inorder or min/max bounds | O(n) | O(h) |
| Kth Smallest in BST | Inorder traversal, count k | O(n) | O(h) |
| Right Side View | BFS: track last node each level | O(n) | O(n) |

---

## 9. Heaps (Priority Queues)

A heap is a **complete binary tree** satisfying the heap property. **Min-heap:** parent ≤ children (root is minimum). **Max-heap:** parent ≥ children (root is maximum). Stored as array: for index `i`, left child = `2i+1`, right child = `2i+2`, parent = `(i-1)/2`.

### Complexity

| Operation | Time |
|---|---|
| Insert (push) | O(log n) |
| Extract min/max (pop) | O(log n) |
| Peek min/max | O(1) |
| Build heap from array | O(n) |
| Delete arbitrary | O(log n) |
| Space | O(n) |

> **Why Build Heap is O(n), not O(n log n)?** Heapify starts from the last internal node upward. Most nodes are near the bottom and do minimal work. The sum of work at each level is a geometric series converging to O(n).

### Key Heap Applications
- **K Largest/Smallest Elements** — Min-heap of size k: O(n log k)
- **Top K Frequent Elements** — Max-heap or min-heap of size k
- **Merge K Sorted Lists** — Min-heap with one element from each list: O(n log k)
- **Dijkstra's Algorithm** — Min-heap for greedy shortest path
- **Median of Data Stream** — Two heaps (see below)

### Median of Data Stream — Classic Dual-Heap
Maintain two heaps: a **max-heap for the smaller half** and a **min-heap for the larger half**. Balance so sizes differ by at most 1. For odd total: the heap with extra element has the median. For even: average of both tops. **Add: O(log n), Find median: O(1).**

---

## 10. Hashing

A hash table maps keys to values using a hash function. Goal is near O(1) average time for insert, delete, and search.

### Complexity

| Operation | Average | Worst |
|---|---|---|
| Search | O(1) | O(n) |
| Insert | O(1) | O(n) |
| Delete | O(1) | O(n) |
| Space | O(n) | O(n) |

Worst case O(n) occurs when many keys collide to the same bucket.

### Collision Handling
- **Chaining:** each bucket is a linked list. Simple to implement.
- **Open Addressing:** find next open slot. Linear probing, quadratic probing, double hashing. Better cache performance.

### HashMap vs HashSet vs TreeMap

| Structure | Ordering | Operations | Use Case |
|---|---|---|---|
| HashMap | None | O(1) avg | Key-value mapping, frequency count |
| HashSet | None | O(1) avg | Membership check, remove duplicates |
| TreeMap | Sorted by key | O(log n) | When order matters, range queries |
| LinkedHashMap | Insertion order | O(1) avg | LRU Cache |

### Important Hashing Problems

| Problem | Approach |
|---|---|
| Two Sum | For each x, check if (target-x) exists in HashMap |
| Longest Consecutive Sequence | HashSet: only start chain if x-1 not in set → O(n) |
| Group Anagrams | HashMap with sorted string as key |
| Subarray Sum Equals K | Prefix sum + HashMap of prefix sum counts |
| Contains Duplicate within K | Sliding window HashSet |
| Valid Sudoku | 3 HashSets (rows, cols, boxes) |

---

## 11. Graphs

A graph G = (V, E) consists of vertices (V) and edges (E). Trees and linked lists are special cases of graphs.

### Graph Representations

| Representation | Space | Edge Check | Get Neighbors | Best For |
|---|---|---|---|---|
| Adjacency Matrix | O(V²) | O(1) | O(V) | Dense graphs |
| Adjacency List | O(V+E) | O(degree) | O(degree) | Sparse graphs (most problems) |
| Edge List | O(E) | O(E) | O(E) | Kruskal's MST |

### BFS — Breadth First Search
Explores nodes **level by level** using a Queue. **Time: O(V+E), Space: O(V).**

- Finds shortest path in **unweighted** graphs (guaranteed)
- Level-order traversal
- Check bipartiteness (2-coloring)
- Multi-source BFS: put all sources in queue initially (e.g., 0/1 matrix, rotting oranges)

### DFS — Depth First Search
Explores as **deep as possible** before backtracking. Uses Stack (explicit or recursion). **Time: O(V+E), Space: O(V).**

- Detect cycle in directed/undirected graph
- Topological sort
- Find connected components
- Flood fill, number of islands

### Topological Sort
Linear ordering of vertices such that for every directed edge u→v, u comes before v. **Only for DAGs (Directed Acyclic Graphs).**

**Kahn's Algorithm (BFS):** Compute in-degrees. Add all 0 in-degree nodes to queue. Process queue: reduce neighbors' in-degree, add to queue if 0. **O(V+E).** If queue empties before all nodes processed → cycle exists.

**DFS-based:** After exploring all neighbors, push current node to stack. Reverse of stack is topological order. **O(V+E).**

### Shortest Path Algorithms

| Algorithm | Graph Type | Time | Handles Negative? |
|---|---|---|---|
| BFS | Unweighted | O(V+E) | N/A |
| Dijkstra's | Non-negative weights | O((V+E) log V) | No |
| Bellman-Ford | General (1 source) | O(VE) | Yes (detects neg cycle) |
| Floyd-Warshall | All pairs | O(V³) | Yes (no neg cycle) |
| 0-1 BFS | Weights 0 or 1 only | O(V+E) | N/A |

### Minimum Spanning Tree (MST)

**Kruskal's:** Sort edges by weight, add edge if it doesn't form a cycle (use Union-Find). **O(E log E).** Best for sparse graphs.

**Prim's:** Greedy — grow MST from source, always pick minimum weight edge to unvisited node using min-heap. **O(E log V).** Best for dense graphs.

### Union-Find (Disjoint Set Union — DSU)
Tracks connected components. Two operations: **Find** (which component?) and **Union** (merge components).

- With **path compression + union by rank:** nearly O(1) amortized (inverse Ackermann — O(α(n)))
- Used in: Kruskal's MST, detecting cycles, number of connected components

### Important Graph Problems

| Problem | Algorithm | Time |
|---|---|---|
| Number of Islands | BFS/DFS flood fill | O(m×n) |
| Rotting Oranges | Multi-source BFS | O(m×n) |
| Course Schedule (cycle detection) | Topological sort / DFS | O(V+E) |
| Cheapest Flights Within K Stops | Modified Bellman-Ford | O(K·E) |
| Network Delay Time | Dijkstra | O((V+E) log V) |
| Clone Graph | DFS/BFS + HashMap | O(V+E) |
| Word Ladder | BFS on word graph | O(M²·N) |
| Alien Dictionary | Topological sort | O(total chars) |

---

## 12. Dynamic Programming (DP)

DP solves problems by breaking them into **overlapping subproblems** and storing results to avoid recomputation. Two conditions must hold:
1. **Optimal Substructure** — optimal solution built from optimal sub-solutions
2. **Overlapping Subproblems** — same subproblems solved multiple times

### Two Approaches

**Top-Down (Memoization):** Write recursive solution, cache results in a map/array. More intuitive, uses system stack.

**Bottom-Up (Tabulation):** Fill DP table iteratively from base cases. Usually more space-efficient, avoids stack overflow.

### 1D DP Problems

| Problem | Recurrence | Time | Space → Optimized |
|---|---|---|---|
| Fibonacci | dp[i] = dp[i-1] + dp[i-2] | O(n) | O(n) → O(1) |
| Climbing Stairs | dp[i] = dp[i-1] + dp[i-2] | O(n) | O(n) → O(1) |
| House Robber | dp[i] = max(dp[i-1], dp[i-2]+arr[i]) | O(n) | O(n) → O(1) |
| Min Cost Climbing Stairs | dp[i] = cost[i]+min(dp[i-1],dp[i-2]) | O(n) | O(n) → O(1) |
| Jump Game (can reach end?) | Greedy: track max reach | O(n) | O(1) |
| Decode Ways | dp[i] = sum of valid previous states | O(n) | O(n) → O(1) |

### 2D DP Problems

| Problem | Recurrence | Time | Space |
|---|---|---|---|
| Unique Paths | dp[i][j] = dp[i-1][j] + dp[i][j-1] | O(m×n) | O(m×n) → O(n) |
| Minimum Path Sum | dp[i][j] = grid[i][j]+min(up,left) | O(m×n) | O(m×n) → O(n) |
| Longest Common Subsequence | dp[i][j] based on match/no match | O(m×n) | O(m×n) → O(n) |
| Edit Distance | dp[i][j] = min(insert,delete,replace) | O(m×n) | O(m×n) → O(n) |
| 0/1 Knapsack | dp[i][w] = max(include, exclude) | O(n×W) | O(n×W) → O(W) |
| Coin Change | dp[i] = min coins to make amount i | O(n×amount) | O(amount) |
| Longest Palindromic Subsequence | dp[i][j] for each substring | O(n²) | O(n²) |

### DP Pattern Categories (Striver's Sheet)

- **Knapsack variants:** 0/1 Knapsack, Unbounded Knapsack, Fractional (Greedy), Subset Sum, Partition Equal Subset Sum
- **LCS-based:** LCS itself, Longest Common Substring, Shortest Common Supersequence, Edit Distance
- **MCM / Interval DP:** Burst Balloons, Palindrome Partitioning, Matrix Chain Multiplication
- **DP on Trees:** Diameter, Max path sum, House Robber on tree
- **DP on Strings:** Regex matching, Wildcard matching, Interleaving strings
- **DP on Grids:** Minimum path sum, Unique paths, Maximal square of 1s, Cherry pickup

> **Key Insight:** Always define the state clearly first. Ask: what does dp[i] (or dp[i][j]) represent? Then define the transition. Then identify base cases.

---

## 13. Greedy Algorithms

Make locally optimal choices at each step hoping to reach global optimum. Unlike DP, greedy doesn't reconsider past choices. Greedy works when the problem has the **Greedy Choice Property** and **Optimal Substructure**.

### Classic Greedy Problems

| Problem | Greedy Choice | Time |
|---|---|---|
| Activity Selection | Pick activity that finishes earliest | O(n log n) |
| Fractional Knapsack | Pick highest value/weight ratio first | O(n log n) |
| Huffman Encoding | Merge two lowest frequency nodes first | O(n log n) |
| Jump Game II (min jumps) | Always jump to reach farthest next position | O(n) |
| Gas Station | If total gas ≥ total cost, solution exists | O(n) |
| Assign Cookies | Sort both; give smallest sufficient cookie | O(n log n) |
| Job Sequencing with Deadlines | Sort by profit; assign latest possible slot | O(n log n) |
| Minimum Platforms | Sort arrivals/departures; sweep line | O(n log n) |
| Merge Intervals | Sort by start; merge overlapping | O(n log n) |

> **Greedy vs DP:** If greedy works, it's simpler and faster. Try to prove correctness by exchange argument. If you can find a counterexample, use DP. 0/1 Knapsack needs DP; Fractional Knapsack uses Greedy.

---

## 14. Backtracking

Backtracking is a systematic way to try all possibilities by building a solution incrementally and abandoning a path as soon as it's determined to be invalid. Think of it as **DFS on a decision tree.**

**General Template:** Choose → Explore → Unchoose (backtrack). Always undo your choice after the recursive call to restore state.

**Complexity:** Usually exponential — O(kⁿ) or O(n!) depending on problem. Pruning cuts branches early.

### Classic Backtracking Problems

| Problem | State Space | Pruning |
|---|---|---|
| Subsets / Power Set | 2ⁿ subsets | None needed |
| Permutations | n! orderings | Skip used elements |
| Combinations (nCr) | nCr combos | Start from i+1 to avoid duplicates |
| N-Queens | n! placements | Check row, col, diagonals |
| Sudoku Solver | 9^81 worst case | Valid number check |
| Word Search | 4^(m×n) | Mark visited, unmark on backtrack |
| Palindrome Partitioning | 2ⁿ | Check palindrome before recursing |
| Letter Combinations Phone | 4ⁿ | Map digit to letters |

---

## 15. Trie (Prefix Tree)

A trie is a tree-like structure for storing strings where each path from root to a node represents a string prefix. Each node has up to 26 children (for lowercase English). Extremely efficient for prefix-related operations.

### Complexity

| Operation | Time | Space |
|---|---|---|
| Insert word | O(m) | O(m) |
| Search word | O(m) | O(1) |
| Search prefix | O(m) | O(1) |
| Delete word | O(m) | O(1) |

`m = length of the word`

Total space: **O(ALPHABET_SIZE × m × n)** where n = number of words.

### Key Applications
- Autocomplete / typeahead search
- Spell checker
- IP routing (prefix matching)
- Word Break problem
- Maximum XOR of two numbers (Binary Trie storing bit representations)

---

## 16. Bit Manipulation

Operates directly on binary representations. **O(1) time and space** for all operations.

### Essential Bit Operations

| Operation | Syntax | Description |
|---|---|---|
| AND | `a & b` | 1 only if both bits are 1 |
| OR | `a \| b` | 1 if either bit is 1 |
| XOR | `a ^ b` | 1 if bits are different |
| NOT | `~a` | Flip all bits |
| Left Shift | `a << k` | Multiply by 2^k |
| Right Shift | `a >> k` | Divide by 2^k |
| Check bit i | `(a >> i) & 1` | Is the ith bit set? |
| Set bit i | `a \| (1 << i)` | Force ith bit to 1 |
| Clear bit i | `a & ~(1 << i)` | Force ith bit to 0 |
| Toggle bit i | `a ^ (1 << i)` | Flip ith bit |
| Clear lowest set bit | `a & (a-1)` | Used in counting set bits |
| Isolate lowest set bit | `a & (-a)` | |
| Check power of 2 | `a > 0 && (a & (a-1)) == 0` | Only one bit is set |

### Classic Bit Problems

- **Count set bits (Brian Kernighan):** repeatedly do `n = n & (n-1)` until n=0. Count iterations. O(set bits).
- **XOR trick:** `a^a=0`, `a^0=a`. Single non-duplicate in array: XOR all elements → O(n), O(1).
- **Two non-duplicates in array:** XOR all → XOR of two different numbers. Find rightmost set bit, partition array by this bit, XOR each group separately.
- **Subset enumeration:** iterate mask from 0 to `(1<<n)-1`. Each mask represents a subset. O(2ⁿ).

---

## 17. Recursion & Divide and Conquer

### Key Concepts
- Every recursive solution has a **base case** and a **recursive case**
- Stack depth = O(recursion depth). Deep recursion can cause stack overflow
- **Tail recursion:** recursive call is the last operation (can be optimized to iteration)
- Memoization converts exponential recursion to polynomial DP

### Master Theorem for Recurrences
`T(n) = aT(n/b) + O(n^d)` where `a` = subproblems, `b` = size reduction factor, `d` = work per level.

| Condition | Result | Example |
|---|---|---|
| d > log_b(a) | O(n^d) | — |
| d = log_b(a) | O(n^d × log n) | Merge Sort: T(n)=2T(n/2)+O(n) → O(n log n) |
| d < log_b(a) | O(n^log_b(a)) | Binary Search: T(n)=T(n/2)+O(1) → O(log n) |

### Divide and Conquer
- Divide problem into subproblems, solve each, combine results
- Examples: Merge Sort, Quick Sort, Binary Search
- Closest pair of points: O(n log n) with D&C
- Strassen's matrix multiplication: O(n^2.81)

---

## 18. Advanced Data Structures

### Segment Tree
A binary tree where each node stores info about a range of an array. Supports range queries and point updates. **Space: O(4n).**

| Operation | Time |
|---|---|
| Build | O(n) |
| Range query (sum, min, max) | O(log n) |
| Point update | O(log n) |
| Range update (with lazy propagation) | O(log n) |

### Fenwick Tree (Binary Indexed Tree — BIT)
Simpler alternative to Segment Tree for prefix sum queries and point updates.

| Operation | Time |
|---|---|
| Build | O(n log n) |
| Prefix sum query | O(log n) |
| Point update | O(log n) |
| Space | O(n) |

More cache-friendly and simpler to code than Segment Tree. Use BIT when you only need prefix sums and point updates.

### Sparse Table
For **static arrays (no updates)**. After O(n log n) preprocessing, answers range min/max queries in **O(1)** using the overlap property of powers of 2.

### LRU Cache Design
**Least Recently Used** cache. Use **Doubly Linked List + HashMap.** DLL maintains access order (most recent at head, LRU at tail). HashMap provides O(1) access to any node.

| Operation | Time |
|---|---|
| Get | O(1) — find in map, move to head |
| Put | O(1) — insert at head; if over capacity, remove tail |
| Space | O(capacity) |

---

## 19. Master Complexity Cheat Sheet

### Data Structures Summary

| Structure | Access | Search | Insert | Delete | Space |
|---|---|---|---|---|---|
| Array | O(1) | O(n) | O(n) | O(n) | O(n) |
| Linked List | O(n) | O(n) | O(1) head | O(n) | O(n) |
| Stack | O(n) | O(n) | O(1) | O(1) | O(n) |
| Queue | O(n) | O(n) | O(1) | O(1) | O(n) |
| HashMap | — | O(1) avg | O(1) avg | O(1) avg | O(n) |
| BST (balanced) | O(log n) | O(log n) | O(log n) | O(log n) | O(n) |
| Heap | O(1) top | O(n) | O(log n) | O(log n) | O(n) |
| Trie | — | O(m) | O(m) | O(m) | O(nm) |
| Segment Tree | — | O(log n) | O(log n) | O(log n) | O(n) |
| Graph (adj list) | — | O(V+E) | O(1) | O(E) | O(V+E) |

### Algorithm Complexity Summary

| Algorithm | Time | Space | Notes |
|---|---|---|---|
| Binary Search | O(log n) | O(1) | Sorted input required |
| Bubble/Selection Sort | O(n²) | O(1) | Only for tiny arrays |
| Insertion Sort | O(n²) avg, O(n) best | O(1) | Good for nearly sorted |
| Merge Sort | O(n log n) | O(n) | Stable, guaranteed |
| Quick Sort | O(n log n) avg | O(log n) | Fast in practice |
| Heap Sort | O(n log n) | O(1) | In-place |
| BFS | O(V+E) | O(V) | Shortest unweighted path |
| DFS | O(V+E) | O(V) | Cycle detection, topo sort |
| Dijkstra (heap) | O((V+E) log V) | O(V) | Non-negative weights |
| Bellman-Ford | O(VE) | O(V) | Negative edges ok |
| Floyd-Warshall | O(V³) | O(V²) | All-pairs shortest path |
| Kruskal's MST | O(E log E) | O(V) | Sparse graphs |
| Prim's MST | O(E log V) | O(V) | Dense graphs |
| Topological Sort | O(V+E) | O(V) | DAGs only |
| Knapsack 0/1 | O(nW) | O(W) | DP |
| LCS | O(mn) | O(n) | DP |
| Longest Increasing Subseq | O(n log n) | O(n) | Patience sort / BS |

---

## 20. Problem-Solving Framework & Tips

### Step-by-Step Approach
1. **Understand:** Restate the problem. Ask about constraints (n size?), edge cases (empty, negatives, duplicates?).
2. **Examples:** Walk through 2-3 examples including edge cases manually.
3. **Brute Force:** State the naive solution first. Shows you understand the problem.
4. **Optimize:** Identify bottleneck. Ask: can I use sorting? Hashing? Two pointers? DP? Precomputation?
5. **Pseudocode:** Outline the approach before coding.
6. **Code:** Write clean code with good variable names.
7. **Test:** Trace through with examples. Check edge cases.
8. **Complexity:** State time and space complexity clearly.

### Pattern Recognition Guide

| If you see... | Think... |
|---|---|
| Sorted array + search/pair | Binary Search or Two Pointer |
| Subarray/substring optimization | Sliding Window |
| Range sum/frequency queries | Prefix Sum |
| Overlapping subproblems, optimal substructure | Dynamic Programming |
| Make local choices, order matters | Greedy — sort first |
| Try all possibilities, prune invalid | Backtracking |
| Shortest path, unweighted graph | BFS |
| Connected components, cycle detection | DFS / Union-Find |
| Shortest path, weighted non-negative | Dijkstra (min-heap) |
| K largest/smallest/frequent | Heap (priority queue) |
| Frequency count, O(1) lookup | HashMap / HashSet |
| Prefix matching, autocomplete | Trie |
| Hierarchical structure, recursion natural | Tree + DFS/BFS |
| Scheduling, intervals | Sort by end time + Greedy |
| Single element, XOR | Bit manipulation |
| Parentheses, undo operations | Stack |
| Level-order processing, min distance | Queue / BFS |

### Space Optimization Tricks
- **1D DP:** if dp[i] depends only on dp[i-1] and dp[i-2], use two variables
- **2D DP:** if dp[i][j] depends only on previous row, use 1D rolling array
- Sorting + two pointers often replaces HashSet/HashMap when order doesn't matter
- Bit masking for subset problems reduces space significantly

### Constraint → Complexity Guide

| Input Size (n) | Acceptable Complexity |
|---|---|
| n ≤ 10 | O(n!) — backtracking/permutations ok |
| n ≤ 20 | O(2ⁿ) — bitmask DP ok |
| n ≤ 500 | O(n²) — nested loops ok |
| n ≤ 10⁴ | O(n²) borderline — optimize if possible |
| n ≤ 10⁵ | O(n log n) needed |
| n ≤ 10⁶ | O(n) or O(n log n) only |
| n ≤ 10⁹ | O(log n) or O(1) only |

---

*Good luck with your assessment! 🚀*

---

## 21. Solved Problems Index

A complete quick-reference index of every problem solved in this repository, organized by topic. Click a folder header to open the full topic README with detailed notes, approach explanations, and better-approach comparison tables.

---

### 📁 [Binary Trees](BinaryTrees/README.md)

| Problem | LC # | Approach | Time | Space |
|---|---|---|---|---|
| Additional Tree Functions | — | Insert/delete/traversal | O(n) | O(h) |
| Balance a Binary Search Tree | 1382 | Inorder collect + divide build | O(n) | O(n) |
| Binary Tree Maximum Path Sum | 124 | DFS with global max | O(n) | O(h) |
| Boundary Traversal | — | Left boundary + leaves + right boundary | O(n) | O(n) |
| Construct Binary Tree from Inorder & Postorder | 106 | Recursive with hashmap | O(n) | O(n) |
| Construct Binary Tree from Inorder & Preorder | 105 | Recursive with hashmap | O(n) | O(n) |
| Construct Binary Tree from Preorder & Postorder | 889 | Recursive partition | O(n) | O(n) |
| Convert BST to Greater Sum Tree | 538 | Reverse inorder with running sum | O(n) | O(h) |
| Count Good Nodes in Binary Tree | 1448 | DFS tracking max on path | O(n) | O(h) |
| Create Binary Tree From Descriptions | 2196 | Two-pass: child set + parent map | O(n) | O(n) |
| Delete Nodes and Return Forest | 1110 | DFS, disconnect on delete | O(n) | O(n) |
| Diameter of Binary Tree | 543 | DFS returning height, track max diameter | O(n) | O(h) |
| Flatten Binary Tree to Linked List | 114 | Preorder rewire | O(n) | O(h) |
| Invert Binary Tree | 226 | DFS swap left/right | O(n) | O(h) |
| K-th Smallest Element in BST | 230 | Inorder with counter | O(n) | O(h) |
| Lowest Common Ancestor | 236 | DFS return node when found | O(n) | O(h) |
| Maximum Depth of Binary Tree | 104 | DFS: 1 + max(left, right) | O(n) | O(h) |
| Maximum Width of Binary Tree | 662 | BFS with index tracking | O(n) | O(w) |
| Merge Two Binary Trees | 617 | DFS simultaneous traversal | O(n) | O(h) |
| Morris Inorder Traversal | — | Thread predecessor, no stack | O(n) | O(1) |
| Path Sum II | 113 | DFS backtracking with path vector | O(n) | O(h) |
| Populate Next Right Pointers | 116 | BFS or O(1) level linking | O(n) | O(1) |
| Print Binary Tree | 655 | BFS with column width from height | O(n) | O(n) |
| Right Side View | 199 | BFS, take last per level | O(n) | O(w) |
| Serialize & Deserialize Binary Tree | 297 | BFS with null markers | O(n) | O(n) |
| Sum Root to Leaf Numbers | 129 | DFS with running value | O(n) | O(h) |
| Symmetric Tree | 101 | DFS mirror check | O(n) | O(h) |
| Trim a BST | 669 | DFS prune nodes outside range | O(n) | O(h) |
| Validate Binary Search Tree | 98 | DFS with min/max bounds | O(n) | O(h) |
| Vertical Order Traversal | 987 | BFS + column sorting | O(n log n) | O(n) |
| Zigzag Level Order Traversal | 103 | BFS with alternate reversal | O(n) | O(w) |

---

### 📁 [Dynamic Programming](DP/README.md)

| Problem | LC # | Approach | Time | Space |
|---|---|---|---|---|
| Best Time to Buy and Sell Stock II | 122 | Greedy collect all gains | O(n) | O(1) |
| Best Time to Buy and Sell Stock III | 123 | 3D DP + 4 rolling variables | O(n) | O(1) |
| Best Time to Buy and Sell Stock IV | 188 | 3D DP with K transactions | O(n·K) | O(n·K) |
| Best Time to Buy/Sell (Cooldown) | 309 | DP with 3 states | O(n) | O(1) |
| Best Time to Buy/Sell (Fee) | 714 | DP hold/cash states | O(n) | O(1) |
| Cherry Pickup II | 1463 | 3D DP two robots simultaneously | O(n·m²) | O(n·m²) |
| Coin Change | 322 | Bottom-up 1D DP | O(n·amount) | O(amount) |
| Coin Change II | 518 | Unbounded knapsack | O(n·amount) | O(amount) |
| Combination Sum IV | 377 | 1D DP ordered arrangements | O(n·target) | O(target) |
| Count Square Submatrices | 1277 | 2D DP min of neighbours + 1 | O(m·n) | O(1) |
| Delete Operations for Two Strings | 583 | LCS-based min deletions | O(m·n) | O(m·n) |
| Distinct Subsequences | 115 | Bottom-up 2D DP from end | O(m·n) | O(m·n) |
| Domino and Tromino Tiling | 790 | DP with 4 states per column | O(n) | O(1) |
| Frog Jump | 403 | DP with set of jump sizes per stone | O(n²) | O(n²) |
| Guess Number Higher or Lower II | 375 | Interval DP | O(n³) | O(n²) |
| House Robber | 198 | 1D DP rolling two vars | O(n) | O(1) |
| House Robber II (circle) | 213 | Two runs excluding first/last | O(n) | O(1) |
| House Robber III (tree) | 337 | Postorder DFS pair return | O(n) | O(h) |
| House Robber IV | 2560 | Binary search + greedy check | O(n log max) | O(1) |
| House Robber V | 3700 | 2D DP same-colour constraint | O(n) | O(n) |
| Integer Break | 343 | Math: max product with 3s | O(n) | O(1) |
| Interleaving String | 97 | 2D DP | O(m·n) | O(m·n) |
| Largest Divisible Subset | 368 | Sort + LIS-style + backtrack | O(n²) | O(n) |
| Last Stone Weight II | 1049 | 0/1 Knapsack partition | O(n·sum) | O(sum) |
| Longest Almost Palindromic Substring | 3844 | 2D DP palindrome + almost-pal tables | O(n²) | O(n²) |
| Longest Arithmetic Subsequence | 1027 | O(n²) DP with diff hashmaps | O(n²) | O(n²) |
| Longest Arith. Subseq. of Given Diff | 1218 | Single-pass hashmap DP | O(n) | O(n) |
| Longest Common Subsequence | 1143 | 2D DP | O(m·n) | O(m·n) |
| Longest Increasing Subsequence | 300 | Patience sort + binary search | O(n log n) | O(n) |
| Longest Palindromic Subsequence | 516 | 2D interval DP | O(n²) | O(n²) |
| Longest String Chain | 1048 | Sort by length + LIS DP | O(n²·L) | O(n) |
| Maximum Amount of Money Robot Can Earn | 3418 | 3D memoised DP with lives | O(m·n·3) | O(m·n·3) |
| Maximum Number of Items From Sale | — | O(n²) divisibility + knapsack | O(n·B) | O(n·B) |
| Maximum Number of Jumps | 2770 | 1D DP with constraint check | O(n²) | O(n) |
| Maximum Path Score in a Grid | 3742 | 3D DP dp[i][j][cost] | O(m·n·k) | O(m·n·k) |
| Maximum Product Subarray | 152 | Track max and min running product | O(n) | O(1) |
| Min Cost Climbing Stairs | 746 | 1D DP rolling two vars | O(n) | O(1) |
| Minimum Cost for Tickets | 983 | 1D DP over days | O(365) | O(365) |
| Minimum Cost to Move Between Indices | 3919 | Forward + backward DP + queries | O(n+q) | O(n) |
| Minimum Cost to Split into Ones | — | DP or closed form n(n-1)/2 | O(1) | O(1) |
| Minimum Cost Tree From Leaf Values | 1130 | Interval DP | O(n³) | O(n²) |
| Minimum Deletions to Make String Balanced | 1653 | DP or prefix B-count | O(n) | O(1) |
| Minimum Falling Path Sum | 931 | 2D DP bottom-up | O(m·n) | O(1) |
| Minimum Insertion Steps to Palindrome | 1312 | LPS-based DP | O(n²) | O(n²) |
| Minimum Path Sum | 64 | 2D DP in-place | O(m·n) | O(1) |
| Number of Dice Rolls With Target Sum | 1155 | Memoised recursion | O(n·t·k) | O(n·t) |
| Number of Longest Increasing Subseq | 673 | DP tracking length + count | O(n²) | O(n) |
| Palindrome Partitioning | 131 | Backtracking + palindrome DP | O(n·2ⁿ) | O(n²) |
| Palindrome Partitioning II | 132 | Min cuts DP + isPalin table | O(n²) | O(n²) |
| Palindrome Partitioning IV | 1745 | Check 3-part palindrome split | O(n²) | O(n²) |
| Partition Equal Subset Sum | 416 | 0/1 Knapsack bitset | O(n·sum) | O(sum) |
| Perfect Squares | 279 | DP coin change variant | O(n·√n) | O(n) |
| Profitable Schemes | 879 | 3D DP profit/crime/member | O(n·P·G) | O(P·G) |
| Rotated Digits | 788 | DP digit classification | O(n) | O(1) |
| Shortest Common Supersequence | 1092 | LCS + reconstruct | O(m·n) | O(m·n) |
| Solving Questions with Brainpower | 2140 | 1D DP backward | O(n) | O(n) |
| Super Ugly Number | 313 | K-pointer min-heap DP | O(n·k) | O(k) |
| Target Sum | 494 | 2D DP with positive/negative | O(n·sum) | O(sum) |
| Triangle | 120 | Bottom-up 1D DP | O(n²) | O(n) |
| Unique Binary Search Trees | 96 | Catalan number DP | O(n²) | O(n) |
| Unique Paths | 62 | 2D DP → 1D rolling | O(m·n) | O(n) |
| Word Break | 139 | DP with dictionary set | O(n²) | O(n) |

---

### 📁 [Graphs](Graphs/README.md)

| Problem | LC # | Approach | Time | Space |
|---|---|---|---|---|
| Clone Graph | 133 | DFS + hashmap | O(V+E) | O(V) |
| Course Schedule I (cycle) | 207 | DFS 3-state | O(V+E) | O(V) |
| Course Schedule II (topo) | 210 | DFS 3-state + stack | O(V+E) | O(V) |
| Course Schedule IV (reachability) | 1462 | Floyd-Warshall reachability | O(V²+Q) | O(V²) |
| Find City With Smallest Neighbours | 1334 | Floyd-Warshall + threshold count | O(V³) | O(V²) |
| Find if Path Exists | 1971 | DFS from source | O(V+E) | O(V+E) |
| Number of Provinces | 547 | DFS count components | O(n²) | O(n) |
| **BFS sub-folder** | | | | |
| 01-Matrix | 542 | Multi-source BFS | O(m·n) | O(m·n) |
| Is Graph Bipartite | 785 | BFS 2-colouring | O(V+E) | O(V) |
| Jump Game III | 1306 | BFS visited | O(n) | O(n) |
| Jump Game IV | 1345 | BFS + value-to-index map | O(n) | O(n) |
| Map of Highest Peak | 1765 | Multi-source BFS | O(m·n) | O(m·n) |
| Rotting Oranges | 994 | Multi-source BFS | O(m·n) | O(m·n) |
| Word Ladder | 127 | BFS character replacement | O(N·L·26) | O(N) |
| Word Ladder II | 126 | BFS parent-map + DFS reconstruct | O(N·L·26) | O(N²) |
| **DFS sub-folder** | | | | |
| Find Eventual Safe States | 802 | DFS 4-state condition | O(V+E) | O(V) |
| Island Perimeter | 463 | DFS count exposed edges | O(m·n) | O(m·n) |
| Number of Enclaves | 1020 | DFS from border | O(m·n) | O(m·n) |
| Number of Islands | 200 | DFS flood fill | O(m·n) | O(m·n) |
| Number of Ways to Assign Edge Weights | 3558 | DFS depth + 2^(depth-1) | O(V+E) | O(V) |
| Surrounded Regions | 130 | DFS from border O's | O(m·n) | O(m·n) |
| **ShortestPath sub-folder** | | | | |
| Cheapest Flights Within K Stops | 787 | Modified Dijkstra with stops | O(E·k·log(V·k)) | O(V·k) |
| Network Delay Time | 743 | Dijkstra min-heap | O((V+E) log V) | O(V+E) |
| Number of Ways to Arrive at Destination | 1976 | Dijkstra + ways[] | O((V+E) log V) | O(V+E) |
| Path With Minimum Effort | 1631 | Dijkstra on max diff | O(m·n·log(m·n)) | O(m·n) |
| Shortest Path in Binary Matrix | 1091 | BFS 8-directional | O(n²) | O(n²) |
| Shortest Path With K Consecutive Identical Chars | 3970 | Dijkstra + consecutive state | O(E·k·log(V·k)) | O(V·k) |

---

### 📁 [Linked Lists](LinkedLists/README.md)

| Problem | LC # | Approach | Time | Space |
|---|---|---|---|---|
| Add Two Numbers | 2 | Iterate with carry | O(n+m) | O(1) |
| Add Two Numbers II | 445 | Reverse + add + reverse | O(n+m) | O(1) |
| Copy List with Random Pointer | — | Interleave or HashMap | O(n) | O(1)/O(n) |
| Delete Node in a Linked List | 237 | Copy-forward trick | O(n) | O(1) |
| Delete Nodes Matching Array | 3217 | HashSet + scan | O(n+m) | O(m) |
| Design Circular Deque | 1670 | Circular singly LL | O(1)/O(n) | O(k) |
| Design Circular Queue | 622 | Circular singly LL | O(1) | O(k) |
| Flatten Multilevel Doubly LL | 430 | DFS splice | O(n²) | O(h) |
| Intersection of Two Linked Lists | 160 | Two-pointer switch heads | O(n+m) | O(1) |
| Linked List Cycle | 141 | Floyd slow/fast | O(n) | O(1) |
| Linked List Cycle II | 142 | Floyd + reset to head | O(n) | O(1) |
| Merge In Between Linked Lists | 1669 | Find a-1 and b+1, splice | O(n+m) | O(1) |
| Merge Two Sorted Lists | 21 | Iterative merge | O(n+m) | O(1) |
| Next Greater Element (circular) | — | Stack backward scan | O(n) | O(n) |
| Odd Even Linked List | 328 | Split + reconnect | O(n) | O(1) |
| Partition List | 86 | Two dummy-head lists | O(n) | O(1) |
| Random Node | 382 | Reservoir sampling | O(n) | O(1) |
| Remove Duplicates from Sorted List II | 82 | Dummy head skip runs | O(n) | O(1) |
| Remove Nodes Greater on Right | 2487 | Reverse + max filter + reverse | O(n) | O(1) |
| Remove Nodes From Linked List | — | Reverse + monotone + reverse | O(n) | O(1) |
| Reorder List | 143 | Find mid + reverse second + weave | O(n) | O(1) |
| Reverse Linked List II | 92 | Isolate sublist + reverse + reconnect | O(n) | O(1) |
| Reverse Nodes in Even Length Groups | — | Measure groups, reverse even ones | O(n²) | O(1) |
| Reverse Nodes in k-Group | 25 | Cut k-segment, reverse, reconnect | O(n) | O(1) |
| Sort List | 148 | Merge sort (multimap used, O(n) space) | O(n log n) | O(n) |
| Split Linked List in Parts | 725 | Length + split with remainder | O(n) | O(1) |
| Swap Nodes in Pairs | 24 | Iterative pointer swaps | O(n) | O(1) |
| Swap Two Nodes (by k) | 1721 | Two-pass locate, swap values | O(n) | O(1) |

---

### 📁 [Maths](Maths/README.md)

| Problem | LC # | Concept / Formula | Time | Space |
|---|---|---|---|---|
| Angle Between Clock Hands | 1344 | Hour: (h mod 12 + m/60)×30°; Minute: m×6°; take min angle | O(1) | O(1) |
| Frequency Balanced Subarray | 3960 | Freq-of-freq map; one freq = double the other | O(n²) | O(n) |
| Largest Number | 179 | Custom comparator sort: (a+b) vs (b+a) | O(n log n) | O(n) |
| Maximize Sum of Device Ratings | 3961 | Sort by max rating; assign greedily | O(m log m) | O(1) |
| Maximum Length of Pair Chain | 646 | Greedy interval scheduling (sort by end) | O(n log n) | O(1) |
| Median of Two Sorted Arrays | 4 | Binary search on partition point | O(log min(m,n)) | O(1) |
| Russian Doll Envelopes | 354 | Sort (w asc, h desc) + patience LIS | O(n log n) | O(n) |
| Strictly Palindromic Number | 2633 | Base conversion + palindrome check | O(log n) | O(1) |

---

### 📁 [Recursion](Recursion/README.md)

| Problem | LC # | Approach | Time | Space |
|---|---|---|---|---|
| Combination Sum | 39 | Backtracking with reuse | O(2ⁿ) | O(target/min) |
| Combination Sum II | 40 | Backtracking skip duplicates | O(2ⁿ) | O(n) |
| Generate Parentheses | 22 | Backtracking open/close balance | O(4ⁿ/√n) | O(n) |
| Kth Lexicographical Happy String | 1415 | Generate all then pick k | O(3·2^(n-1)) | O(output) |
| N-Queens | 51 | Column-by-column backtracking with 3 arrays | O(n!) | O(n²) |
| Permutations | 46 | Backtracking swap/restore | O(n·n!) | O(n) |
| Permutations II | 47 | Backtracking + skip duplicates | O(n·n!) | O(n) |
| Subsets | 78 | Backtracking include/exclude | O(n·2ⁿ) | O(n) |
| Subsets II | 90 | Backtracking skip duplicate sibling | O(n·2ⁿ) | O(n) |
| Valid Binary Strings With Cost Limit | 3955 | Backtracking no-consecutive-1s + cost check | O(2ⁿ) | O(n) |

---

### 📁 [Sliding Window](SlidingWindow/README.md)

| Problem | LC # | Approach | Time | Space |
|---|---|---|---|---|
| Arithmetic Slices | 413 | Nested expand (O(n²)) or single-pass O(n) | O(n²) | O(1) |
| Best Time to Buy and Sell Stock | 121 | Track min so far + max profit | O(n) | O(1) |
| Binary Subarrays With Sum | 930 | Prefix sum + hash | O(n) | O(n) |
| Count Subarrays With Fixed Bounds | 2444 | Variable window with min/max tracking | O(n) | O(1) |
| Find All Anagrams in a String | 438 | Fixed window freq map | O(n+m) | O(26) |
| Fruits Into Baskets | 904 | Variable window max 2 types | O(n) | O(1) |
| Longest Repeating Character Replacement | 424 | Variable window + max freq | O(n) | O(26) |
| Longest Subarray of 1s After Deleting One | 1493 | Variable window at most 1 zero | O(n) | O(1) |
| Longest Turbulent Window | 978 | Variable window turbulence check | O(n) | O(1) |
| Max Consecutive Ones III | 1004 | Variable window at most k zeros | O(n) | O(1) |
| Minimum Window Substring | 76 | Variable window freq map target match | O(n+m) | O(26) |
| No. of Substrings Containing All 3 Chars | 1358 | Variable window, add (n-right) | O(n) | O(1) |
| Permutation in String | 567 | Fixed window anagram check | O(n+m) | O(26) |
| Subarray Product Less Than K | 713 | Variable window product | O(n) | O(1) |

---

### 📁 [Stacks & Queues](StacksQueues/README.md)

| Problem | LC # | Approach | Time | Space |
|---|---|---|---|---|
| Asteroid Collision | 735 | Stack simulation with sign | O(n) | O(n) |
| Build Array With Stack Ops | 1441 | Simulate push/pop | O(n) | O(1) |
| Daily Temperatures | 739 | Monotonic decreasing stack | O(n) | O(n) |
| Decode String | 394 | Stack of strings | O(n·k) | O(n) |
| Evaluate Reverse Polish Notation | 150 | Operand stack | O(n) | O(n) |
| Infix to Postfix | — | Operator stack with precedence | O(n) | O(n) |
| Min Stack | 155 | Auxiliary min-stack | O(1) all | O(n) |
| Online Stock Span | 901 | Monotonic stack of (price, span) | O(n) | O(n) |
| Postfix Evaluation | — | Operand stack | O(n) | O(n) |
| Prefix to Infix | — | Stack right-to-left | O(n) | O(n) |

---

### 📁 [Mixed LeetCode Practice](Some_Leetcode/README.md)

#### Binary Search Problems

| Problem | LC # | Approach | Time | Space |
|---|---|---|---|---|
| Capacity to Ship Packages Within D Days | 1011 | Binary search on capacity | O(n log S) | O(1) |
| Find the Smallest Divisor Given a Threshold | 1283 | Binary search on divisor | O(n log max) | O(1) |
| Koko Eating Bananas | 875 | Binary search on speed | O(n log max) | O(1) |
| Minimum Number of Days to Make M Bouquets | 1482 | Binary search on days | O(n log max) | O(1) |
| Search a 2D Matrix | 74 | Nested binary search | O(log n + log m) | O(1) |
| Search a 2D Matrix II | 240 | Start top-right corner | O(n+m) | O(1) |
| Single Element in Sorted Array | 540 | Binary search on even indices | O(log n) | O(1) |
| Successful Pairs of Spells and Potions | 2300 | Binary search + postfix array | O((s+p) log p) | O(p) |
| Nth Ugly Number III | 1201 | Binary search + inclusion-exclusion | O(log 2e9) | O(1) |
| Find First and Last Position | 34 | Binary search left + right bound | O(log n) | O(1) |

#### Array / Two-Pointer Problems

| Problem | LC # | Approach | Time | Space |
|---|---|---|---|---|
| 3Sum | 15 | Sort + two pointers | O(n²) | O(1) |
| 3Sum Closest | 16 | Sort + two pointers min diff | O(n²) | O(1) |
| 4Sum | 18 | Two loops + two pointers | O(n³) | O(1) |
| 4Sum II | 454 | Hash pair sums | O(n²) | O(n²) |
| Check Array Sorted and Rotated | 1752 | Count drops ≤ 1 | O(n) | O(n) |
| Minimum Swaps to Move Zeros to End | 3936 | Two-pointer swap | O(n) | O(1) |
| Trapping Rain Water | 42 | Two-pointer running max | O(n) | O(1) |
| Majority Element II | 229 | Boyer-Moore voting | O(n) | O(1) |
| Maximum Subarray | 53 | Kadane's algorithm | O(n) | O(1) |
| Merge Intervals | 56 | Sort + greedy merge | O(n log n) | O(1) |
| Non-Overlapping Intervals | 435 | Sort by end + greedy | O(n log n) | O(1) |
| Product of Array Except Self | 238 | Prefix + suffix product | O(n) | O(1) |
| Rotate Image | 48 | Transpose + reverse rows | O(n²) | O(1) |
| Set Matrix Zeroes | 73 | First row/col as flags | O(m·n) | O(1) |
| Spiral Matrix | 54 | Boundary traversal | O(m·n) | O(1) |

#### String Problems

| Problem | LC # | Approach | Time | Space |
|---|---|---|---|---|
| Add Binary | 67 | Simulate from end with carry | O(n+m) | O(1) |
| Check If Strings Can Be Made Equal (Ops 1) | 2839 | Compare even/odd index sets | O(1) | O(1) |
| Check If Strings Can Be Made Equal (Ops 2) | 2840 | Multiset or frequency array compare | O(n log n) | O(n) |
| Decode the Slanted Ciphertext | 2075 | Diagonal traversal step cols+1 | O(n) | O(1) |
| Greatest Common Divisor of Strings | 1071 | Check concatenation equality + gcd | O(n) | O(n) |
| Process String With Special Operations | 3614 | Forward length pass + backward resolve | O(n) | O(n) |
| Sort Vowels by Frequency | 3913 | Freq count + sort by freq/pos | O(n) | O(1) |
| Shortest Palindrome | 214 | KMP LPS on s + '#' + rev(s) | O(n) | O(n) |
| Valid String With Wildcards | 678 | Range [min_open, max_open] tracking | O(n) | O(1) |
| Words Within Two Edits of Dictionary | 2452 | Brute compare | O(q·d·L) | O(1) |

#### Greedy / Math Problems

| Problem | LC # | Approach | Time | Space |
|---|---|---|---|---|
| Candy | 135 | Two-pass left/right arrays | O(n) | O(n) |
| Earliest Finish Time for Land and Water Rides I | 3633 | O(l·w) brute all orderings | O(l·w) | O(1) |
| Earliest Finish Time for Land and Water Rides II | 3635 | O(l+w) greedy best-first-ride | O(l+w) | O(1) |
| Integer to Roman | 12 | Greedy symbol table | O(1) | O(1) |
| Jump Game I | 55 | Greedy max reach | O(n) | O(1) |
| Jump Game II | 45 | BFS-level greedy | O(n) | O(1) |
| Maximum Sum of K Selected Elements | 3974 | Sort desc + multiplier | O(n log n) | O(1) |
| Minimum Energy to Maintain Brightness | 3951 | Count steps + merge intervals | O(n log n) | O(1) |
| Min Changes to Make Alternating Binary String | 1758 | Count mismatches for two patterns | O(n) | O(1) |
| Min Penalty for a Shop | 2483 | Prefix loss + single pass | O(n) | O(1) |
| Next Greater Element III | 556 | Next permutation on digits | O(d) | O(1) |
| Next Permutation | 31 | Find pivot + swap + reverse suffix | O(n) | O(1) |
| Nim Game | 292 | n % 4 != 0 | O(1) | O(1) |
| Non-Overlapping Intervals | 435 | Sort by end, greedy keep | O(n log n) | O(1) |
| Robot Collisions | 2751 | Sort by position, stack simulation | O(n log n) | O(n) |
| Total Waviness of Numbers in Range | 3751 | Sliding 3-digit window per number | O(range·log n) | O(1) |

#### Stack / Queue Problems

| Problem | LC # | Approach | Time | Space |
|---|---|---|---|---|
| Decrypt Code (Sliding Window Circular) | 1652 | Circular index loop | O(n·|k|) | O(n) |
| Robot Collisions | 2751 | Stack collision simulation | O(n log n) | O(n) |
| Sum of Subarray Minimums | 907 | Monotonic stack PSE/NSE | O(n) | O(n) |
| Sum of Subarray Ranges | 2104 | Monotonic stacks for min+max | O(n) | O(n) |
| Walking Robot Simulation | 874 | Simulate with obstacle hash set | O(n) | O(obs) |

#### Binary Search on Answer Pattern

> **Key revision note:** All these problems share the same template:
> 1. Set `lo = smallest possible answer`, `hi = largest possible answer`
> 2. Binary search: check if `mid` is feasible in O(n)
> 3. Shrink window to find minimum feasible value

| Problem | What to binary-search on | Feasibility check |
|---|---|---|
| Koko Eating Bananas | Eating speed | Sum of ceil(pile/speed) ≤ h |
| Capacity to Ship Packages | Ship capacity | Greedy pack count ≤ days |
| Minimum Days for M Bouquets | Wait days | Greedy adjacent count ≥ m·k |
| Find Smallest Divisor | Divisor value | Sum of ceil(nums[i]/div) ≤ threshold |
| Successful Pairs | Minimum potion needed | Binary search in sorted potions |

---

### 📁 [Graphs/BFS — 01-Matrix vs Multi-source BFS Pattern](Graphs/README.md)

> **Key revision note:** Whenever you need shortest distance from multiple sources simultaneously, seed ALL sources into the BFS queue at distance 0 and run one BFS. This avoids O(sources × BFS) repeated searches.

**Examples:** 01-Matrix (distance to nearest 0), Rotting Oranges (time to rot all), Map of Highest Peak (height from water cells).

---

### 🔁 Cross-Topic Revision Patterns

| Pattern | Where to look | Key technique |
|---|---|---|
| Binary search on answer | Some_Leetcode (Koko, Capacity, Bouquets, Divisor) | `lo/hi` + greedy feasibility |
| Dijkstra variants | Graphs/ShortestPath | Add extra state dimension (stops, cost) to visited array |
| 3D DP | DP (Robot Earn, Max Path Score, House Robber IV, Cherry Pickup) | Add constraint as third DP dimension |
| DFS from border → flip interior | Graphs/DFS (Surrounded Regions, Number of Enclaves) | Mark border-connected first, then flip remaining |
| Interval scheduling greedy | Maths (Pair Chain), Some_Leetcode (Non-overlapping, Candy) | Sort by end time, greedily keep earliest-ending |
| Monotonic stack | StacksQueues, Some_Leetcode (Subarray Min/Max) | Each element pushed/popped once → O(n) |
| Patience sort LIS | DP (LIS, Russian Doll Envelopes) | `lower_bound` on active sequence → O(n log n) |
| Parent-map BFS for all shortest paths | Graphs/BFS (Word Ladder II) | BFS builds parent map, DFS reconstructs all paths |

---

*Good luck with your assessment! 🚀*
