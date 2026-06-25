// 210

class Solution {
public:
    int flag=0; // no cycle found yet
    void dfs(vector<vector<int>> &v, int index, stack<int>& st, vector<int>& visited){
        if (flag==1) return;
        if (index==visited.size()) return;
        if (visited[index]==1) {
            flag=1;
            return;
        }
        if (visited[index]==2) return;
        visited[index]=1;
        int n=v[index].size();
        for (int i=0; i<n; i++){
            dfs(v, v[index][i], st, visited);
            if (flag==1) return;
        }
        st.push(index);
        visited[index]=2;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        if (flag==1) return {};
        return answer;
    }
};