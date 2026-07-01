class Solution {
public:
    unordered_set <int> s; // terminal nodes
    bool dfs(vector<vector<int>> &graph, int curr, vector<int>& condition){
        if (curr>=graph.size()) return true;
        if (condition[curr]==1) return false; // cycle detected
        else if (condition[curr]==2) return true; // already checked, safe
        else if (condition[curr]==0) return false; // already checked, not safe
        condition[curr]=1;
        int n=graph[curr].size();
        for (int i=0; i<n; i++){
            if (dfs(graph, graph[curr][i], condition)==false){
                condition[curr]=0;
                return false;
            }
        }
        condition[curr]=2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> condition(n, -1); 
        // [-1: dfs not done], 
        // [0: dfs done, not a safe node], 
        // [1: in dfs stack, maybe safe node],
        // [2: dfs done, safe node];
        unordered_set<int> answer;
        for (int i=0; i<n; i++){
            if (graph[i].size()==0) {
                condition[i]=2;
            }
        }
        for (int i=0; i<n; i++){
            if (dfs(graph, i, condition)==true) {
                answer.insert(i);
            }
        }
        vector<int> a(answer.begin(), answer.end());
        sort(a.begin(), a.end());
        return a;
    }
};