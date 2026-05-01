# Linked Lists

This folder covers singly and doubly linked list operations, classic LeetCode problems, and basic stack/queue implementations using linked lists. Use this guide to review pointer manipulation patterns, reversal, merging, cycle detection, and list partitioning.

## Problems and approaches

### Additional Functions on Linked List
- File: [LinkedLists/AdditionalFunctionsOnLL.cpp](LinkedLists/AdditionalFunctionsOnLL.cpp)
- Approach used: array-to-list creation, brute reverse via stack, optimal iterative reverse.
- Note: `sortLL` is unfinished in this file.
- Better approach: for sorting, use merge sort on linked list for O(n log n) time and O(1) extra space.

### Add Two Numbers
- File: [LinkedLists/AddTwoNumbers.cpp](LinkedLists/AddTwoNumbers.cpp)
- Approach used: iterate both lists with carry; build output list.
- Time: O(n+m). Space: O(1) extra.

### Add Two Numbers II
- File: [LinkedLists/AddTwoNumbers2.cpp](LinkedLists/AddTwoNumbers2.cpp)
- Approach used: reverse both lists, add like normal, then reverse result.
- Time: O(n+m). Space: O(1) extra (excluding recursion stack).
- Better approach: use stacks instead of reversing if immutability is required.

### Doubly Linked List Operations
- File: [LinkedLists/AllFunctionsOfDoublyLL.cpp](LinkedLists/AllFunctionsOfDoublyLL.cpp)
- Approach used: basic insert/delete operations at head, tail, index; count nodes.
- Time: O(n) for indexed ops. Space: O(1).

### Singly Linked List Operations
- File: [LinkedLists/AllFunctionsOfLL.c](LinkedLists/AllFunctionsOfLL.c)
- Approach used: insert/delete at head, tail, index; count nodes.
- Time: O(n) for indexed ops. Space: O(1).

### Circular Queue (Linked List)
- File: [LinkedLists/CircularQueue.c](LinkedLists/CircularQueue.c)
- Approach used: linked list queue with circular next pointer; fixed capacity.
- Time: O(1) enqueue/dequeue. Space: O(k).

### Delete Node in a Linked List
- File: [LinkedLists/delete_ll_node.c](LinkedLists/delete_ll_node.c)
- Approach used: copy values from next nodes forward, then drop tail.
- Time: O(n). Space: O(1).
- Better approach: standard O(1) solution copies next node value and bypasses it.

### Delete Nodes That Match Values in Array
- File: [LinkedLists/delete_llnodes_that_match_with_array_elements.c](LinkedLists/delete_llnodes_that_match_with_array_elements.c)
- Approach used: for each node, scan array to find match (TLE comment).
- Time: O(n*m). Space: O(1).
- Better approach:
  - Summarize current: linear scan in array per node.
  - Improvement: store nums in hash set and delete in one pass.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | O(n*m) | O(n+m) |
| Lookup | Linear | O(1) average |

### Design Circular Deque
- File: [LinkedLists/DesignCircularDeque.c](LinkedLists/DesignCircularDeque.c)
- Approach used: circular singly linked list; front/rear pointers.
- Time: O(1) ops, but delete last walks list (O(n)).
- Better approach: use doubly linked list for O(1) delete last.

### Design Circular Queue
- File: [LinkedLists/DesignCircularQueue.c](LinkedLists/DesignCircularQueue.c)
- Approach used: circular singly linked list with front/rear.
- Time: O(1) ops. Space: O(k).

### Flatten a Multilevel Doubly Linked List
- File: [LinkedLists/FlattenLL.cpp](LinkedLists/FlattenLL.cpp)
- Approach used: DFS to splice child list into main list; find child tail each time.
- Time: O(n^2) worst-case due to tail scan. Space: O(h).
- Better approach: return tail from recursion to avoid repeated scans.

