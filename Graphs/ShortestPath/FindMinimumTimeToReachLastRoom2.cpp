// 3342

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
        priority_queue <vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0, 1});
        vector<pair<int, int>> dir={{0, -1}, {0,1},{-1, 0},{1, 0}};
        while(pq.empty()!=true){
            int t=pq.top()[0];
            int r=pq.top()[1];
            int c=pq.top()[2];
            int penalty=pq.top()[3];
            pq.pop();
            if (t>visited[r][c]) continue;
            for(int i=0; i<4; i++){
                int nr=r+dir[i].first;
                int nc=c+dir[i].second;
                if (check(nr, nc, n, m)==false) continue;
                int final_time=max(t, moveTime[nr][nc])+penalty;
                if (final_time<visited[nr][nc]){
                    visited[nr][nc]=final_time;
                    int new_penalty=(penalty==1)?2:1;
                    pq.push({final_time, nr, nc, new_penalty});
                }
            }
        }
        return visited[n-1][m-1];
    }
};