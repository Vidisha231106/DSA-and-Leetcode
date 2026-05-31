# Mixed LeetCode Practice

This folder is a grab bag of arrays, strings, intervals, stacks, math, and tree/graph problems. Use this as a quick revision guide, with notes on faster alternatives when your solution is marked inefficient or incorrect.

## Problems and approaches

### 3Sum
- File: [Some_Leetcode/3sum.cpp](Some_Leetcode/3sum.cpp)
- Approach used: sort + two pointers for each fixed i, skip duplicates.
- Time: O(n^2). Space: O(1) extra.

### 3Sum Closest
- File: [Some_Leetcode/3sumClosest.cpp](Some_Leetcode/3sumClosest.cpp)
- Approach used: sort + two pointers to minimize diff.
- Time: O(n^2). Space: O(1).

### 4Sum
- File: [Some_Leetcode/4sum.cpp](Some_Leetcode/4sum.cpp)
- Approach used: two loops + two pointers, skip duplicates.
- Time: O(n^3). Space: O(1).

### 4Sum II
- File: [Some_Leetcode/4sum2.cpp](Some_Leetcode/4sum2.cpp)
- Approach used: hash counts of pair sums for two arrays, match complements.
- Time: O(n^2). Space: O(n^2).

### Add Binary
- File: [Some_Leetcode/AddBinary.cpp](Some_Leetcode/AddBinary.cpp)
- Approach used: simulate addition from the end with carry.
- Time: O(n+m). Space: O(1) extra.

### Candy
- File: [Some_Leetcode/Candy.cpp](Some_Leetcode/Candy.cpp)
- Approach used: two passes (left and right arrays) and take max.
- Time: O(n). Space: O(n).
- Better approach:
  - Summarize current: uses left/right arrays.
  - Improvement: single-pass slope counting to do O(1) space.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Space | O(n) | O(1) |
| Strategy | Two arrays | Slope tracking |

### Check if Strings Can Be Made Equal (Ops 1)
- File: [Some_Leetcode/CheckIfStringsCanBeMadeEqualWithOperations1.cpp](Some_Leetcode/CheckIfStringsCanBeMadeEqualWithOperations1.cpp)
- Approach used: compare sets of even indices and odd indices.
- Time: O(1) (fixed length). Space: O(1).

### Check if Strings Can Be Made Equal (Ops 2)
- File: [Some_Leetcode/CheckIfStringsCanBeMadeEqualWithOperations2.cpp](Some_Leetcode/CheckIfStringsCanBeMadeEqualWithOperations2.cpp)
- Approach used: multiset compare for even and odd positions; better solution included.
- Better approach:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Data structure | multiset | frequency array |
| Time | O(n log n) | O(n) |

### Check if Array Is Sorted and Rotated
- File: [Some_Leetcode/CheckSortedArray.cpp](Some_Leetcode/CheckSortedArray.cpp)
- Approach used: extend array by rotation and validate.
- Time: O(n). Space: O(n) extra due to push_back.
- Better approach: count number of drops in one pass; valid if drops <= 1.

### Closest Equal Element Queries
- File: [Some_Leetcode/ClosestEqualElementQueries.cpp](Some_Leetcode/ClosestEqualElementQueries.cpp)
- Approach used: map value -> set of positions, use lower/upper bound.
- Time: O((n+q) log n). Space: O(n).

### Complement of Base 10 Integer
- File: [Some_Leetcode/ComplementOfABase10Integer.cpp](Some_Leetcode/ComplementOfABase10Integer.cpp)
- Approach used: binary string conversion, flip bits.
- Time: O(log n). Space: O(log n).
- Better approach: build mask and use XOR: ans = (~n) & mask.

### Construct Uniform Parity Array
- File: [Some_Leetcode/ConstructUniformParityArray2.cpp](Some_Leetcode/ConstructUniformParityArray2.cpp)
- Approach used: track min of odd/even and check feasibility.
- Time: O(n). Space: O(1).

### Count Commas in Range
- File: [Some_Leetcode/CountCommasInRange2.cpp](Some_Leetcode/CountCommasInRange2.cpp)
- Approach used: count digits and sum contributions by powers of 1000.
- Time: O(log n). Space: O(1).

