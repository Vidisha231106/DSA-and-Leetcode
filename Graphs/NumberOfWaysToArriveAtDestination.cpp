// 1976

 class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int m=roads.size();
        vector<vector<pair<int, long long>>> adj(n);
        for (int i=0; i<m; i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});//both directions
        }
        vector<long long> visited(n, LLONG_MAX);
        vector<int> ways(n, 0);
        ways[0]=1;
        priority_queue <vector<long long>, vector<vector<long long>>, greater<>> pq; //distance, node
        pq.push({0, 0});
        visited[0]=0;
        while (pq.empty()!=true){
            int curr=pq.top()[1];
            long long time=pq.top()[0];
            pq.pop();
            if (time> visited[curr]) continue;
            int x = adj[curr].size();
            for (int i=0; i<x; i++){
                if (visited[adj[curr][i].first]>time+adj[curr][i].second){
                    visited[adj[curr][i].first]=time+adj[curr][i].second;
                    ways[adj[curr][i].first]=ways[curr];
                    pq.push({visited[adj[curr][i].first], adj[curr][i].first});
                }
                else if (visited[adj[curr][i].first]==time+adj[curr][i].second){
                    ways[adj[curr][i].first]=(ways[curr]+ways[adj[curr][i].first])%(1000000000+7);
                }
            }
        }
        return ways[n-1];
    }
};