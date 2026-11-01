// 3882

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> visited(n, vector<vector<int>> (m, vector<int>(1024, 0)));
        queue<vector<int>> pq;
        pq.push({0,0, grid[0][0]});
        visited[0][0][grid[0][0]]=1;
        vector<vector<int>> dir={{0,1}, {1,0}};
        while (pq.empty()!=true){
            int x=pq.front()[0];
            int y=pq.front()[1];
            int xorrr=pq.front()[2];
            pq.pop();
            //if (visited[x][y][xorrr]==1) continue;
            //if (x==n-1 && y==m-1) continue;
            
            for (int i=0; i<2; i++){
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];
                if (nx>=n || ny>=m) continue;
                int nxorrr=xorrr ^ grid[nx][ny]; 
                if (visited[nx][ny][nxorrr]==0) {
                    visited[nx][ny][nxorrr]=1;
                    pq.push({nx, ny, nxorrr});
                }
            }
        }
        for(int k=0; k<1024; k++){
            if (visited[n-1][m-1][k]==1) return k;
        }
        return 0;
    }
};