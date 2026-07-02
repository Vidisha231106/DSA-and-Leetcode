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

### Cherry Pickup II
- File: [DP/CherryPickup2.cpp](DP/CherryPickup2.cpp)
- Approach used: two paths moving down simultaneously with 3D memoization (row, col1, col2); accumulate cherries when paths occupy same cell.
- Time: O(m*n^2). Space: O(m*n^2).

### Last Stone Weight II
- File: [DP/LastStoneWeight2.cpp](DP/LastStoneWeight2.cpp)
- Approach used: partition stones into two groups; result = |S1 - S2| minimized by finding subset sum closest to total/2; 0/1 knapsack DP.
- Time: O(n*sum/2). Space: O(sum/2).

### Longest Almost Palindromic Substring
- File: [DP/LongestAlmostPalindromicSubstring.cpp](DP/LongestAlmostPalindromicSubstring.cpp)
- Approach used: DP tracking palindrome vs almost-palindrome (one character mismatch allowed) for all substrings.
- Time: O(n^2). Space: O(n^2).

### Interleaving String
- File: [DP/InterleavingString.cpp](DP/InterleavingString.cpp)
- Approach used: 2D DP where dp[i][j] = can s3[0..i+j-1] be formed from s1[0..i-1] and s2[0..j-1].
- Time: O(n*m). Space: O(n*m).

### Combination Sum IV
- File: [DP/CombinationSum4.cpp](DP/CombinationSum4.cpp)
- Approach used: memoized recursion; for each target, try subtracting each number and sum results.
- Time: O(target * n). Space: O(target).

### Maximum Number of Jumps to Reach the Last Index
- File: [DP/MaximumNumberOfJumpsToReachTheLastIndex.cpp](DP/MaximumNumberOfJumpsToReachTheLastIndex.cpp)
- Approach used: DP bottom-up; dp[i] = max jumps reachable from i by checking all j where |nums[j]-nums[i]| <= target.
- Time: O(n^2). Space: O(n).

### Perfect Squares
- File: [DP/PerfectSquares.cpp](DP/PerfectSquares.cpp)
- Approach used: 1D DP; dp[i] = minimum count of perfect squares summing to i; try all squares <= i.
- Time: O(n*sqrt(n)). Space: O(n).

### Profitable Schemes
- File: [DP/ProfitableSchemes.cpp](DP/ProfitableSchemes.cpp)
- Approach used: 3D memoized recursion dp[index][men_used][profit_made]; for each crime, decide to take or skip.
- Time: O(n*m*minProfit). Space: O(n*m*minProfit).

### Rotated Digits
- File: [DP/RotatedDigits.cpp](DP/RotatedDigits.cpp)
- Approach used: DP per digit; valid rotated = all digits valid (0,1,2,5,6,8,9) and at least one in (2,5,6,9).
- Time: O(n). Space: O(n).

### Shortest Common Supersequence
- File: [DP/ShortestCommonSupersequence.cpp](DP/ShortestCommonSupersequence.cpp)
- Approach used: LCS DP on two strings; backtrack from dp table, including common chars once and diff chars from both.
- Time: O(n*m). Space: O(n*m).

### Solving Questions With Brainpower
- File: [DP/SolvingQuestionsWithBrainpower.cpp](DP/SolvingQuestionsWithBrainpower.cpp)
- Approach used: memoized recursion; for each question, take it (gain points + skip ahead) or skip it.
- Time: O(n). Space: O(n).

### Super Ugly Number
- File: [DP/SuperUglyNumber.cpp](DP/SuperUglyNumber.cpp)
- Approach used: 1D DP with pointers per prime; at each step pick minimum and advance pointer for that prime.
- Time: O(n*k). Space: O(n).

### Target Sum
- File: [DP/TargetSum.cpp](DP/TargetSum.cpp)
- Approach used: partition DP where sum of positive = (target + total)/2; solve 0/1 knapsack to count ways.
- Time: O(n*target). Space: O(target).

### Unique Binary Search Trees
- File: [DP/UniqueBinarySearchTrees.cpp](DP/UniqueBinarySearchTrees.cpp)
- Approach used: memoized recursion; for root i in [1..n], count = count_left * count_right; dp[n].
- Time: O(n^2). Space: O(n).
- Better approach: recognize as Catalan number C_n.

### Minimum Cost For Tickets
- File: [DP/MinimumCostForTickets.cpp](DP/MinimumCostForTickets.cpp)
- Approach used: DP over days; skip non-travel days; on travel days, choose 1/7/30 day pass with running sum.
- Time: O(max_day). Space: O(max_day).

### Minimum Cost to Move Between Indices
- File: [DP/MinimumCostToMoveBetweenIndices.cpp](DP/MinimumCostToMoveBetweenIndices.cpp)
- Approach used: forward and backward DP for cost; forward: if adjacent indices are closest, allow move for cost 1 vs diff; queries answered via DP difference.
- Time: O(n + q). Space: O(n).