### Implementing Hash Table (Chaining)
- File: [LinkedLists/implementing_hash_table.c](LinkedLists/implementing_hash_table.c)
- Approach used: chained hash table to count frequencies.
- Time: O(n) average. Space: O(n).

### Linked List Cycle
- File: [LinkedLists/LC_LinkedListCycle.c](LinkedLists/LC_LinkedListCycle.c)
- Approach used: Floyd's slow/fast pointers.
- Time: O(n). Space: O(1).

### Add Two Numbers (C)
- File: [LinkedLists/LC_LL_AddTwoNums.c](LinkedLists/LC_LL_AddTwoNums.c)
- Approach used: iterate with carry, build new list.
- Time: O(n+m). Space: O(1) extra.

### Intersection of Two Linked Lists
- File: [LinkedLists/LC_LL_IntersectionNodeOfTwoLL.cpp](LinkedLists/LC_LL_IntersectionNodeOfTwoLL.cpp)
- File: [LinkedLists/LC_LL_IntersectionOfTwoLL.cpp](LinkedLists/LC_LL_IntersectionOfTwoLL.cpp)
- Approach used: nested loops compare nodes; marked as failing for some cases.
- Time: O(n*m). Space: O(1).
- Better approach:
  - Summarize current: brute force node comparisons.
  - Improvement: two-pointer switch heads; meet at intersection.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | O(n*m) | O(n+m) |
| Correctness | Fails in cases | Correct |

### Linked List Cycle II
- File: [LinkedLists/LinkedListCycle2.cpp](LinkedLists/LinkedListCycle2.cpp)
- Approach used: Floyd cycle detection; then reset slow to head to find entry.
- Time: O(n). Space: O(1).

### Merge In Between Linked Lists
- File: [LinkedLists/MergeTwoLL_1669.c](LinkedLists/MergeTwoLL_1669.c)
- Approach used: find node before `a` and after `b`, splice list2.
- Time: O(n+m). Space: O(1).

### Merge Two Sorted Lists
- File: [LinkedLists/MergeTwoSortedLists.cpp](LinkedLists/MergeTwoSortedLists.cpp)
- Approach used: iterative merge using pointers.
- Time: O(n+m). Space: O(1).

### Next Greater Element in Circular Array (Stack)
- File: [LinkedLists/NextGreaterElementUsingStack.c](LinkedLists/NextGreaterElementUsingStack.c)
- Approach used: custom stack and backward scan; uses extra tracking for circularity.
- Time: O(n^2) due to stack top and pop traversal in linked list.
- Better approach: array-based stack with two-pass index mod n, O(n).

### Odd Even Linked List
- File: [LinkedLists/OddEvenLL.cpp](LinkedLists/OddEvenLL.cpp)
- Approach used: split odd/even position nodes and reconnect.
- Time: O(n). Space: O(1).

### Partition List
- File: [LinkedLists/PartitionLL.cpp](LinkedLists/PartitionLL.cpp)
- Approach used: build two lists (<x and >=x) then concatenate.
- Time: O(n). Space: O(1).

### Queue Using Linked List (C++)
- File: [LinkedLists/queue_using_ll_cpp.cpp](LinkedLists/queue_using_ll_cpp.cpp)
- Approach used: linked list with front/rear pointers.
- Time: O(1) ops. Space: O(n).

### Queue Using Linked List (C)
- File: [LinkedLists/queue_using_ll.c](LinkedLists/queue_using_ll.c)
- Approach used: linked list with push at tail, pop at head.
- Time: O(n) enqueue because tail is not tracked; dequeue O(1).
- Better approach: keep tail pointer for O(1) enqueue.

### Linked List Random Node
- File: [LinkedLists/RandomNodeOfLL.cpp](LinkedLists/RandomNodeOfLL.cpp)
- Approach used: count length, pick random index, then traverse to it.
- Time: O(n) per call. Space: O(1).
- Better approach: reservoir sampling for single-pass selection.

