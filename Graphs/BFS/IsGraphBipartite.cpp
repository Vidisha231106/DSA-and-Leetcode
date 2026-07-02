// 785

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector <int> v(n, -1);
        for (int k=0; k<n; k++){
            if (v[k]!=-1) continue;
            queue<int> q;
            v[k]=0;
            q.push(k);
            while (q.empty()!=true){
                int i=q.front();
                q.pop();
                int m=graph[i].size();
                for (int j=0; j<m; j++){
                    
                    if (v[graph[i][j]]==-1){
                        v[graph[i][j]]=1-v[i];
                        q.push(graph[i][j]);
                    }
                    else{
                        if (v[i]==v[graph[i][j]]) return false;
                    }
                    
                }
            }
        }
        return true;
    }
};