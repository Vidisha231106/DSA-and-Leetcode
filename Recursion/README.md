# Recursion and Backtracking

This folder covers classic backtracking patterns: choose/explore/unchoose, pruning with sorted inputs, and generation of combinatorial sets. Use this to revise recursion templates and duplicate-handling strategies.

## Problems and approaches

### Combination Sum
- File: [Recursion/CombinationSum.cpp](Recursion/CombinationSum.cpp)
- Approach used: DFS choose current number repeatedly; pass index to allow reuse.
- Time: Exponential. Space: O(target) recursion depth.
- Better approach: pass `curr_candidates` by reference with push/pop to reduce copies.

### Combination Sum II
- File: [Recursion/CombinationSum2.cpp](Recursion/CombinationSum2.cpp)
- Approach used: sort + skip duplicates at same depth; move index forward.
- Time: Exponential. Space: O(n) recursion depth.

### Combination Sum III
- File: [Recursion/CombinationSum3.cpp](Recursion/CombinationSum3.cpp)
- Approach used: backtracking over numbers 1..9 with pruning by sum and size.
- Time: Exponential. Space: O(k).

### Generate Parentheses
- File: [Recursion/GenerateParanthesis.cpp](Recursion/GenerateParanthesis.cpp)
- Approach used: backtracking with counts of open/close.
- Time: O(Cn). Space: O(n).

### Letter Combinations of a Phone Number
- File: [Recursion/LetterCombinationOfAPhoneNumber.cpp](Recursion/LetterCombinationOfAPhoneNumber.cpp)
- Approach used: DFS over digit mapping.
- Time: O(3^n to 4^n). Space: O(n).

### Permutations
- File: [Recursion/Permutations.cpp](Recursion/Permutations.cpp)
- Approach used: in-place swap recursion.
- Time: O(n!). Space: O(n).

### Permutations II (Unique)
- File: [Recursion/Permutations2.cpp](Recursion/Permutations2.cpp)
- Approach used: sort + skip duplicates by position.
- Time: O(n!). Space: O(n).
- Better approach: use a `used` array and build permutation to avoid value-copy recursion.

### Subsets
- File: [Recursion/Subsets.cpp](Recursion/Subsets.cpp)
- Approach used: include/exclude recursion.
- Time: O(2^n). Space: O(n).

### Subsets II
- File: [Recursion/Subsets2.cpp](Recursion/Subsets2.cpp)
- Approach used: sort + skip duplicates at same depth.
- Time: O(2^n). Space: O(n).

### K-th Lexicographical Happy String of Length n
- File: [Recursion/TheKthLexicographicalStringofAllHappyStringsOfLengthN.cpp](Recursion/TheKthLexicographicalStringofAllHappyStringsOfLengthN.cpp)
- Approach used: generate all strings then pick k; comment notes can be optimized.
- Time: O(3*2^(n-1)). Space: O(3*2^(n-1)).
- Better approach:
  - Summarize current: full generation of all strings.
  - Improvement: construct kth string by counting blocks (skip subtrees).
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | Generate all | O(n) build |
| Space | Store all | O(n) |

### N-Queens
- File: [Recursion/N-Queens.cpp](Recursion/N-Queens.cpp)
- Approach used: column-by-column backtracking; track which rows, upper diagonals, and lower diagonals are occupied using three boolean arrays; place queen in each valid row for current column and recurse.
- Time: O(n!). Space: O(n) for the tracking arrays and O(n^2) for the board.
- Note: using index arrays for rows/diagonals instead of re-scanning the board gives O(1) validity checks per placement.

### Valid Binary Strings With Cost Limit
- File: [Recursion/ValidBinaryStringsWithCostLimit.cpp](Recursion/ValidBinaryStringsWithCostLimit.cpp)
- Approach used: backtracking generates all binary strings of length n; constraint: two consecutive '1's are not allowed; at the leaf level, compute cost = sum of 1-based positions of '1' bits and include only if cost ≤ k.
- Time: O(2^n). Space: O(n) recursion + O(output).
- Better approach: prune early by tracking cost incrementally during recursion rather than computing at the leaf; skip entire subtrees when accumulated cost would exceed k.

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Cost check | At leaf (no pruning) | Incremental during DFS |
| Time | O(2^n) full | O(2^n) but with strong pruning |

