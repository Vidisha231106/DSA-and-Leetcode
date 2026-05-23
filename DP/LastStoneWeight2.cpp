// 1049

/*

INTUITION:

Suppose we smash two stones:

a >= b

After smashing:
a - b

This can be viewed as:
a + (-b)

Meaning:
one stone contributes positively,
the other negatively.

Eventually, after all smash operations,
every stone effectively gets either:

+ sign
or
- sign

So the final result becomes:

+s1 + s2 - s3 + s4 ...

This is equivalent to partitioning stones into TWO groups:

Group A sum = S1
Group B sum = S2

Final remaining stone becomes:

|S1 - S2|

Now since:

S1 + S2 = totalSum

=> S2 = totalSum - S1

Substitute:

|S1 - (totalSum - S1)|

= |totalSum - 2*S1|

So the problem reduces to:

Find a subset sum S1 such that:

|totalSum - 2*S1|

is minimized.

The minimum difference occurs when S1 is as close as possible to:

totalSum / 2

Therefore:
we use subset-sum / knapsack DP
to find the achievable subset sum
closest to totalSum/2.

*/


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum=0;
        for (int i=0; i<n; i++) sum+=stones[i];
        vector<int> dp((sum/2)+1, 0);
        dp[0]=1;
        for (int i=0; i<n; i++){
            for (int j=(sum/2); j>=stones[i]; j--){
                dp[j]=dp[j] || dp[j-stones[i]];
            }
        }
        for (int i=(sum/2); i>=0; i--){
            if (dp[i]) return sum-2*i;
        }
        return 0;
    }
};