// 3742

// wrong answer - incorrect solution (passes for 435 testcases)

class Solution {
public:
    int cost(int n){
        if (n==0) return 0;
        return 1;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        // dp[i][j] = (score, cost)
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, {-1,INT_MAX}));

        dp[0][0]={grid[0][0], cost(grid[0][0])}; // for the first cell you can directly take the cost

        for (int i=1; i<n; i++){
            if (dp[i-1][0].first==-1) continue;
            dp[i][0].first= dp[i-1][0].first+ grid[i][0];
            dp[i][0].second=dp[i-1][0].second + cost(grid[i][0]);
            if (dp[i][0].second>k ) dp[i][0].first=-1; 
        }
        for (int i=1; i<m; i++){
            if (dp[0][i-1].first==-1) continue;
            dp[0][i].first= dp[0][i-1].first+ grid[0][i];
            dp[0][i].second=dp[0][i-1].second + cost(grid[0][i]);
            if (dp[0][i].second>k ) dp[0][i].first=-1; 
        }
        for (int i=1; i<n; i++){
            for (int j=1; j<m; j++){

                int down_score = grid[i][j] + dp[i-1][j].first;
                if (dp[i-1][j].first==-1 || dp[i-1][j].second + cost(grid[i][j]) > k) down_score=-1;
                int right_score = grid[i][j] + dp[i][j-1].first;
                if (dp[i][j-1].first==-1 || dp[i][j-1].second + cost(grid[i][j]) > k) right_score=-1;
                dp[i][j].first= max(down_score, right_score);
                if(dp[i][j].first==-1) continue;
                if (dp[i][j].first == down_score) dp[i][j].second = dp[i-1][j].second + cost(grid[i][j]);
                else dp[i][j].second = dp[i][j-1].second + cost(grid[i][j]);
            }
        }
        return dp[n-1][m-1].first;
    }
};