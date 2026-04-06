// 120

class Solution {
public:
    int recursion(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int j, int &t, int &n){
        if (i>t || j>n) return 1e9;
        if (i==t-1) dp[i][j]=triangle[i][j];
        if (dp[i][j]!=INT_MIN) return dp[i][j];
        int first = triangle[i][j]+recursion(triangle, dp, i+1, j, t, n);
        int second= triangle[i][j]+recursion(triangle, dp, i+1, j+1, t, n);
        dp[i][j]=min(first, second);
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int t = triangle.size();
        int n = triangle[t-1].size();
        vector<vector<int>> dp(t, vector<int>(n, INT_MIN));
        return recursion(triangle, dp, 0, 0, t, n);
    }
};