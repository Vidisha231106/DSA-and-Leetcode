// 3857

//Mathematical solution - better

class Solution {
public:
    int minCost(int n) {
        return n*(n-1)/2;
    }
};

// DP solution

class Solution {
public:
    int minCost(int n) {
        // since it is optimal to split an integer x into 1 and x-1, we define dp[x] = 
        vector<int> dp(n+1, INT_MAX);
        dp[0]=0;
        dp[1]=0;
        for (int i=2; i<=n; i++){
            for (int j=i-1; j>=0; j--){
                dp[i]=min(dp[i-j]+dp[j]+j*(i-j), dp[i]);
            }
        }
        return dp[n];
    }
};