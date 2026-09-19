// 1192

class Solution {
public:
    vector<vector<int>> ans;        
    unordered_map<int, vector<int>> mp;
    int timer=0;
    vector<int> low;
    vector<int> tin;
    vector<int> visited;
    void dfs(int node, int parent){
        tin[node]=low[node]=timer;
        timer++;
        visited[node]=1;
        for(int x:mp[node]){
            if (x==parent) continue;
            if (visited[x]==1){
                low[node]=min(low[node], tin[x]);
            }
            else{
                dfs(x, node);
                low[node]=min(low[node], low[x]);
                if (low[x]>tin[node]) ans.push_back({node,x});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int x=connections.size();
        for(int i=0; i<x; i++){
            mp[connections[i][0]].push_back(connections[i][1]);
            mp[connections[i][1]].push_back(connections[i][0]);
        }
        low.resize(n+1, 0);
        tin.resize(n+1, 0);
        visited.resize(n+1, 0);
        dfs(0, -1);
        return ans;
    }
};