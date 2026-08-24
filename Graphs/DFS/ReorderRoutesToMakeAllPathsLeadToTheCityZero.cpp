// 1466

class Solution {
public:
    int count=0;
    unordered_map <int, vector<int>> mp;
    vector<int> visited;
    void dfs(set<vector<int>> &s, int curr){
        if (visited[curr]==1) return;
        visited[curr]=1;
        //cout<<curr<<endl;
        for(int x: mp[curr]){
            if (visited[x]==0 && s.contains({x, curr})!=true){
                cout<<curr<<" , "<<x<<endl;
                count++;
            }
            dfs(s, x);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        set<vector<int>> s(connections.begin(), connections.end());
        visited.resize(n, 0);
        int x=connections.size();
        for (int i=0; i<x; i++){
            mp[connections[i][0]].push_back(connections[i][1]);
            mp[connections[i][1]].push_back(connections[i][0]);
        }
        
        dfs(s, 0);
        return count;
    }
};