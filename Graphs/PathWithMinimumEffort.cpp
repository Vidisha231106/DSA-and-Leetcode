// 1631

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        //we want more gradient steps
        priority_queue <vector<int>, vector<vector<int>>, greater<>> pq;//{weight, x, y}
        pq.push({0, 0,0});
        vector<int> dir_x={-1, 1, 0, 0};
        vector<int> dir_y={0, 0, -1, 1};
        vector<vector<int>> v(n, vector<int> (m, INT_MAX));
        v[0][0]=0;
        while (pq.empty()!=true){
            int diff=pq.top()[0];
            int x=pq.top()[1];
            int y=pq.top()[2];
            pq.pop();
            if (diff>v[x][y]) continue;
            if (x==n-1 && y==m-1) return diff;
           
            for (int i=0; i<4; i++){
                if (x+dir_x[i]<0 ||x+dir_x[i]>=heights.size()) continue;
                if (y+dir_y[i]<0 ||y+dir_y[i]>=heights[0].size()) continue;
                if (v[x+dir_x[i]][y+dir_y[i]]>max(diff, abs(heights[x+dir_x[i]][y+dir_y[i]]-heights[x][y]))){
                    v[x+dir_x[i]][y+dir_y[i]]=max(diff, abs(heights[x+dir_x[i]][y+dir_y[i]]-heights[x][y]));
                    pq.push({max(diff, abs(heights[x+dir_x[i]][y+dir_y[i]]-heights[x][y])), x+dir_x[i], y+dir_y[i]});
                }
            }
        }
        return v[n-1][m-1];
    }
};