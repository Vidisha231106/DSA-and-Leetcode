// 375 - VERY VERY IMPORTANT

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));
        for (int left=n; left>=1; left--){
            for (int right=left+1; right<=n; right++){
                dp[left][right]= INT_MAX;
                for (int pivot=left; pivot<=right; pivot++){
                    dp[left][right]=min(dp[left][right], pivot+ max(dp[left][pivot-1], dp[pivot+1][right]));
                }
            }
        }
        return dp[1][n];
    }
};