### Count Partitions With Even Sum
- File: [Some_Leetcode/CountPartitionsWithEvenSum.cpp](Some_Leetcode/CountPartitionsWithEvenSum.cpp)
- Approach used: prefix parity counting; returns count of split points.
- Time: O(n). Space: O(1).

### Decode the Slanted Ciphertext
- File: [Some_Leetcode/DecodeTheSlantedCipherText.cpp](Some_Leetcode/DecodeTheSlantedCipherText.cpp)
- Approach used: diagonal traversal by column with step cols+1; trim trailing spaces.
- Time: O(n). Space: O(1) extra.

### Find First and Last Position in Sorted Array
- File: [Some_Leetcode/FindFirstAndLastPositionOfElementInSortedArray.cpp](Some_Leetcode/FindFirstAndLastPositionOfElementInSortedArray.cpp)
- Approach used: binary search for left then right boundary.
- Time: O(log n). Space: O(1).

### Find the Smallest Balanced Index
- File: [Some_Leetcode/FindTheSmallestBalancedIndex.cpp](Some_Leetcode/FindTheSmallestBalancedIndex.cpp)
- Approach used: product from right, sum from left; stop on overflow.
- Time: O(n). Space: O(1).

### Find Unique Binary String
- File: [Some_Leetcode/FindUniqueBinaryString.cpp](Some_Leetcode/FindUniqueBinaryString.cpp)
- Approach used: convert all to decimal, mark used, return first missing.
- Time: O(n*2^n). Space: O(2^n).
- Better approach:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Strategy | Mark all strings | Cantor diagonal | 
| Time | Exponential | O(n) |
| Space | O(2^n) | O(1) |

### First Element With Unique Frequency
- File: [Some_Leetcode/FirstElementWithUniqueFrequency.cpp](Some_Leetcode/FirstElementWithUniqueFrequency.cpp)
- Approach used: map value->freq, map freq->count, scan first unique.
- Time: O(n). Space: O(n).

### Flatten Binary Tree to Linked List
- File: [Some_Leetcode/flatten_binary_tree.c](Some_Leetcode/flatten_binary_tree.c)
- Approach used: preorder rewire using dummy head pointer.
- Time: O(n). Space: O(h).

### Greatest Common Divisor of Strings
- File: [Some_Leetcode/GreatestCommonDivisorOfStrings.cpp](Some_Leetcode/GreatestCommonDivisorOfStrings.cpp)
- Approach used: brute gcd of lengths by divisor scan and verify repeats.
- Time: O(n^2) worst-case. Space: O(1).
- Better approach: compute gcd(len1,len2) and check str1+str2 == str2+str1.

### Insert Interval
- File: [Some_Leetcode/InsertInterval.cpp](Some_Leetcode/InsertInterval.cpp)
- Approach used: add intervals before, merge overlaps, append rest.
- Time: O(n). Space: O(1) extra.

### Integers With Multiple Sum of Two Cubes
- File: [Some_Leetcode/IntegersWithMultipleSumOfTwoCubes.cpp](Some_Leetcode/IntegersWithMultipleSumOfTwoCubes.cpp)
- Approach used: precompute cubes and count sum pairs.
- Time: O(n^(2/3)) pairs. Space: O(n^(2/3)).

### Integer to Roman
- File: [Some_Leetcode/IntergerToRoman.cpp](Some_Leetcode/IntergerToRoman.cpp)
- Approach used: greedy over symbol values.
- Time: O(1). Space: O(1).

### Jump Game (empty)
- File: [Some_Leetcode/JumpGame.cpp](Some_Leetcode/JumpGame.cpp)
- Note: file is empty.

### Jump Game I
- File: [Some_Leetcode/JumpGame1.cpp](Some_Leetcode/JumpGame1.cpp)
- Approach used: greedy max reach.
- Time: O(n). Space: O(1).

### Jump Game II
- File: [Some_Leetcode/JumpGame2.cpp](Some_Leetcode/JumpGame2.cpp)
- Approach used: BFS-level style greedy range expansion.
- Time: O(n). Space: O(1).

