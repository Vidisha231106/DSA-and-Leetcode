// 188

class Solution {
public:
    int NEGATIVE=-1e9;
    int maxProfit(int K, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int> (K+1,NEGATIVE)));
            dp[0][1][0]=-prices[0];
            dp[0][0][0]=0;
        for (int i=1; i<n; i++){
            dp[i][0][0]=max(dp[i-1][0][0], dp[i-1][1][0]);
            dp[i][1][0]=max(dp[i-1][1][0]+0, -prices[i]+dp[i-1][0][0]);
            for (int k=1; k<=K; k++){
                dp[i][1][k]=max(dp[i-1][1][k]+0, -prices[i]+dp[i-1][0][k]);
                dp[i][0][k]=max(dp[i-1][0][k]+0, prices[i]+dp[i-1][1][k-1]);
            }
        }
        int ans=INT_MIN;
        for (int i=0; i<=K; i++){
            ans=max(ans, dp[n-1][0][i]);
        }
        return ans;
    }
};