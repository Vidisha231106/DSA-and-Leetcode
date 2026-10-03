// 329

class Solution {
public:
    int dfs(vector<vector<int>> &dp, int x, int y, vector<vector<int>>& matrix, int n, int m){
        if (dp[x][y]!=0){
            return dp[x][y];
        }
        vector<vector<int>> dir={{0,1}, {0,-1},{-1,0},{1,0}};
        int max_dist=1;
        for(int i=0; i<4; i++){
            int nx=dir[i][0]+x;
            int ny=dir[i][1]+y;
            if (nx>=n || nx<0 || ny>=m || ny<0) continue;
            if (matrix[nx][ny]<=matrix[x][y]) continue;
            max_dist=max(max_dist,1+dfs(dp, nx, ny, matrix, n, m));
        }
        dp[x][y]=max_dist;
        return max_dist;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m,0));
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans=max(ans,dfs(dp, i, j, matrix, n, m));
            }
        }
        return ans;
    }
};