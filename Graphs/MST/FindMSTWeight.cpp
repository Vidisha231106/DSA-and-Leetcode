// NOT IN LEETCODE, BUT PRESENT IN STRIVERS

class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue <vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0}); // distance, node
        int answer=0;
        vector<int> visited(V, 0);
        while (pq.empty()!=true){
            int dist=pq.top()[0];
            int node=pq.top()[1];
            
            pq.pop();
            
            if (visited[node]==1) continue;
            answer+=dist;
            visited[node]=1;
            int x=adj[node].size();
            for (int i=0; i<x; i++){
                if (visited[adj[node][i][0]] ==0){
                    pq.push({adj[node][i][1], adj[node][i][0]});
                }
            }
        }
        return answer;
    }
};