### Keys and Rooms
- File: [Some_Leetcode/KeysAndRooms.cpp](Some_Leetcode/KeysAndRooms.cpp)
- Approach used: DFS with stack; shows inefficient map vs vector.
- Better approach:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Visited | unordered_map | vector<bool> |
| Overhead | Higher | Lower |

### Leaf-Similar Trees
- File: [Some_Leetcode/leaf-similar-trees.c](Some_Leetcode/leaf-similar-trees.c)
- Approach used: collect leaf sequences into arrays and compare.
- Time: O(n). Space: O(n).

### Majority Element II
- File: [Some_Leetcode/MajorityElement2.cpp](Some_Leetcode/MajorityElement2.cpp)
- Approach used: brute frequency map; better Boyer-Moore included.
- Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | O(n) | O(n) |
| Space | O(n) | O(1) |

### Maximum Subarray
- File: [Some_Leetcode/MaximumSubarray.cpp](Some_Leetcode/MaximumSubarray.cpp)
- Approach used: O(n^2) and Kadane O(n).
- Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | O(n^2) | O(n) |
| Technique | Nested loops | Kadane |

### Merge Intervals
- File: [Some_Leetcode/MergeIntervals.cpp](Some_Leetcode/MergeIntervals.cpp)
- Approach used: sort by start and merge.
- Time: O(n log n). Space: O(1) extra.

### Min Changes to Make Alternating Binary String
- File: [Some_Leetcode/MinChangesToMakeAlternatingBinaryString.cpp](Some_Leetcode/MinChangesToMakeAlternatingBinaryString.cpp)
- Approach used: count mismatches for start with 0 and start with 1.
- Time: O(n). Space: O(1).

### Minimum Operations to Make a Uni-Value Grid
- File: [Some_Leetcode/MinimumOperationsToMakeAUniValueGrid.cpp](Some_Leetcode/MinimumOperationsToMakeAUniValueGrid.cpp)
- Approach used: flatten, median via nth_element, check divisibility by x.
- Time: O(n). Space: O(n).

### Min Moves to Balance Circular Array
- File: [Some_Leetcode/MinMovesToBalanceCircularArray.cpp](Some_Leetcode/MinMovesToBalanceCircularArray.cpp)
- Approach used: TLE then corrected greedy using expanding distance.
- Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Status | TLE | Corrected |
| Movement | 1-by-1 | Batch transfer |

### Min Penalty for a Shop
- File: [Some_Leetcode/MinPenaltyForAShop.cpp](Some_Leetcode/MinPenaltyForAShop.cpp)
- Approach used: compute losses; improved single pass included.
- Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Space | O(n) | O(1) |
| Passes | 2+ | 1 |

### Mirror Frequency Distance
- File: [Some_Leetcode/MirrorFrequencyDistance.cpp](Some_Leetcode/MirrorFrequencyDistance.cpp)
- Approach used: compute mirror char and frequency differences.
- Time: O(n^2). Space: O(1).
- Better approach: count frequencies once in O(n).

### Maximum Depth of N-ary Tree
- File: [Some_Leetcode/Nary_tree.cpp](Some_Leetcode/Nary_tree.cpp)
- Approach used: DFS storing leaf depths then max.
- Time: O(n). Space: O(n).
- Better approach: return max depth directly without storing all.

### Next Greater Element III
- File: [Some_Leetcode/NextGreaterElement3.cpp](Some_Leetcode/NextGreaterElement3.cpp)
- Approach used: next permutation on digits with overflow check.
- Time: O(d). Space: O(1).

### Next Permutation
- File: [Some_Leetcode/NextPermutation.cpp](Some_Leetcode/NextPermutation.cpp)
- Approach used: find pivot, swap with next greater, reverse suffix.
- Time: O(n). Space: O(1).

### Nim Game
- File: [Some_Leetcode/NimGame.c](Some_Leetcode/NimGame.c)
- Approach used: n % 4 != 0 rule.
- Time: O(1). Space: O(1).

### Non-Overlapping Intervals
- File: [Some_Leetcode/NonOverlappingIntervals.cpp](Some_Leetcode/NonOverlappingIntervals.cpp)
- Approach used: sort by end and count overlaps.
- Time: O(n log n). Space: O(1).

