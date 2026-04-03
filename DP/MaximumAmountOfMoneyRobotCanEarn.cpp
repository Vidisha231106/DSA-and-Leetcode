// 3418

class Solution {
public:
    int recursion(vector<vector<int>> & coins, vector<vector<vector<int>>>& dp, int i, int j, int lives){
        if (i<0 || j<0) return -1e9;
        if (i==0 && j==0){
            if (coins[i][j]<0 && lives>0){
                return 0;
            }
            return coins[i][j];
        }
        if (dp[i][j][lives]!=INT_MIN) return dp[i][j][lives];
        int left = recursion(coins, dp, i, j-1, lives);
        int up = recursion(coins, dp, i-1, j, lives);
        int best = max(left, up);
        if (coins[i][j]>=0){
            dp[i][j][lives]=coins[i][j]+best;
        }
        else{
            int loss_incurred=coins[i][j]+best;
            int used_life=INT_MIN;
            if (lives>0){
                int left_neutralise = recursion(coins, dp, i, j-1, lives-1);
                int up_neutralise=recursion(coins, dp, i-1, j, lives-1);
                used_life = max(left_neutralise, up_neutralise);
            }
            dp[i][j][lives]= max(used_life, loss_incurred);
        }
        return dp[i][j][lives];
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector <vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int> (3, INT_MIN)));
        return recursion(coins, dp, m-1, n-1, 2);
    }
};