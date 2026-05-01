# Binary Trees

This folder focuses on binary tree and BST fundamentals: traversals, construction from traversals, structural transforms, path-based queries, and classic property checks. Use this as a compact revision guide for patterns like DFS with returned state, BFS level processing, and BST-specific pruning.

## Problems and approaches

### Average of Levels in Binary Tree
- File: [BinaryTrees/AverageLevelOrderTrav.cpp](BinaryTrees/AverageLevelOrderTrav.cpp)
- Approach used: BFS level order, store each level in a vector, compute sum for average.
- Time: O(n). Space: O(w) for queue plus O(w) per level vector.
- Better approach:
  - Summarize current: uses per-level vector of values.
  - Improvement: compute running sum and count per level without storing values.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Extra storage | Level vector | No level vector |
| Implementation | Simple | Simpler and less memory |

### Balance a BST
- File: [BinaryTrees/BalanceA_BST.cpp](BinaryTrees/BalanceA_BST.cpp)
- Approach used: inorder traversal to collect nodes, rebuild balanced BST via mid.
- Time: O(n). Space: O(n) for node list + recursion.

### Balanced Binary Tree
- File: [BinaryTrees/BalancedBinaryTree.cpp](BinaryTrees/BalancedBinaryTree.cpp)
- Approach used: postorder height computation; global flag for imbalance.
- Time: O(n). Space: O(h).
- Better approach:
  - Summarize current: uses global flag and still computes full height.
  - Improvement: return -1 on imbalance to short-circuit.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Early exit | No | Yes (return -1) |
| Work on unbalanced tree | Full | Partial |

### Binary Tree Pruning
- File: [BinaryTrees/BinaryTreePruning.cpp](BinaryTrees/BinaryTreePruning.cpp)
- Approach used: postorder prune; remove leaf 0 nodes after pruning children.
- Time: O(n). Space: O(h).

### Binary Tree Tilt
- File: [BinaryTrees/BinaryTreeTilt.cpp](BinaryTrees/BinaryTreeTilt.cpp)
- Approach used: postorder sums; accumulate absolute difference.
- Time: O(n). Space: O(h).

### Flatten Binary Tree to Linked List (custom)
- File: [BinaryTrees/BinTreeToLL.c](BinaryTrees/BinTreeToLL.c)
- Approach used: DFS that creates a new linked list by visiting leaves.
- Time: O(n). Space: O(h) recursion + O(n) new list.
- Better approach:
  - Summarize current: builds a new list; only adds leaves.
  - Improvement: if goal is full preorder flattening, rewire tree in-place using recursion or stack.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Output | New list (leaves only) | In-place full flatten |
| Space | O(n) extra | O(h) or O(1) |

### Evaluate Boolean Binary Tree
- File: [BinaryTrees/BooleanBinaryTree.cpp](BinaryTrees/BooleanBinaryTree.cpp)
- Approach used: postorder list then stack evaluation.
- Time: O(n). Space: O(n).
- Better approach:
  - Summarize current: uses postorder array plus stack.
  - Improvement: evaluate recursively and return boolean at each node.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Extra storage | O(n) array | O(h) recursion |
| Simplicity | Two-phase | Single DFS |

### Binary Tree Maximum Path Sum
- File: [BinaryTrees/BTMaxPathSum.cpp](BinaryTrees/BTMaxPathSum.cpp)
- Approach used: DFS returns max gain; update global max with left+right+node.
- Time: O(n). Space: O(h).

### Closest Nodes Queries in BST
- File: [BinaryTrees/ClosedNodesQueriesInBST.cpp](BinaryTrees/ClosedNodesQueriesInBST.cpp)
- Approach used: inorder to sorted list, then binary search per query.
- Time: O(n + q log n). Space: O(n).

### Construct Binary Tree from Inorder and Postorder
- File: [BinaryTrees/ConstructBTfromInorderAndPostorder.cpp](BinaryTrees/ConstructBTfromInorderAndPostorder.cpp)
- Approach used: hashmap of inorder indices; recurse using postorder index from end.
- Time: O(n). Space: O(n).

### Construct Binary Tree from Preorder and Inorder
- File: [BinaryTrees/ConstructBTfromInorderAndPreorder.cpp](BinaryTrees/ConstructBTfromInorderAndPreorder.cpp)
- Approach used: scans inorder to find next root positions; passes full vectors.
- Time: O(n^2). Space: O(h) recursion.
- Better approach:
  - Summarize current: linear scan per recursion for inorder index.
  - Improvement: build hashmap of inorder index and pass index ranges.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | O(n^2) | O(n) |
| Lookup | Linear scan | O(1) map |

### Construct String from Binary Tree
- File: [BinaryTrees/ConstructTreeFromBT.cpp](BinaryTrees/ConstructTreeFromBT.cpp)
- Approach used: DFS; include empty parentheses for missing left when right exists.
- Time: O(n). Space: O(h).

