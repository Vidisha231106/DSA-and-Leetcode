// 207

class Solution {
public:
    int flag=0;// no cycle detected yet
    void dfs(vector<vector<int>>& v, vector<int>& visited, int index){
        if (flag==1) return;//cycle detected
        if (visited[index]==1){
            flag=1;
            return;
        }
        if (visited[index]==2) return;
        if (index==visited.size()) return;
        int n=v[index].size();
        visited[index]=1;
        for (int i=0; i<n; i++){
            dfs(v, visited, v[index][i]);
        }
        visited[index]=2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> v(numCourses);
        for (int i=0; i<n; i++){
            v[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        n=v.size();
        vector <int> visited(numCourses, 0);
        for (int i=0; i<numCourses; i++){
            dfs(v, visited, i);
        }
        if (flag==1) return false; //cycle detected
        return true;
    }
};