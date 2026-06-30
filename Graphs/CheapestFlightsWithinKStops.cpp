// 787

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m=flights.size();
        priority_queue <vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, src, 0});// distance, source, stops
        vector<vector<int>> visited(k+2,vector<int>(n,INT_MAX));
        visited[0][src]=0;
        vector <vector<pair<int, int>>> v(n);// adjacency list

        for (int i=0; i<m; i++){
            v[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        } 
        while (pq.empty()!=true){
            int stops=pq.top()[2];
            int curr_src=pq.top()[1];
            int dist=pq.top()[0];
            pq.pop();
            if (curr_src==dst) return dist;
            if (stops>k+1) continue;
            
            int x=v[curr_src].size();
            for (int i=0; i<x; i++){
                if (stops<k+1 && dist+v[curr_src][i].second<visited[stops+1][v[curr_src][i].first]){
                    visited[stops+1][v[curr_src][i].first]=dist+v[curr_src][i].second;
                    pq.push({dist+v[curr_src][i].second , v[curr_src][i].first,stops+1 });
                }
            }
        }
        return -1;
    }
};