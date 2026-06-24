// 463

class Solution {
public:
    int ans=0;
    int dfs(vector<vector<int>>& grid, int r, int c){
        if (r<0 || r>grid.size()-1 || c<0 || c>grid[0].size()-1) return 1;
        if (grid[r][c]==0) return 1;
        if (grid[r][c]==-1) return 0;
        grid[r][c]=-1;
        return dfs(grid, r-1, c)+dfs(grid, r+1, c)+dfs(grid, r, c-1)+dfs(grid, r, c+1);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for (int i=0; i<n ;i++){ 
            for (int j=0; j<m; j++){ 
                if (grid[i][j]==1) return dfs(grid, i, j); 
            } 
        }
        return 0;
    }
};

