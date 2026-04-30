// 343

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        // multiples of 2, multiples of 3
        dp[0]=0;
        dp[1]=1;
        for (int i=2; i<=n; i++){
            for (int j=1; j<=i; j++){
                dp[i]=max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }
        return dp[n];
    }
};


/*
IMPORTANT:

Code (Optimal O(1)):
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;

        if (n % 3 == 0) return pow(3, n / 3);
        if (n % 3 == 1) return pow(3, n / 3 - 1) * 4;
        return pow(3, n / 3) * 2;
    }
};

*/