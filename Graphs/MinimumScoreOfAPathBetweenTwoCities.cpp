// 2492

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int answer=INT_MAX;
        int x=roads.size();
        vector<vector<pair<int,int>>> v(n+1);
        for (int i=0; i<x; i++){
            v[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            v[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vector<int> visited(n+1 ,0);
        queue <int> q;
        q.push(1);
        while (q.empty()!=true){
            int node=q.front();
            q.pop();
            if (visited[node]==1) continue;
            visited[node]=1;
            int x=v[node].size();
            for (int i=0; i<x; i++){
                answer=min(answer, v[node][i].second);
                if (visited[v[node][i].first]==0) q.push(v[node][i].first);
            }
        }
        return answer;
    }
};