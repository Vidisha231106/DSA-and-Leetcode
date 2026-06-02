//https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1


class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=wt.size();
        //dp[using this weight][max current weight of knapsack]
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        for (int i=1; i<=n; i++){
            for (int j=0; j<=W; j++){
                if (j>=wt[i-1]) dp[i][j]=max(dp[i-1][j], dp[i-1][j-wt[i-1]]+val[i-1]);
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][W];
    }
};