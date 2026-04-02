//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector <pair<int,int>> dp(n);
        dp[0].first= 0;
        dp[0].second = -prices[0];
        for (int i=1; i<n; i++){
            dp[i].first=max(dp[i-1].first, dp[i-1].second+prices[i]);
            if (i>1) dp[i].second=max(dp[i-1].second, dp[i-2].first-prices[i]);
            else dp[i].second = max(dp[i-1].second, -prices[1]);
        }
        return dp[n-1].first;
    }
};