### Number of Arithmetic Triplets
- File: [Some_Leetcode/NoOfArithematicTriplets.cpp](Some_Leetcode/NoOfArithematicTriplets.cpp)
- Approach used: two-pointer per i (note says not needed).
- Time: O(n^2). Space: O(1).
- Better approach: use hash set and count (x, x+diff, x+2diff).

### Product of Array Except Self
- File: [Some_Leetcode/ProductOfArrayExceptSelf.cpp](Some_Leetcode/ProductOfArrayExceptSelf.cpp)
- Approach used: suffix product + prefix rolling.
- Time: O(n). Space: O(1) extra.

### Water Bottles (Recursive)
- File: [Some_Leetcode/recursion_water_bottles.c](Some_Leetcode/recursion_water_bottles.c)
- Approach used: recursive exchange simulation.
- Time: O(log n). Space: O(log n).

### Remove Digit to Maximize Result
- File: [Some_Leetcode/RemoveDigitMaximiseResult.c](Some_Leetcode/RemoveDigitMaximiseResult.c)
- Approach used: remove leftmost digit that is less than next; else last occurrence.
- Time: O(n). Space: O(1).

### Robot Collisions
- File: [Some_Leetcode/RobotCollisions.cpp](Some_Leetcode/RobotCollisions.cpp)
- Approach used: sort by position, stack simulate collisions.
- Time: O(n log n). Space: O(n).

### Rotate Image
- File: [Some_Leetcode/RotateImage.cpp](Some_Leetcode/RotateImage.cpp)
- Approach used: transpose then reverse rows.
- Time: O(n^2). Space: O(1).

### Set Matrix Zeroes
- File: [Some_Leetcode/SetMatrixZeroes.cpp](Some_Leetcode/SetMatrixZeroes.cpp)
- Approach used: store zero rows/cols then zero them.
- Time: O(m*n). Space: O(m+n).
- Better approach: use first row/col markers for O(1) extra space.

### Single Element in a Sorted Array
- File: [Some_Leetcode/SingleElementInASortedArray.cpp](Some_Leetcode/SingleElementInASortedArray.cpp)
- Approach used: binary search on even indices.
- Time: O(log n). Space: O(1).

### Shortest Palindrome
- File: [Some_Leetcode/SmallestPalindrome.cpp](Some_Leetcode/SmallestPalindrome.cpp)
- Approach used: compare with reversed suffix; better KMP included.
- Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | O(n^2) | O(n) |
| Technique | Brute compare | KMP LPS |

### Smallest Palindromic Rearrangement
- File: [Some_Leetcode/SmallestPalindromicRearrangement1.cpp](Some_Leetcode/SmallestPalindromicRearrangement1.cpp)
- Approach used: build half from freq, append odd center, mirror.
- Time: O(n). Space: O(1).

### Special Positions in a Binary Matrix
- File: [Some_Leetcode/SpecialPositionsInABinaryMatrix.cpp](Some_Leetcode/SpecialPositionsInABinaryMatrix.cpp)
- Approach used: count 1s per row/col then check cells.
- Time: O(m*n). Space: O(m+n).

### Spiral Matrix
- File: [Some_Leetcode/SpiralMatrix.cpp](Some_Leetcode/SpiralMatrix.cpp)
- Approach used: boundary traversal.
- Time: O(m*n). Space: O(1) extra.

### Sum of Beauty of All Substrings
- File: [Some_Leetcode/SumOfBeautyOfAllSubstrings.cpp](Some_Leetcode/SumOfBeautyOfAllSubstrings.cpp)
- Approach used: O(n^2*26) with freq recompute.
- Time: O(n^2). Space: O(1).

### Sum of Subarray Minimums (TLE versions)
- File: [Some_Leetcode/SumOfSubarrayMin.cpp](Some_Leetcode/SumOfSubarrayMin.cpp)
- Approach used: brute force; TLE.
- Better approach: monotonic stack for contribution counting.

### Sum of Subarray Minimums (Optimized)
- File: [Some_Leetcode/SumOfSubarrayMinimum.cpp](Some_Leetcode/SumOfSubarrayMinimum.cpp)
- Approach used: PSE/NSE monotonic stack to count contributions.
- Time: O(n). Space: O(n).

