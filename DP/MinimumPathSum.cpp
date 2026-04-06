// 64

class Solution {
public:
    int recursion(vector<vector<int>> &dp, vector<vector<int>>& grid, int i, int j){
        if (i<0 || j<0) return 1e9;
        if (i==0 && j==0) return grid[i][j];
        if (dp[i][j]!=-1) return dp[i][j];
        int left=grid[i][j]+recursion(dp, grid, i,j-1);
        int up = grid[i][j]+recursion(dp, grid, i-1, j);
        dp[i][j]=min(left, up);
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return recursion(dp, grid, m-1, n-1);
    }
};