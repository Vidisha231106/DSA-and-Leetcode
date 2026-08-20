// 174

class Solution {
public:
    vector<vector<int>> dir={{0, 1}, {1, 0}};
    int recursion(vector<vector<int>>& dungeon, vector<vector<int>>& dp, int r, int c, int m, int n){
        if(r<0 || c<0 || r>=m || c>=n) return INT_MAX;
        if (dp[r][c]!=INT_MIN) return dp[r][c];
        if (r==m-1 && c==n-1) return dp[r][c]=max(1, 1-dungeon[r][c]);
        int path=INT_MAX;
        for(int i=0; i<2; i++){
            path=min(path, recursion(dungeon, dp, r+dir[i][0], c+dir[i][1], m, n));
        }
        return dp[r][c]=max(1, path-dungeon[r][c]);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MIN));
        return recursion(dungeon, dp, 0, 0, m, n);
    }
};