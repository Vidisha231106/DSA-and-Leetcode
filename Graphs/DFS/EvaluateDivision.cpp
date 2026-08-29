// 399

class Solution {
public:
    unordered_map<string, double> mp;
    unordered_map<string, unordered_set<string>> existence;
    double dfs(string num, string den, double ans, unordered_set<string> &visited){
        if (existence.contains(num)==false && existence.contains(num)==false) return -1.0;
        if (num==den) return ans;
        visited.insert(num);
        for(string x:existence[num]){
            if (visited.contains(x)) continue;
            
            double result=dfs(x, den, ans*mp[num+'+'+x], visited);
            if (result!=-1.00000) return result;
        }
        return -1.00000;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        for(int i=0; i<n; i++){
            mp[equations[i][0]+'+'+equations[i][1]]=values[i];
            mp[equations[i][1]+'+'+equations[i][0]]=1/values[i];
            existence[equations[i][0]].insert(equations[i][1]);
            existence[equations[i][1]].insert(equations[i][0]);
        }
        int m=queries.size();
        vector<double> answer;
        
        for(int i=0; i<m; i++){
            unordered_set <string> visited;
            answer.push_back(dfs(queries[i][0], queries[i][1], 1, visited));
        }
        return answer;
    }
};