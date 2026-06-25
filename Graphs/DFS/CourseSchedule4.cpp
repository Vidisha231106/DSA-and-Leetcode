// 1462

class Solution {
public:
    void dfs(vector<vector<int>> &v, int index, stack<int>& st, vector<int>& visited){
        if (index==visited.size()) return;
        if (visited[index]==1) return;
        visited[index]=1;
        int n=v[index].size();
        for (int i=0; i<n; i++){
            dfs(v, v[index][i], st, visited);
        }
        st.push(index);
        visited[index]=0;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> v(numCourses);
        int n= prerequisites.size();
        for (int i=0; i<n; i++){
            v[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        stack <int> st;
        vector<int> visited(numCourses);
        for (int i=0; i<numCourses; i++){
            if (visited[i]==0) dfs(v, i, st, visited);
        }
        vector <int> answer;
        while (st.empty()!=true){
            answer.push_back(st.top());
            st.pop();
        }
        unordered_map <int, int> mp; //course: index
        n=answer.size();
        vector<bool> ans;
        for (int i=0; i<n; i++){
            mp[answer[i]]=i;
        }
        n=queries.size();
        for (int i=0; i<n; i++){
            if (mp[queries[i][0]]<mp[queries[i][1]]) ans.push_back(false);
            else ans.push_back(true);
        }
        return ans;
    }
};