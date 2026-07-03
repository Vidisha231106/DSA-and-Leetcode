/*
The intuition to remember

The only reason Dijkstra needs a priority queue is that cycles can cause a shorter path to be discovered later.

A DAG has no cycles, so processing nodes in topological order guarantees that when you reach a node, all possible ways of reaching it have already been considered. That lets you compute shortest paths with a single pass of dynamic programming instead of repeatedly extracting the minimum-distance node.*/


//BETTER APPROACH:

class Solution {
public:
    bool check(int mid, vector<vector<pair<int, long long>>> &adj, vector<bool> &online, long long k, int n) {

        vector<int> indegree(n, 0);

        // Compute indegree considering only valid edges
        for (int u = 0; u < n; u++) {
            if (!online[u] && u != 0 && u != n - 1) continue;

            for (auto &it : adj[u]) {
                int v = it.first;
                long long wt = it.second;

                if (wt < mid) continue;
                if (!online[v] && v != n - 1) continue;

                indegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if ((!online[i] && i != 0 && i != n - 1)) continue;

            if (indegree[i] == 0)
                q.push(i);
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &it : adj[node]) {
                int next = it.first;
                long long wt = it.second;

                if (wt < mid) continue;
                if (!online[next] && next != n - 1) continue;

                if (dist[node] != LLONG_MAX)
                    dist[next] = min(dist[next], dist[node] + wt);

                indegree[next]--;

                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int, long long>>> adj(n);

        int maxEdge = 0;

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            maxEdge = max(maxEdge, e[2]);
        }

        int left = 0;
        int right = maxEdge;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (check(mid, adj, online, k, n)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};

//MY SOLUTION: I USED DIJKSTRAS

class Solution {
public:
    bool check(int mid, vector<vector<pair<int, long long>>> &v, vector<bool>& online, long long k, int n){
        priority_queue <vector<long long>, vector<vector<long long>>, greater<>> pq;
        pq.push({0,0}); //0 distance, 0th node, largest edge distance
        vector<long long> visited(n, LLONG_MAX);
        visited[0]=0;
        while (pq.empty()!=true){
            long long dist=pq.top()[0];
            int node=pq.top()[1];
            pq.pop();
            if (online[node]==false) continue;
            if (dist>visited[node]) continue;
            int x= v[node].size();
            for (int i=0; i<x; i++){
                if (v[node][i].second<mid) continue;
                if (online[v[node][i].first]!=1) continue;
                if ((long long)(dist+v[node][i].second)<visited[v[node][i].first]){
                    visited[v[node][i].first]=(long long)(dist+v[node][i].second);
                    pq.push({dist+v[node][i].second, v[node][i].first});
                }
            }
        } 
        return visited[n-1]<=k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int x=edges.size();
        int n=online.size();
        vector<vector<pair<int, long long>>> v(n);
        int max_edge=0;
        for (int i=0; i<x; i++){
            v[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            max_edge=max(max_edge, edges[i][2]);
        }
        int answer=0;
        int left=0; 
        int right=max_edge;
        int flag=0; 
        while (left<=right){
            int mid=(left+right)/2;
            if (check (mid, v, online,k,n)==true){
                answer=mid;
                left=mid+1;
                flag=1;
            }
            else {
                right=mid-1;
            }
        }
        if (flag==0) return -1;
        return answer;
    }
};