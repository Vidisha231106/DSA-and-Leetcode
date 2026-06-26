// 200

class Solution {
public:
    int count=0; 
    void dfs(vector<vector<char>>& grid, int r, int c, int m, int n){
        if (r<0 || r>m-1 || c<0 || c>n-1) return;
        grid[r][c]='0';
            dfs(grid, r-1, c, m, n);
            dfs(grid, r+1, c, m, n);
            dfs(grid, r, c-1, m, n);
            dfs(grid, r, c+1, m, n);        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]=='1'){
                    dfs(grid, i, j, m,n);
                    count++;
                }
            }
        }
        return count;
    }
};