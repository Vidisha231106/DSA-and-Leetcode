# Maths

This folder covers mathematical problem-solving techniques including geometry (trigonometry), number theory (modular arithmetic, GCD/LCM), binary search optimization, and integer manipulation. Use this as a reference for math-heavy algorithmic problems.

## Problems and approaches

### Angle of a Triangle
- File: [Maths/AngleOfATriangle.cpp](Maths/AngleOfATriangle.cpp)
- **Concept:** Law of Cosines for computing triangle angles from side lengths. First validates that sides form a valid triangle using triangle inequality: a + b > c.
- **Formula:** For sides a, b, c and angle A opposite to side a:
  - $A = \cos^{-1}\left(\frac{b^2 + c^2 - a^2}{2bc}\right) \times \frac{180}{\pi}$ (convert from radians to degrees)
  - All three angles sum to 180°, so third angle = 180° - angle1 - angle2
- **Approach used:** sort sides; validate triangle inequality; apply Law of Cosines to each angle; convert radians to degrees; return sorted angles.
- **Time:** O(1). **Space:** O(1).

### Count Kth Roots in a Range
- File: [Maths/CountKthRootsInARange.cpp](Maths/CountKthRootsInARange.cpp)
- **Concept:** Find how many perfect k-th roots exist in range [l, r], i.e., count integers i where $i^k \in [l, r]$.
- **Approach used:** iterate from 1 upward; for each i compute $p = i^k$; count if $l \leq p \leq r$; early exit when $p > r$ (monotonic increasing property).
- **Edge case:** k=1 means every number is its own first root, so answer = r - l + 1.
- **Time:** O(r - l). **Space:** O(1).

### Minimum Operations to Make Array Modulo Alternating
- File: [Maths/MinimumOperationsToMakeArrayModuloAlternating1.cpp](Maths/MinimumOperationsToMakeArrayModuloAlternating1.cpp)
- **Concept:** Make array elements alternate between two remainder values (x at even indices, y at odd indices) when taken modulo k. Each operation changes one element's remainder by 1 (wrapping around 0 to k-1).
- **Distance formula:** for current remainder r and target remainder t:
  - $\text{distance} = \min(|r - t|, k - |r - t|)$ (shortest circular distance on modulo ring)
- **Approach used:** try all possible pairs (x, y) where x ≠ y (both in range [0, k-1]); for each pair, compute total cost as sum of distances for all elements to their alternating targets; track minimum cost.
- **Time:** O(k² × n). **Space:** O(1).

### Minimum Operations to Sort a Permutation
- File: [Maths/MinimumOperationsToSortAPermutation.cpp](Maths/MinimumOperationsToSortAPermutation.cpp)
- **Concept:** Permutation of [0..n-1] can be sorted by rotations (left/right circular shifts) or a single reversal. Find minimum operation count.
- **Approach used:** locate index of 0; check if left-rotating or right-rotating by that position yields sorted array; check if reversing yields sorted array; compute cost for each valid option (rotation = 1 operation + right/left shift indices, reversal = 1 operation).
- **Time:** O(n). **Space:** O(1).

### Minimum Time to Complete All Deliveries
- File: [Maths/MinimumTimeToCompleteAllDeliveries.cpp](Maths/MinimumTimeToCompleteAllDeliveries.cpp)
- **Concept:** Two independent delivery persons with repeat rates r[0] and r[1] must collectively deliver d[0] and d[1] items within time t. Find minimum t.
- **Key formulas:**
  - Deliveries by person i in time t: $c_i = t - \lfloor t / r_i \rfloor$ (total time minus "rest" periods)
  - $\text{LCM}(r_0, r_1) = \frac{r_0 \times r_1}{\gcd(r_0, r_1)}$ (period when both deliver simultaneously)
  - Inclusion-Exclusion for shared deliveries: $\text{shared} = c_0 + c_1 - t + \lfloor t / \text{LCM} \rfloor$
  - Exclusive deliveries: $\text{exclusive}_i = c_i - \text{shared}$
- **Approach used:** binary search on time t in range [d[0] + d[1], 2×10¹¹]; for each t, compute achievable deliveries using GCD/LCM and inclusion-exclusion; check if d[0] and d[1] are achievable with shared/exclusive counts.
- **Time:** O(log(2×10¹¹)). **Space:** O(1).

### Reverse Integer
- File: [Maths/ReverseInteger.cpp](Maths/ReverseInteger.cpp)
- **Concept:** Reverse the decimal digits of a signed 32-bit integer x, with overflow check (return 0 if result is out of [-2³¹, 2³¹ - 1] range).
- **Approach used:** extract digits via modulo operator (digit = x % 10); build reversed number by accumulating reversed = reversed × 10 + digit; before each multiplication, check if reversed would overflow using: $\text{INT\_MAX} / 10 < \text{reversed}$ or $\text{INT\_MIN} / 10 > \text{reversed}$.
- **Overflow prevention:** avoid constructing full number until overflow check passes.
- **Time:** O(log x) [number of digits]. **Space:** O(1).

### Strictly Palindromic Number
- File: [Maths/StrictlyPalindromicNumber.cpp](Maths/StrictlyPalindromicNumber.cpp)
- **Concept:** A number is strictly palindromic if its representation is a palindrome in ALL bases b where 2 ≤ b ≤ n - 2.
- **Base conversion formula:** to represent n in base b, repeatedly divide: $\text{digit}_i = n \mod b$, then $n := \lfloor n / b \rfloor$ until n = 0.
- **Example:** n = 9, base (n - 2) = 7: 9 = 1×7 + 2, so digits are [1, 2] (not palindrome). For n = 9 in all bases 2 to 7, it's never palindromic in all of them (no such numbers exist for n ≥ 4).
- **Approach used:** represent n in base (n - 2) using repeated modulo/division; check if digit sequence reads the same forwards and backwards.
- **Time:** O(log n) [base conversion depth]. **Space:** O(1).