### Convert BST to Greater Tree
- File: [BinaryTrees/ConvertBSTtoGreaterTree.cpp](BinaryTrees/ConvertBSTtoGreaterTree.cpp)
- Approach used: reverse inorder with running sum.
- Time: O(n). Space: O(h).

### Count Complete Tree Nodes
- File: [BinaryTrees/CountCompleteTreeNodes.cpp](BinaryTrees/CountCompleteTreeNodes.cpp)
- Approach used: compare left and right heights; if equal, compute perfect count.
- Time: O(log^2 n). Space: O(h).

### Count Good Nodes in Binary Tree
- File: [BinaryTrees/CountGoodNodesInBT.cpp](BinaryTrees/CountGoodNodesInBT.cpp)
- Approach used: DFS with max-so-far value.
- Time: O(n). Space: O(h).

### Deepest Leaves Sum
- File: [BinaryTrees/DeepestLeavesSum.cpp](BinaryTrees/DeepestLeavesSum.cpp)
- Approach used: BFS store all levels then sum last.
- Time: O(n). Space: O(n).
- Better approach:
  - Summarize current: stores all levels before summing.
  - Improvement: track sum at current level only, overwrite per level.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Extra storage | O(n) levels | O(w) queue only |
| Simplicity | Two passes | Single BFS |

### Delete Leaves With a Given Value
- File: [BinaryTrees/DeleteBTLeaves.cpp](BinaryTrees/DeleteBTLeaves.cpp)
- Approach used: postorder prune when node becomes target leaf.
- Time: O(n). Space: O(h).

### Delete Nodes and Return Forest
- File: [BinaryTrees/DeleteNodesAndReturnForest.cpp](BinaryTrees/DeleteNodesAndReturnForest.cpp)
- Approach used: postorder; if node deleted, push non-null children to forest set.
- Time: O(n). Space: O(n) for set + O(h).

### Diameter of Binary Tree
- File: [BinaryTrees/DiameterOfBT.cpp](BinaryTrees/DiameterOfBT.cpp)
- Approach used: DFS returns height; update global diameter.
- Time: O(n). Space: O(h).

### Even Odd Tree
- File: [BinaryTrees/EvenOddTree.cpp](BinaryTrees/EvenOddTree.cpp)
- Approach used: BFS per level, then sort to validate ordering and parity.
- Time: O(n log n) across levels. Space: O(n).
- Better approach:
  - Summarize current: sorts each level to compare order.
  - Improvement: single pass per level with prev value tracking, no sort.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | O(n log n) | O(n) |
| Validation | Sort + compare | One pass with prev |

### Find Bottom Left Tree Value
- File: [BinaryTrees/FindBottomLeftTreeValue.cpp](BinaryTrees/FindBottomLeftTreeValue.cpp)
- Approach used: DFS preorder, track deepest level and value.
- Time: O(n). Space: O(h).

### Kth Smallest Element in a BST
- File: [BinaryTrees/KthSmallestInBST.cpp](BinaryTrees/KthSmallestInBST.cpp)
- Approach used: inorder traversal with k decrement.
- Time: O(h + k). Space: O(h).

### Zigzag Level Order Traversal
- File: [BinaryTrees/LevelOrderTrav.cpp](BinaryTrees/LevelOrderTrav.cpp)
- Approach used: BFS with level reversal on odd levels.
- Time: O(n). Space: O(w).

### Longest Univalue Path
- File: [BinaryTrees/LongestUnivaluePath.cpp](BinaryTrees/LongestUnivaluePath.cpp)
- Approach used: DFS returns longest same-value chain; update global with left+right.
- Time: O(n). Space: O(h).

### Maximum Depth of Binary Tree
- File: [BinaryTrees/MaxDepth.c](BinaryTrees/MaxDepth.c)
- Approach used: collect depths into dynamic array then take max.
- Time: O(n). Space: O(n).
- Better approach:
  - Summarize current: stores all leaf depths.
  - Improvement: simple recursion returning 1 + max(left, right).
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Extra storage | O(n) array | O(h) recursion |
| Simplicity | Multi-step | Direct |

### Maximum Binary Tree
- File: [BinaryTrees/Maximum_Binary_Tree.cpp](BinaryTrees/Maximum_Binary_Tree.cpp)
- Approach used: recursion scanning range for max each time.
- Time: O(n^2) worst-case. Space: O(h).
- Better approach:
  - Summarize current: linear scan per subtree.
  - Improvement: monotonic stack to build in O(n).
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | O(n^2) | O(n) |
| Technique | Divide and scan | Stack |

### Maximum Width of Binary Tree
- File: [BinaryTrees/MaximumWidthOfBT.cpp](BinaryTrees/MaximumWidthOfBT.cpp)
- Approach used: BFS with positional indices and normalization per level.
- Time: O(n). Space: O(w).

### Minimum Absolute Difference in BST
- File: [BinaryTrees/Min_Absolute_Diff_in_BST.cpp](BinaryTrees/Min_Absolute_Diff_in_BST.cpp)
- Approach used: inorder to sorted list then compute min diff.
- Time: O(n). Space: O(n).
- Better approach:
  - Summarize current: stores all values.
  - Improvement: track previous value during inorder, compute diff on the fly.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Extra storage | O(n) list | O(1) extra |
