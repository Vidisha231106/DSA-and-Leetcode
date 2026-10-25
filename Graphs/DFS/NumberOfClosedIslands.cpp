// 1254

class Solution {
public:
    //,{-1, -1},{1,-1},{-1,1},{1,1}
    vector<vector<int>> dir={{0,1}, {1,0},{0,-1},{-1,0}};
    bool dfs(int i, int j, vector<vector<int>> &visited, int n, int m, vector<vector<int>>& grid){
        if (i>=n || i<0 || j>=m || j<0) return false;
        if (visited[i][j]==2) return true;
        if (visited[i][j]==1 || grid[i][j]==1) {
            return true;
        }
        visited[i][j]=1;
        bool loop=true;
        for(int x=0; x<4; x++){
            int ni=dir[x][0]+i;
            int nj=dir[x][1]+j;
            //if (grid[ni][nj]==1) continue;
            if (dfs(ni, nj, visited, n, m, grid)==false){
                loop=false;
            }
        }
        visited[i][j]=2;
        return loop;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>> visited(n, vector<int> (m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (grid[i][j]==0 && visited[i][j]==0)
                ans+=dfs(i,j, visited, n, m, grid);
            } 
        }
        return ans;
    }
};