### Minimum Deletions to Make String Balanced
- File: [DP/MinimumDeletionsToMakeStringBalanced.cpp](DP/MinimumDeletionsToMakeStringBalanced.cpp)
- Approach used: prefixes of 'b' before position, suffixes of 'a' after position; answer = min(b_before + a_after) for all splits.
- Time: O(n). Space: O(n).

### Minimum Insertion Steps to Make a String Palindrome
- File: [DP/MinimumInsertionStepsToMakeAStringPalindrome.cpp](DP/MinimumInsertionStepsToMakeAStringPalindrome.cpp)
- Approach used: LCS of string and its reverse gives longest palindromic subsequence; insertions = length - LCS_length.
- Time: O(n^2). Space: O(n^2).

### Minimum Cost Tree From Leaf Values
- File: [DP/MinimumCostTreeFromLeafValues.cpp](DP/MinimumCostTreeFromLeafValues.cpp)
- Approach used: interval DP; for each range, try all split points; cost = mctFromLeafValues(left) + mctFromLeafValues(right) + (max_left * max_right).
- Time: O(n^3). Space: O(n^2).

### Best Time to Buy and Sell Stock III
- File: [DP/BestTimeToBuyAndSellStock3.cpp](DP/BestTimeToBuyAndSellStock3.cpp)
- Approach used: 3D DP with states `dp[i][buy/sell][transactions]`; tracks profit for at most 2 transactions using transaction count as third dimension. Also includes an optimised constant-space solution tracking four states: buy1, sell1, buy2, sell2.
- Time: O(n). Space: O(n) DP or O(1) with rolling variables.
- Better approach:
  - Summarize current: full 3D DP array.
  - Improvement: use four variables (buy1, sell1, buy2, sell2) updated in one pass.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Space | O(n) | O(1) |
| State | 3D table | 4 rolling variables |

### Best Time to Buy and Sell Stock IV
- File: [DP/BestTimeToBuyAndSellStock4.cpp](DP/BestTimeToBuyAndSellStock4.cpp)
- Approach used: 3D DP `dp[i][buy/sell][k]` tracking up to K transactions; at each day decide whether to buy, sell, or hold.
- Time: O(n*K). Space: O(n*K).
- Better approach: roll the DP to O(K) space by keeping only the current and previous rows.

### Distinct Subsequences
- File: [DP/DistinctSubsequences.cpp](DP/DistinctSubsequences.cpp)
- Approach used: bottom-up 2D DP iterating from the end; `dp[i][j]` = number of ways `s[i..]` contains `t[j..]`; on match, sum both use and skip choices; on mismatch, propagate skip.
- Time: O(n*m). Space: O(n*m).
- Better approach: reduce to O(m) space with a single 1D array processed right to left.

### House Robber III (Tree DP)
- File: [DP/HouseRobber3.cpp](DP/HouseRobber3.cpp)
- Approach used: postorder DFS returning a pair `{taken, not_taken}` for each node; `taken = node->val + left.not_taken + right.not_taken`; `not_taken = max(left) + max(right)`. No extra space beyond recursion.
- Time: O(n). Space: O(h).

### House Robber IV (Binary Search + DP)
- File: [DP/HouseRobber4.cpp](DP/HouseRobber4.cpp)
- Note: File comment says TLE. Uses memoized recursion `dp[index][k]`: at each house either take it (reducing k by 1, skip next) or skip. Does not correctly memoize due to shared dp across different `k` branches. 
- Better approach:
  - Summarize current: memoised recursion — TLE and memo not properly keyed.
  - Improvement: binary search on the answer (minimum capability), then greedily check if k houses can be robbed with capability ≤ mid.
  - Comparison:

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | TLE (exponential) | O(n log(max)) |
| Technique | Memoised recursion | Binary search on answer |

### House Robber V (Colour-Constrained DP)
- File: [DP/HouseRobber5.cpp](DP/HouseRobber5.cpp)
- Approach used: 2D DP with states `dp[i][0]` = max profit including house i, `dp[i][1]` = max profit excluding house i; when adjacent houses have the same colour, only the skip-previous option is available for taking current.
- Time: O(n). Space: O(n).
- Better approach: reduce to O(1) with four rolling variables.

### Largest Divisible Subset
- File: [DP/LargestDivisibleSubset.cpp](DP/LargestDivisibleSubset.cpp)
- Approach used: sort then LIS-style DP; `dp[i]` = longest chain ending at `nums[i]`; extend when `nums[i] % nums[j] == 0`; backtrack using a `prev` array to reconstruct the subset.
- Time: O(n^2). Space: O(n).

### Longest Arithmetic Subsequence
- File: [DP/LongestArithematicSubsequence.cpp](DP/LongestArithematicSubsequence.cpp)
- Approach used: `dp[i]` is a hashmap from difference → length of longest arithmetic subsequence ending at i with that difference; for each pair (j, i), compute diff = nums[i] - nums[j], set `dp[i][diff] = dp[j][diff] + 1` (or 2 if new).
- Time: O(n^2). Space: O(n^2).

### Longest Arithmetic Subsequence of Given Difference
- File: [DP/LongestArithematicSubsequenceOfGivenDifference.cpp](DP/LongestArithematicSubsequenceOfGivenDifference.cpp)
- Approach used: hashmap DP in a single pass; for each element x, `dp[x] = dp[x - difference] + 1`; avoids the O(n^2) loop since the target predecessor is known.
- Time: O(n). Space: O(n).

