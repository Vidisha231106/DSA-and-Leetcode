// 778

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<vector<int>, vector<vector<int>> , greater<>> pq;
        // curr time, curr max, x, y
        vector<vector<int>> dir={{-1,0}, {1, 0}, {0, -1}, {0, 1}};
        pq.push({grid[0][0], 0 ,0});
        vector<vector<int>> visited(n, vector<int> (m, INT_MAX));
        while (pq.empty()!=true){
            int x=pq.top()[1];
            int y=pq.top()[2];
            int time=pq.top()[0];
            pq.pop();
            if (x==n-1 && y==m-1) return time;
            for(int i=0; i<4; i++){
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];
                if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if (visited[nx][ny]>time) {
                    visited[nx][ny]=time;
                    pq.push({max(grid[nx][ny], time), nx, ny});
                }
            }
        }
        return visited[n-1][m-1];
    }
};