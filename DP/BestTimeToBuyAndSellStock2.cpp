//122

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector <pair<int,int>> dp(n);
        dp[0].first=0;
        dp[0].second=-prices[0];
        for (int i=1; i<n;i++){
            dp[i].first=max(dp[i-1].first, dp[i-1].second+prices[i]); // do nothing or sell
            dp[i].second=max(dp[i-1].second, dp[i-1].first-prices[i]); // do nothing or buy
        }
        return dp[n-1].first;
    }
};