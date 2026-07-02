// 1319

//COMPLETELY WRONG SOLUTION: 

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> v(n);
        int x=connections.size(); 
        // n = necessary + unnecessary connections
        for (int i=0; i<x; i++){
            v[connections[i][0]].push_back(connections[i][1]);
            v[connections[i][1]].push_back(connections[i][0]);
        }
        int unconnected_nodes=0;
        for (int i=0; i<n; i++){
            if (v[i].size()==0) unconnected_nodes++;
        }
        priority_queue <int, vector<int>, greater<int>> pq;
        pq.push(0);
        int necessary=0;
        vector<int> visited(n, 0);
        while (pq.empty()!=true){
            int node=pq.top();
            pq.pop();
            if (visited[node]==1) continue;
            int m=v[node].size();
            visited[node]=1;
            necessary++;
            for (int i=0; i<m; i++){
                if (visited[v[node][i]]==1) continue;
                pq.push(v[node][i]);
            }
        }
        // for n devices, i need minimum n-1 connections, rn i have necessary connections
        // if unnecessary connections are less than unconnected nodes return -1
        if ((n-necessary)<unconnected_nodes) return -1;
        return unconnected_nodes;
    }
};

// CORRECTED SOLUTION: 

class Solution {
public:
    void dfs(vector<vector<int>>& v, vector<int>& visited, int node){
        int x=v[node].size();
        visited[node]=1;
        for (int i=0; i<x; i++){
            if (visited[v[node][i]]==0) dfs(v, visited, v[node][i]);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n-1>connections.size()) return -1;
        vector<vector<int>> v(n);
        int x=connections.size(); 
        for (int i=0; i<x; i++){
            v[connections[i][0]].push_back(connections[i][1]);
            v[connections[i][1]].push_back(connections[i][0]);
        }
        int components=0; 
        vector<int> visited(n, 0);
        for (int i=0; i<n; i++){
            if (visited[i]==0){
                components++;
                dfs(v, visited, i);
            }
        }
        return components-1;
    }
};

// BETTER SOLUTION: 

class Solution {
public:

class DisjointSet{
    vector<int> parent, size;

    public:
        DisjointSet(int n){
            parent.resize(n+1);
            for(int i = 0; i<=n; i++) parent[i] = i;
            size.resize(n+1, 1);
        }

        int findUltP(int node){
            if(parent[node] == node) return node;
            return parent[node] = findUltP(parent[node]);
        }

        void Union(int u, int v){
            int ult_u = findUltP(u);
            int ult_v = findUltP(v);

            if(ult_u == ult_v) return;
            if(size[ult_u] >= size[ult_v]){
                parent[ult_v] = ult_u;
                size[ult_u] += size[ult_v];
            }
            else{
                parent[ult_u] = ult_v;
                size[ult_v] += size[ult_u];
            } 
            return;
        }
};
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra = 0;
        int need = 0;
        
        for(int i = 0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            if(ds.findUltP(u) == ds.findUltP(v)) extra++;
            else{
                // need++;
                ds.Union(u, v);
            }
        }

        for(int i = 0; i<n; i++){
            if(ds.findUltP(i) == i) need++;
        }
        need--;
        if(need>extra) return -1;
        else return need;

    }
};