# Sliding Window

This folder covers fixed and variable window patterns: at-most counting, two pointers, and window contraction with frequency tracking. Use this to revise window invariants and counting tricks.

## Problems and approaches

### Binary Subarrays With Sum
- File: [SlidingWindow/BinarySubarraysWithSum.cpp](SlidingWindow/BinarySubarraysWithSum.cpp)
- Approach used: count subarrays with sum <= goal and goal-1, subtract.
- Time: O(n). Space: O(1).

### Container With Most Water
- File: [SlidingWindow/ContainerWithMostWater.cpp](SlidingWindow/ContainerWithMostWater.cpp)
- Approach used: two pointers moving the smaller height.
- Time: O(n). Space: O(1).

### Count Number of Nice Subarrays
- File: [SlidingWindow/CountNoOfNiceSubarrays.cpp](SlidingWindow/CountNoOfNiceSubarrays.cpp)
- Approach used: count subarrays with exactly k odds using prefixes in window.
- Time: O(n). Space: O(1).

### Count Vowel Substrings of a String
- File: [SlidingWindow/CountVowelSubstringsOfAString.cpp](SlidingWindow/CountVowelSubstringsOfAString.cpp)
- Approach used: custom window with map and shrink logic; includes better solution using atMost(k) - atMost(k-1).
- Time: O(n). Space: O(1) or O(1) map.

### Longest Subarray of 1s After Deleting One Element
- File: [SlidingWindow/LongestSubarrayOf1sAfterDeletingOneElement.cpp](SlidingWindow/LongestSubarrayOf1sAfterDeletingOneElement.cpp)
- Approach used: window with at most one zero; answer is window size minus one.
- Time: O(n). Space: O(1).

### Longest Substring Without Repeating Characters
- File: [SlidingWindow/LongestSubstringWithoutRepeatingCharacters.cpp](SlidingWindow/LongestSubstringWithoutRepeatingCharacters.cpp)
- Approach used: expand right; shrink until all unique using freq map.
- Time: O(n). Space: O(1) or O(128).

### Max Consecutive Ones III
- File: [SlidingWindow/MaxConsecutiveOnes3.cpp](SlidingWindow/MaxConsecutiveOnes3.cpp)
- Approach used: window with at most k zeros.
- Time: O(n). Space: O(1).

### Maximum Number of Vowels in a Substring of Given Length
- File: [SlidingWindow/MaximumNumberOfVowelsInASubstringOfGivenLength.cpp](SlidingWindow/MaximumNumberOfVowelsInASubstringOfGivenLength.cpp)
- Approach used: fixed window with vowel count.
- Time: O(n). Space: O(1).

### Max Points You Can Obtain from Cards
- File: [SlidingWindow/MaxPointsYouCanObtainFromCards.cpp](SlidingWindow/MaxPointsYouCanObtainFromCards.cpp)
- Approach used: take k from left then slide by removing left, adding from right.
- Time: O(k). Space: O(1).

### Number of Substrings Containing All Three Characters
- File: [SlidingWindow/NoOfSubstringsContainingAll3Characters.cpp](SlidingWindow/NoOfSubstringsContainingAll3Characters.cpp)
- Approach used: window counts a/b/c; for each valid right, add (n-right).
- Time: O(n). Space: O(1).

### Arithmetic Slices
- File: [SlidingWindow/ArithematicSlices.cpp](SlidingWindow/ArithematicSlices.cpp)
- Approach used: for each starting index, expand right counting contiguous slices with same arithmetic difference; break when difference changes; any subarray of length ≥ 3 with same diff is counted.
- Time: O(n^2) worst case. Space: O(1).
- Better approach: single pass counting: whenever the difference between consecutive elements stays the same, increment a running count and add it to the total; reset to 0 on diff change.

| Aspect | Current approach | Better approach |
| --- | --- | --- |
| Time | O(n^2) nested | O(n) single pass |
| Logic | Brute expand | Running count accumulation |

### Longest Turbulent Window (Subarray)
- File: [SlidingWindow/LongestTurbulentWindow.cpp](SlidingWindow/LongestTurbulentWindow.cpp)
- Approach used: variable-size window; maintain left pointer; advance right pointer, shrinking left when the turbulence pattern breaks (equal adjacent elements or direction not alternating); track maximum window length.
- Time: O(n). Space: O(1).

### Minimum Window Substring
- File: [SlidingWindow/MinimumWindowSubstring.cpp](SlidingWindow/MinimumWindowSubstring.cpp)
- Approach used: variable window with frequency map of target t; expand right adding characters, track `count` of matched characters; when count == len(t), shrink from left to minimize window; record smallest valid window.
- Time: O(n+m). Space: O(|alphabet|).