### Remove Nodes Greater on Right
- File: [LinkedLists/remove_nodes_greater_on_right_IMP.c](LinkedLists/remove_nodes_greater_on_right_IMP.c)
- Approach used: reverse list, keep max so far, delete smaller, reverse back.
- Time: O(n). Space: O(1).

### Remove Duplicates from Sorted List II
- File: [LinkedLists/RemoveDuplicates.cpp](LinkedLists/RemoveDuplicates.cpp)
- Approach used: dummy head and skip duplicate runs.
- Time: O(n). Space: O(1).

### Remove Nodes From Linked List
- File: [LinkedLists/RemoveNodesFromLL.cpp](LinkedLists/RemoveNodesFromLL.cpp)
- Approach used: reverse, delete nodes less than max-so-far, reverse back.
- Time: O(n). Space: O(1).

### Reorder List
- File: [LinkedLists/ReorderLL.cpp](LinkedLists/ReorderLL.cpp)
- Approach used: split at middle, reverse second half, weave.
- Time: O(n). Space: O(1) extra.

### Reverse Linked List II
- File: [LinkedLists/ReverseLL2.cpp](LinkedLists/ReverseLL2.cpp)
- Approach used: isolate sublist, reverse, and reconnect.
- Time: O(n). Space: O(1) extra.
- Better approach: in-place reversal with one pass using pointer manipulation.

### Reverse Nodes in Even Length Groups
- File: [LinkedLists/ReverseNodesInEvenLengths.cpp](LinkedLists/ReverseNodesInEvenLengths.cpp)
- Approach used: group sizing and sublist reversals; marked inefficient.
- Time: O(n^2) worst-case. Space: O(1) extra.
- Better approach: one pass to measure group sizes, reverse in-place when size even.

### Reverse Nodes in k-Group
- File: [LinkedLists/ReverseNodesInKGroup.cpp](LinkedLists/ReverseNodesInKGroup.cpp)
- Approach used: count k, cut segment, reverse, reconnect.
- Time: O(n). Space: O(1) extra (recursive reverse uses stack).

### Reverse Doubly Linked List
- File: [LinkedLists/ReversingDLL.cpp](LinkedLists/ReversingDLL.cpp)
- Approach used: brute using stack, and optimal by swapping next/back.
- Time: O(n). Space: O(1) for optimal.

### Sort List
- File: [LinkedLists/SortLL.cpp](LinkedLists/SortLL.cpp)
- Approach used: multimap to sort by value (marked inefficient).
- Time: O(n log n). Space: O(n).
- Better approach: merge sort on linked list with O(1) extra space.

### Split Linked List in Parts
- File: [LinkedLists/SplitLL.cpp](LinkedLists/SplitLL.cpp)
- Approach used: compute length, split into k parts with size distribution.
- Time: O(n). Space: O(1) extra.

### Stack Using Linked List (C++)
- File: [LinkedLists/stack_using_ll_cpp.cpp](LinkedLists/stack_using_ll_cpp.cpp)
- Approach used: push/pop at head.
- Time: O(1). Space: O(n).

### Stack Using Linked List (C)
- File: [LinkedLists/stack_using_ll.c](LinkedLists/stack_using_ll.c)
- Approach used: push/pop at tail by traversal.
- Time: O(n) for push/pop. Space: O(n).
- Better approach: keep head as top for O(1) push/pop.

### Swap Nodes in Pairs
- File: [LinkedLists/SwapNodesInPairs.cpp](LinkedLists/SwapNodesInPairs.cpp)
- Approach used: iterative pointer swaps.
- Time: O(n). Space: O(1).

### Swap Nodes in Linked List
- File: [LinkedLists/SwapTwoNodes.cpp](LinkedLists/SwapTwoNodes.cpp)
- Approach used: locate kth from start and end, swap values.
- Time: O(n). Space: O(1).