### Sum of Subarray Ranges
- File: [Some_Leetcode/SumOfSubarrayRanges.cpp](Some_Leetcode/SumOfSubarrayRanges.cpp)
- Approach used: O(n^3) brute and O(n) stack-based min/max contributions.
- Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | O(n^3) | O(n) |
| Technique | Enumerate subarrays | Monotonic stacks |

### Triangular Sum
- File: [Some_Leetcode/triangular_sum](Some_Leetcode/triangular_sum)
- Approach used: repeated reduction with mod 10.
- Time: O(n^2). Space: O(n).

### Tribonacci
- File: [Some_Leetcode/Tribonacci.cpp](Some_Leetcode/Tribonacci.cpp)
- Approach used: iterative rolling values.
- Time: O(n). Space: O(1).

### Trionic Array
- File: [Some_Leetcode/TrionicArray1.cpp](Some_Leetcode/TrionicArray1.cpp)
- Approach used: track alternating peak/valley count.
- Time: O(n). Space: O(1).

### Walking Robot Simulation
- File: [Some_Leetcode/WalkingRobotSimulation.cpp](Some_Leetcode/WalkingRobotSimulation.cpp)
- Approach used: simulate with obstacle checks by scan (O(n*m)).
- Time: O(commands * obstacles). Space: O(1).
- Better approach: store obstacles in hash set for O(1) lookup.

### Water Bottles II
- File: [Some_Leetcode/water_bottles_2.c](Some_Leetcode/water_bottles_2.c)
- Approach used: iterative exchange with increasing cost.
- Time: O(numExchange steps). Space: O(1).

### Words Within Two Edits of Dictionary
- File: [Some_Leetcode/WordsWithinTwoEditsOfDictionary.cpp](Some_Leetcode/WordsWithinTwoEditsOfDictionary.cpp)
- Approach used: brute compare each query with each dictionary word.
- Time: O(q*d*len). Space: O(1).

### XOR After Range Multiplication Queries
- File: [Some_Leetcode/XORAfterRangeMultiplicationQueries1.cpp](Some_Leetcode/XORAfterRangeMultiplicationQueries1.cpp)
- Approach used: apply each query by stepping indices; then xor all.
- Time: O(total steps). Space: O(1).
- Better approach: use difference-style batching or segment tree for many queries.

### Find the Score Difference in a Game
- File: [Some_Leetcode/FindTheScoreDifferenceInAGame.cpp](Some_Leetcode/FindTheScoreDifferenceInAGame.cpp)
- Approach used: toggle active player flags on odd numbers and every 6th index; accumulate scores.
- Time: O(n). Space: O(1).

### Nth Ugly Number III
- File: [Some_Leetcode/UglyNumber3.cpp](Some_Leetcode/UglyNumber3.cpp)
- Approach used: binary search on answer range [1, 2e9]; count ugly numbers <= mid using inclusion-exclusion on lcm.
- Time: O(log(2e9)). Space: O(1).

### Valid Elements in an Array
- File: [Some_Leetcode/ValidElementsInAnArray.cpp](Some_Leetcode/ValidElementsInAnArray.cpp)
- Approach used: for each index, check if all left elements are less and all right elements are greater; O(n^2) nested loops.
- Time: O(n^2). Space: O(1).
- Better approach: compute prefix max and suffix min for O(n).

### Maximum Product of Three Elements After One Replacement
- File: [Some_Leetcode/MaximumProductOfThreeElementsAfterOneReplacement.cpp](Some_Leetcode/MaximumProductOfThreeElementsAfterOneReplacement.cpp)
- Approach used: find two largest abs values, check various replacements and two-element products scaled by 1e5.
- Time: O(n log n). Space: O(1).

### Check If Number Is Digitorial Permutation
- File: [Some_Leetcode/CheckDigitorialPermutation.cpp](Some_Leetcode/CheckDigitorialPermutation.cpp)
- Approach used: sum factorials of digits; check if digit multiset of n equals digit multiset of factorial sum.
- Time: O(log n). Space: O(1).

## Requires_Correction

These files are marked incorrect or inefficient. Use this section to revisit them.

