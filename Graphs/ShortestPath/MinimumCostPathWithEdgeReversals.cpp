// 3650

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<vector<int>>> mp;
        for(vector<int> x: edges){
            mp[x[0]].push_back({x[2], x[1]});
            mp[x[1]].push_back({x[2]*2,x[0]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0});
        vector<int> visited(n, INT_MAX);
        visited[0]=0;
        // vector<vector<int>> dir={{0, -1}, {0, 1}, {1,0},{-1,0}};
        while(pq.empty()==false){
            vector<int> curr=pq.top();
            pq.pop();
            if (curr[0]>visited[curr[1]]) continue;
            //visited[curr[1]]=curr[0];
            int x=mp[curr[1]].size();
            for (int i=0; i<x; i++){
                if (mp[curr[1]][i][0]+curr[0]<visited[mp[curr[1]][i][1]]){
                    visited[mp[curr[1]][i][1]]=mp[curr[1]][i][0]+curr[0];
                    pq.push({visited[mp[curr[1]][i][1]], mp[curr[1]][i][1]});
                }
            }
        }
        if (visited[n-1]==INT_MAX) return -1;
        return visited[n-1];
    }
};