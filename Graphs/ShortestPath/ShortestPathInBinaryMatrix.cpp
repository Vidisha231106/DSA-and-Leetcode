class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if (grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        queue <vector<int>> q;
        q.push({0, 0, 1});
        vector<int> dir={-1, 0, 1};
        int ans=n*n;
        while (q.empty()!=true){
            int x=q.front()[0];
            int y=q.front()[1];
            int dist=q.front()[2];
            if (x==n-1 && y==n-1) return dist;
            q.pop();
            for (int i=0; i<3; i++){
                for (int j=0; j<3; j++){
                    if (i==1 && j==1) continue;
                    if (x+dir[i]<0 || x+dir[i]>=n || y+dir[j]<0 || y+dir[j]>=n) continue;
                    if (grid[x+dir[i]][y+dir[j]]==0) {
                        grid[x+dir[i]][y+dir[j]]=1;
                        q.push({x+dir[i], y+dir[j], dist+1});
                        ans=min(ans, dist+1);
                    }
                }
            }
        }
        return -1;
    }
};