### Add Two Numbers (overflow)
- File: [Some_Leetcode/Requires_Correction/AddTwoNums.cpp](Some_Leetcode/Requires_Correction/AddTwoNums.cpp)
- Approach used: convert lists to number; overflow error.
- Better approach: digit-by-digit addition with carry.

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Correctness | Overflows | Safe |
| Space | O(1) | O(1) |

### Contaminated Binary Tree
- File: [Some_Leetcode/Requires_Correction/ContaminatedBT.cpp](Some_Leetcode/Requires_Correction/ContaminatedBT.cpp)
- Approach used: re-label only while searching target (inefficient).
- Better approach: rebuild entire tree once and store values in a hash set.

### Delete Linked List Nodes Present in Array
- File: [Some_Leetcode/Requires_Correction/DeleteNodesPresentInArray.cpp](Some_Leetcode/Requires_Correction/DeleteNodesPresentInArray.cpp)
- Approach used: set of values, then skip matching nodes.
- Time: O(n + m). Space: O(m).

### Design Linked List
- File: [Some_Leetcode/Requires_Correction/DesignLinkedList.cpp](Some_Leetcode/Requires_Correction/DesignLinkedList.cpp)
- Approach used: basic singly linked list operations.
- Time: O(n) for index ops. Space: O(n).

### Divide Two Integers
- File: [Some_Leetcode/Requires_Correction/DivideTwoIntegers29.cpp](Some_Leetcode/Requires_Correction/DivideTwoIntegers29.cpp)
- Approach used: repeated subtraction; TLE.
- Better approach: use bit shifting and doubling.

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | O(quotient) | O(log n) |
| Technique | Subtract | Bit shifts |

### Kth Largest Element in an Array
- File: [Some_Leetcode/Requires_Correction/Kth_largest_element.c](Some_Leetcode/Requires_Correction/Kth_largest_element.c)
- Approach used: repeatedly find max; TLE.
- Better approach: quickselect or min-heap of size k.

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | O(k*n) | O(n) average |
| Space | O(1) | O(k) |

### Longest Arithmetic Subsequence After One Change
- File: [Some_Leetcode/Requires_Correction/LongestArithematicSubseqAfterChangingAtMostOneElement.cpp](Some_Leetcode/Requires_Correction/LongestArithematicSubseqAfterChangingAtMostOneElement.cpp)
- Approach used: complex heuristic; needs review.
- Better approach: DP with states (index, diff, usedChange).

### Lowest Common Ancestor of BST
- File: [Some_Leetcode/Requires_Correction/LowestCommonAncestorOfBST.cpp](Some_Leetcode/Requires_Correction/LowestCommonAncestorOfBST.cpp)
- Approach used: path arrays in general tree.
- Better approach: use BST property to walk down in O(h).

### N-ary Tree Level Order Traversal
- File: [Some_Leetcode/Requires_Correction/NaryTreeLOT.cpp](Some_Leetcode/Requires_Correction/NaryTreeLOT.cpp)
- Approach used: BFS; marked inefficient but fine.
- Time: O(n). Space: O(n).

### Next Greater Node in Linked List
- File: [Some_Leetcode/Requires_Correction/NextGreaterElementInLL.cpp](Some_Leetcode/Requires_Correction/NextGreaterElementInLL.cpp)
- Approach used: reverse list + stack of values.
- Time: O(n). Space: O(n).

### Rearrange Array Elements by Sign
- File: [Some_Leetcode/Requires_Correction/RearrangeArrayElementsBySign.cpp](Some_Leetcode/Requires_Correction/RearrangeArrayElementsBySign.cpp)
- Approach used: inefficient build then interleave; better included.

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | O(n) | O(n) |
| Space | O(n) extra | O(n) direct |

### Smallest Subtree With All the Deepest Nodes
- File: [Some_Leetcode/Requires_Correction/smallest_subtree_with_deepest_node.c](Some_Leetcode/Requires_Correction/smallest_subtree_with_deepest_node.c)
- Approach used: incorrect depth handling; needs rework.
- Better approach: postorder returning (subtree, depth) and choose deeper side or current root when equal.

### Word Break
- File: [Some_Leetcode/Requires_Correction/WordBreak.cpp](Some_Leetcode/Requires_Correction/WordBreak.cpp)
- Approach used: brute recursion; TLE.
- Better approach: DP with dictionary set.
