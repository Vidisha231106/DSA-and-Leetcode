// 3341

class Solution {
public:
    bool check(int r, int c, int n, int m){
        if (r<0 || r>=n || c<0 || c>=m) return false;
        return true;
    }
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
        visited[0][0]=moveTime[0][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // {curr_time, row, col}
        vector<pair<int, int>> dir={{0,1}, {1,0}, {0,-1},{-1,0}};
        pq.push({0,0, 0});
        while (pq.empty()==false){
            int t=pq.top()[0];
            int r=pq.top()[1];
            int c=pq.top()[2];
            pq.pop();
            if (visited[r][c]<t){
                continue;
            }
            for(int i=0; i<4; i++){
                int nr=r+dir[i].first;
                int nc=c+dir[i].second;
                if (check(nr,nc , n, m)==false) continue;
                int final_time=max(t, moveTime[nr][nc])+1;
                if (final_time<visited[nr][nc]){
                    visited[nr][nc]=final_time;
                    pq.push({final_time, nr, nc});
                }
            }
        }
        return visited[n-1][m-1];
    }
};