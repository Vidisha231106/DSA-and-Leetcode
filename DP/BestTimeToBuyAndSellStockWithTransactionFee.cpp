// 714

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        vector <pair<int,int>> dp(n);
        dp[0].first=0;
        dp[0].second=-prices[0];
        for (int i=1; i<n; i++){
            dp[i].first= max(dp[i-1].first, dp[i-1].second+prices[i]-fee);// fees charged only once per transaction - i.e. during buying
            dp[i].second=max(dp[i-1].second, dp[i-1].first-prices[i]);
        }
        return dp[n-1].first;
    }
};