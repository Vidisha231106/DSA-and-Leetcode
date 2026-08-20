// 3310

class Solution {
public:
    unordered_set<int> sus;
    unordered_map <int, vector<int>> children;
    unordered_map<int, vector<int>> parent;
    void dfs(unordered_map <int, vector<int>> &mp, int k){
        if (mp.contains(k)==false) return;
        for (int x: mp[k]){
            if (sus.contains(x)) continue;
            sus.insert(x);
            dfs(mp, x);
        }
    }
    void check(unordered_map <int, vector<int>> &mp,int k){
        if (mp.contains(k)==false) return;
        for (int x:mp[k]){
            if(sus.contains(x)){
                sus.erase(x);
                check(parent, x);
                check(children, x);
                return;
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        
        int t=invocations.size();
        for(int i=0; i<t; i++){
            parent[invocations[i][0]].push_back(invocations[i][1]);
            children[invocations[i][1]].push_back(invocations[i][0]);
        }
        sus.insert(k);
        dfs(parent, k);
        for(auto x: parent){
            if (sus.contains(x.first)==false) {
                check(parent, x.first);
                check(children, x.first);
            }
        }
        vector<int> answer;
        if (sus.empty()==true){
            for(int i=0; i<n; i++){
                if (sus.contains(i)==false) answer.push_back(i);
            }
            return answer;
        }
        for(int i=0; i<n; i++){
            if (sus.contains(i)==false) answer.push_back(i);
        }
        return answer;
    }
};