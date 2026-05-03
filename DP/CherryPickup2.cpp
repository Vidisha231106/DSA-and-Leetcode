// 1463

class Solution {
public:
    int recursion(vector<vector<vector<int>>>& dp, vector<vector<int>>& grid, int r, int c1, int c2, int n, int m){
        if (c1<0 || c2<0 ||c1>m-1 || c2>m-1 ) return -2;
        if (dp[r][c1][c2]!=-1) return dp[r][c1][c2];

        int cherry_num = (c1==c2)? grid[r][c1]:grid[r][c1]+grid[r][c2];
        if (r==n-1) {
            dp[r][c1][c2] = cherry_num;
            return cherry_num;
        }
        int result=INT_MIN;
        for (int i=-1; i<=1; i++){
            for (int j=-1; j<=1; j++){
                
                int answer = recursion(dp,grid, r+1, c1+i, c2+j, n, m);
                if (answer!=-2) result=max(result, cherry_num+answer);
            }
        }
        dp[r][c1][c2]=result;
        return result;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));
        return recursion(dp, grid, 0, 0, m-1, n, m);
    }
};