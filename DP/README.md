# Dynamic Programming (DP)

This folder covers classic DP patterns: 1D/2D tabulation, memoized recursion, interval DP, and state machines (stock problems). Use this as a revision guide for defining states, transitions, and base cases.

## Problems and approaches

### Best Time to Buy and Sell Stock II
- File: [DP/BestTimeToBuyAndSellStock2.cpp](DP/BestTimeToBuyAndSellStock2.cpp)
- Approach used: DP with two states (cash, hold) per day.
- Time: O(n). Space: O(n).
- Better approach:
  - Summarize current: stores two-state DP for all days.
  - Improvement: use two variables for O(1) space.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Space | O(n) | O(1) |
| State | dp[i] pair | rolling variables |

### Best Time to Buy and Sell Stock With Cooldown
- File: [DP/BestTimeToBuyAndSellStockWithCooldown.cpp](DP/BestTimeToBuyAndSellStockWithCooldown.cpp)
- Approach used: DP with cash/hold; hold uses dp[i-2] for cooldown.
- Time: O(n). Space: O(n).
- Better approach: roll variables for O(1) space.

### Best Time to Buy and Sell Stock With Transaction Fee
- File: [DP/BestTimeToBuyAndSellStockWithTransactionFee.cpp](DP/BestTimeToBuyAndSellStockWithTransactionFee.cpp)
- Approach used: DP two states, fee on sell.
- Time: O(n). Space: O(n).
- Better approach: O(1) space with rolling states.

### Coin Change
- File: [DP/CoinChange.cpp](DP/CoinChange.cpp)
- Approach used: bottom-up dp[amount], try all coins.
- Time: O(n*amount). Space: O(amount).

### Coin Change II
- File: [DP/CoinChange2.cpp](DP/CoinChange2.cpp)
- Approach used: memoization, 2D tabulation, and 1D tabulation versions.
- Time: O(n*amount). Space: O(n*amount) or O(amount).

### Count Square Submatrices With All Ones
- File: [DP/CountSquareSubmatricesWithAllOnes.cpp](DP/CountSquareSubmatricesWithAllOnes.cpp)
- Approach used: dp[i][j] = 1 + min(top, left, diag) for ones; sum dp.
- Time: O(m*n). Space: O(m*n).
- Better approach: reduce to O(n) space by rolling rows.

### Delete Operation for Two Strings
- File: [DP/DeleteOperationsForTwoStrings.cpp](DP/DeleteOperationsForTwoStrings.cpp)
- Approach used: edit-distance variant DP counting deletes only.
- Time: O(n*m). Space: O(n*m).
- Better approach: compute LCS, answer = n+m-2*LCS; can use 2-row space.

### Domino and Tromino Tiling
- File: [DP/DominoAndTrominoTiling.cpp](DP/DominoAndTrominoTiling.cpp)
- Approach used: DP with three states for full and partial tilings.
- Time: O(n). Space: O(n).
- Better approach: O(1) space with rolling states.

### Frog Jump
- File: [DP/FrogJump.cpp](DP/FrogJump.cpp)
- Approach used: map from stone to set of reachable jump sizes.
- Time: O(n^2) worst-case. Space: O(n^2).
- Better approach: use unordered_set of stones and memoized DFS to prune early.

### Guess Number Higher or Lower II
- File: [DP/GuessNumberHigherOrLower2.cpp](DP/GuessNumberHigherOrLower2.cpp)
- Approach used: interval DP, minimax cost.
- Time: O(n^3). Space: O(n^2).

### House Robber
- File: [DP/HouseRobber.cpp](DP/HouseRobber.cpp)
- Approach used: dp[i] = max(rob, skip).
- Time: O(n). Space: O(n).
- Better approach: O(1) space with two variables.

### House Robber II
- File: [DP/HouseRobber2.cpp](DP/HouseRobber2.cpp)
- Approach used: run linear robber on [0..n-2] and [1..n-1].
- Time: O(n). Space: O(n).
- Better approach: O(1) space for each run.

### Integer Break
- File: [DP/IntegerBreak.cpp](DP/IntegerBreak.cpp)
- Approach used: DP to maximize product.
- Time: O(n^2). Space: O(n).
- Better approach:
  - Summarize current: DP tries all splits.
  - Improvement: math greedy using 3s for O(1) time.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | O(n^2) | O(1) |
| Technique | DP | Greedy math |

### Longest Common Subsequence
- File: [DP/LongestCommonSubsequence.cpp](DP/LongestCommonSubsequence.cpp)
- Approach used: 2D DP.
- Time: O(n*m). Space: O(n*m).
- Better approach: 2-row DP for O(min(n,m)) space.