| Passes | Two | One |

### Path Sum
- File: [BinaryTrees/PathSum.cpp](BinaryTrees/PathSum.cpp)
- Approach used: DFS collects all root-to-leaf sums into vector, then search.
- Time: O(n). Space: O(n) for sums.
- Better approach:
  - Summarize current: stores all path sums.
  - Improvement: DFS with running sum and early return when found.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Extra storage | O(n) sums | O(h) recursion |
| Early stop | No | Yes |

### Path Sum II
- File: [BinaryTrees/PathSum2.cpp](BinaryTrees/PathSum2.cpp)
- Approach used: DFS with path vector copied along recursion.
- Time: O(n^2) in worst case due to copying. Space: O(n).
- Better approach:
  - Summarize current: passes path vector by value per call.
  - Improvement: pass by reference with push/pop backtracking.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | Higher due to copies | O(n) path updates |
| Space | More allocations | O(h) path |

### Path Sum III
- File: [BinaryTrees/PathSum3.cpp](BinaryTrees/PathSum3.cpp)
- Approach used: DFS with path vector and suffix sum scan per node.
- Time: O(n^2) worst-case. Space: O(h).
- Better approach:
  - Summarize current: scans path from node to root each time.
  - Improvement: prefix-sum hashmap to count sums in O(n).
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | O(n^2) | O(n) |
| Technique | Path scan | Prefix sum map |

### Populating Next Right Pointers in Each Node
- File: [BinaryTrees/PopulatingNextRightPointers.cpp](BinaryTrees/PopulatingNextRightPointers.cpp)
- Approach used: BFS per level and link next pointers.
- Time: O(n). Space: O(w).
- Better approach:
  - Summarize current: uses queue for levels.
  - Improvement: use existing next pointers for O(1) space on perfect trees.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Space | O(w) | O(1) |
| Assumption | Any tree | Perfect tree |

### Range Sum of BST
- File: [BinaryTrees/RangeSumOfBST.cpp](BinaryTrees/RangeSumOfBST.cpp)
- Approach used: DFS with BST pruning.
- Time: O(n) worst-case. Space: O(h).

### Recover Binary Search Tree
- File: [BinaryTrees/RecoverBST.cpp](BinaryTrees/RecoverBST.cpp)
- Approach used: inorder traversal; detect two swapped nodes; swap values.
- Time: O(n). Space: O(h).

### Second Minimum Node In a Binary Tree
- File: [BinaryTrees/SecondMinElement.cpp](BinaryTrees/SecondMinElement.cpp)
- Approach used: BFS collect all values, remove min, take smallest of rest.
- Time: O(n). Space: O(n).
- Better approach:
  - Summarize current: collects all values then filters.
  - Improvement: DFS that returns smallest candidate greater than root.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Extra storage | O(n) list | O(h) recursion |
| Strategy | Collect all | Prune with value constraints |

### Subtree of Another Tree
- File: [BinaryTrees/SubtreeOfAnotherTree.cpp](BinaryTrees/SubtreeOfAnotherTree.cpp)
- Approach used: DFS scan; compare subtree with full equality check.
- Time: O(n*m) worst-case. Space: O(h).
- Better approach:
  - Summarize current: compare at each candidate node.
  - Improvement: serialize trees and use substring search or use hashing.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | O(n*m) | Near O(n+m) |
| Technique | Repeated DFS | Hashing/serialization |

### Sum Root to Leaf Numbers
- File: [BinaryTrees/SumRootOfLeafNumbers.cpp](BinaryTrees/SumRootOfLeafNumbers.cpp)
- Approach used: DFS collect numbers then sum.
- Time: O(n). Space: O(n) for list.
- Better approach:
  - Summarize current: stores all numbers before summing.
  - Improvement: accumulate sum during DFS; return total.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Extra storage | O(n) list | O(h) recursion |
| Passes | Two | One |

### Symmetric Tree
- File: [BinaryTrees/symmetric.c](BinaryTrees/symmetric.c)
- Approach used: recursive mirror check.
- Time: O(n). Space: O(h).

### Trim a BST
- File: [BinaryTrees/TrimBST.cpp](BinaryTrees/TrimBST.cpp)
- Approach used: recurse to find valid root, then prune left/right ranges.
- Time: O(n). Space: O(h).
- Better approach:
  - Summarize current: multiple helper calls and checks.
  - Improvement: single DFS that returns trimmed subtree using BST rules.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Complexity | Multiple helpers | One recursion |
| Readability | Moderate | Simpler |

### Zigzag Level Order Traversal
- File: [BinaryTrees/ZigzagLevelOrderTrav.cpp](BinaryTrees/ZigzagLevelOrderTrav.cpp)
- Approach used: BFS with reversal on odd levels.
- Time: O(n). Space: O(w).
