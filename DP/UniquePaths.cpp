// 62

class Solution {
public:
    int recursion(vector<vector<int>> &dp, int i, int j){
        if (i<0 || j<0) return 0;
        if (i==0 && j==0) return 1;
        if (dp[i][j]!=-1) return dp[i][j];
        int left = recursion(dp, i, j-1);
        int down= recursion(dp, i-1, j);
        dp[i][j]=left+down;
        return left+down;
    }
    int uniquePaths(int m, int n) {
        vector <vector<int>> dp(m, vector<int> (n,-1));
        return recursion(dp, m-1, n-1);
    }
};