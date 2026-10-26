class Solution {
public:
    vector<long long> sums;
    vector<vector<int>> dir={{0,1}, {1,0}, {-1, 0}, {0,-1}};
    long long dfs(int i, int j, vector<vector<int>>& visited, int n, int m, vector<vector<int>>& grid){
        if (i>=n || i<0 || j>=m || j<0) return 0;
        if (visited[i][j]!=0 || grid[i][j]==0) return 0;
        visited[i][j]=1;
        long long curr=grid[i][j];
        for(int k=0; k<4; k++){
            int ni=i+dir[k][0];
            int nj=j+dir[k][1];
            curr+=dfs(ni, nj, visited, n, m, grid);
        }        
        visited[i][j]=2;
        return curr;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (grid[i][j]!=0 && visited[i][j]==0) {
                    //cout<<"here: "<<endl;
                    sums.push_back(dfs(i, j, visited, n, m, grid));
                }
            }
        }
        int count=0;
        for(long long x: sums){
            if (x%k==0) count++;
        }
        return count;
    }
};