### Longest String Chain
- File: [DP/LongestStringChain.cpp](DP/LongestStringChain.cpp)
- Approach used: sort words by length then LIS-style DP; for each pair (j, i) where `|words[i]| - |words[j]| == 1`, check if j is a predecessor by single-character deletion scan; extend chain if so.
- Time: O(n^2 * L) where L = word length. Space: O(n).
- Better approach: for each word, try all one-char deletions and look up result in a hashmap in O(L) per word.

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | O(n^2 * L) | O(n * L^2) |
| Lookup | Pairwise comparison | HashMap of predecessors |

### Maximum Number of Items From Sale
- File: [DP/MaximumNumberOfItemsFromSale1.cpp](DP/MaximumNumberOfItemsFromSale1.cpp)
- Approach used: precompute for each item how many other items have price divisible by its price; then 2D knapsack DP where taking item i also counts all its divisible items (stored in map); unbounded-style loop allows re-use.
- Time: O(n^2 + n * budget). Space: O(n * budget).

### Minimum Cost to Split Into Ones
- File: [DP/MinimumCostToSplitIntoOnes.cpp](DP/MinimumCostToSplitIntoOnes.cpp)
- Approach used: two solutions included — a DP that tries all split points `dp[i] = min(dp[i-j] + dp[j] + j*(i-j))`, and a mathematical observation that the optimal is always to split into pairs of (1, n-1) successively, giving `n*(n-1)/2`.
- Time: O(n^2) DP or O(1) math. Space: O(n) or O(1).
- Better approach:
  - Summarize current: includes both DP and closed-form.
  - The closed-form `n*(n-1)/2` is optimal since the cost of splitting x into parts a and b is a*b and minimizing means always splitting off 1.

| Aspect | DP approach | Mathematical approach |
| --- | --- | --- |
| Time | O(n^2) | O(1) |
| Space | O(n) | O(1) |

### Number of Dice Rolls With Target Sum
- File: [DP/NumberOfDiceRollsWithTargetSum.cpp](DP/NumberOfDiceRollsWithTargetSum.cpp)
- Approach used: memoised recursion; for each die count remaining and remaining target, try all face values 1..k; accumulate ways modulo 1e9+7.
- Time: O(n * target * k). Space: O(n * target).
- Better approach: bottom-up 2D DP `dp[dice][target]` for O(n * target) space and avoids recursion overhead.

### Maximum Amount of Money Robot Can Earn
- File: [DP/MaximumAmountOfMoneyRobotCanEarn.cpp](DP/MaximumAmountOfMoneyRobotCanEarn.cpp)
- Approach used: 3D memoised recursion `dp[i][j][lives]`; at each cell either take the value (paying or earning) or use a life to neutralise a negative cell (subtract its cost); propagate best path from top-left to bottom-right with at most 2 lives.
- Time: O(m * n * 3). Space: O(m * n * 3).

### Maximum Path Score in a Grid
- File: [DP/MaximumPathScoreInAGrid.cpp](DP/MaximumPathScoreInAGrid.cpp)
- Approach used: two implementations — (1) Wrong greedy DP: stores only `(score, cost)` per cell, greedily prefers higher score path; incorrect for ≥435 test cases. (2) Correct 3D DP `dp[i][j][c]` = max score reaching (i,j) with exactly c non-zero cells counted; for each cost dimension c, propagate from neighbours; answer = max over all c ≤ k of dp[n-1][m-1][c].
- Time: O(m * n * k). Space: O(m * n * k).
- Note: clearly demonstrates why greedy fails and 3D DP is needed for constrained path problems.

| Aspect | Wrong greedy | Correct 3D DP |
| --- | --- | --- |
| Correctness | Fails in many cases | Always correct |
| Time | O(m*n) | O(m*n*k) |
| Space | O(m*n) | O(m*n*k) |

### Longest Almost Palindromic Substring
- File: [DP/LongestAlmostPalindromicSubstring.cpp](DP/LongestAlmostPalindromicSubstring.cpp)
- Approach used: 2D DP — `palindrome[i][j]` = 1 if s[i..j] is a strict palindrome; `almost_pal[i][j]` = 1 if s[i..j] is a palindrome with at most one character different. Build bottom-up from shorter substrings; for each `[i,j]`: if ends match, extend any `almost_pal[i+1][j-1]` to an almost palindrome; if ends differ, extend any `palindrome[i+1][j]` or `palindrome[i][j-1]`.
- Time: O(n^2). Space: O(n^2).

### Minimum Cost to Move Between Indices
- File: [DP/MinimumCostToMoveBetweenIndices.cpp](DP/MinimumCostToMoveBetweenIndices.cpp)
- Approach used: for each index record its "closest" index (the neighbour that is closer in value); compute forward DP and backward DP where moving to a closer index costs 1 instead of |diff|; for each query (l, r), answer is the cost to go from l to r using the prefix DP arrays.
- Time: O(n + q). Space: O(n).