### Longest Increasing Subsequence
- File: [DP/LongestIncreasingSubsequence.cpp](DP/LongestIncreasingSubsequence.cpp)
- Approach used: memoized recursion with prev index state.
- Time: O(n^2). Space: O(n^2).
- Better approach:
  - Summarize current: DP over prev/current indices.
  - Improvement: patience sorting with binary search in O(n log n).
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | O(n^2) | O(n log n) |
| Space | O(n^2) | O(n) |

### Longest Palindromic Subsequence
- File: [DP/LongestPalindromicSubsequence.cpp](DP/LongestPalindromicSubsequence.cpp)
- Approach used: LCS of string and its reverse.
- Time: O(n^2). Space: O(n^2).
- Better approach: direct DP on substring with 2-row space.

### Maximum Amount of Money Robot Can Earn
- File: [DP/MaximumAmountOfMoneyRobotCanEarn.cpp](DP/MaximumAmountOfMoneyRobotCanEarn.cpp)
- Approach used: 3D DP with lives (neutralize negatives) and grid coords.
- Time: O(m*n*3). Space: O(m*n*3).

### Maximum Path Score in a Grid
- File: [DP/MaximumPathScoreInAGrid.cpp](DP/MaximumPathScoreInAGrid.cpp)
- Approach used: DP with (score, cost) per cell; marked incorrect.
- Note: This file states the solution is incorrect.
- Better approach:
  - Summarize current: keeps only one best score per cell under cost.
  - Improvement: DP with cost dimension: dp[i][j][c] = max score with cost c, or use shortest/longest path with constraint via knapsack-style transitions.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Correctness | Incorrect for some cases | Correct with cost state |
| State | Single best | Cost-aware DP |

### Min Cost Climbing Stairs
- File: [DP/MinCostClimbingStairs.cpp](DP/MinCostClimbingStairs.cpp)
- Approach used: bottom-up dp with min of previous two steps.
- Time: O(n). Space: O(n).
- Better approach: O(1) space.

### Minimum Falling Path Sum
- File: [DP/MinimumFallingPathSum.cpp](DP/MinimumFallingPathSum.cpp)
- Approach used: tabulation and memoized recursion.
- Time: O(n*m). Space: O(n*m).
- Better approach: rolling row for O(m) space.

### Minimum Path Sum
- File: [DP/MinimumPathSum.cpp](DP/MinimumPathSum.cpp)
- Approach used: memoized recursion with dp.
- Time: O(m*n). Space: O(m*n).
- Better approach: bottom-up DP with O(n) space.

### Number of Longest Increasing Subsequence
- File: [DP/NumberOfLongestIncreasingSubsequence.cpp](DP/NumberOfLongestIncreasingSubsequence.cpp)
- Approach used: O(n^2) DP tracking (length, count).
- Time: O(n^2). Space: O(n).

### Palindrome Partitioning
- File: [DP/PalindromePartitioning.cpp](DP/PalindromePartitioning.cpp)
- Approach used: precompute palindrome DP, then backtrack partitions.
- Time: O(n^2 + output). Space: O(n^2).

### Palindrome Partitioning II
- File: [DP/PalindromePartitioning2.cpp](DP/PalindromePartitioning2.cpp)
- Approach used: memoization (TLE), tabulation (TLE), then precomputed palindrome DP.
- Time: O(n^2). Space: O(n^2).

### Palindrome Partitioning IV
- File: [DP/PalindromePartitioning4.cpp](DP/PalindromePartitioning4.cpp)
- Approach used: precompute palindromes; brute split into 3 parts.
- Time: O(n^2). Space: O(n^2).

### Partition Equal Subset Sum
- File: [DP/PartitionEqualSubsetSum.cpp](DP/PartitionEqualSubsetSum.cpp)
- Approach used: recursion + memo on (index, curr sum).
- Time: O(n*sum). Space: O(n*sum).
- Better approach: 1D boolean DP for O(sum) space.

### Triangle
- File: [DP/Triangle.cpp](DP/Triangle.cpp)
- Approach used: memoized recursion from top to bottom.
- Time: O(n^2). Space: O(n^2).
- Better approach: bottom-up with O(n) space.

### Unique Paths
- File: [DP/UniquePaths.cpp](DP/UniquePaths.cpp)
- Approach used: recursion + memo.
- Time: O(m*n). Space: O(m*n).
- Better approach: O(n) rolling or combinatorics.

### Word Break
- File: [DP/WordBreak.cpp](DP/WordBreak.cpp)
- Approach used: brute force recursion (TLE), then memoized recursion by index.
- Time: O(n^2 * dict) worst-case. Space: O(n).
- Better approach: use unordered_set and DP over indices for faster lookups.
