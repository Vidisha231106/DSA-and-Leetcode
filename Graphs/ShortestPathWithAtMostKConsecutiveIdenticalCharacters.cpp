// 3970

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        priority_queue <vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 1}); // distance from 0, node, count
        vector<vector<pair<int, int>>> v(n);
        int m=edges.size();
        for (int i=0; i<m;i++){
            v[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        vector<vector<int>> visited(n, vector<int> (k+1, INT_MAX));
        visited[0][1]=0;
        while (pq.empty()!=true){
            int dist=pq.top()[0];
            int node=pq.top()[1];
            int count=pq.top()[2];
            pq.pop();
            if (visited[node][count]<dist) continue;
            if (node==n-1) return dist;
            int x=v[node].size();
            for (int i=0; i<x; i++){
                int curr_count=(labels[node]==labels[v[node][i].first])?count+1: 1;
                if (curr_count>k) continue;
                if (v[node][i].second+dist<visited[v[node][i].first][curr_count]){
                    visited[v[node][i].first][curr_count]=v[node][i].second+dist;
                    pq.push({v[node][i].second+dist, v[node][i].first, curr_count});
                }
            }
        }
        int x=visited[n-1].size();
        int answer=INT_MAX;
        for (int i=0; i<x; i++){
            answer=min(answer, visited[n-1][i]);
        }
        if (answer==INT_MAX) return -1;
        return answer;
    }
};