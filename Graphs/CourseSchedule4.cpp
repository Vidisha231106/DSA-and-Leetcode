// 1462

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>v (numCourses, vector<int>(numCourses, 0));
        int n=prerequisites.size();
        for (int i=0; i<n; i++){
            v[prerequisites[i][0]][prerequisites[i][1]]=1;
        }
        for (int k=0; k<numCourses; k++){
            for (int i=0; i<numCourses; i++){
                for (int j=0; j<numCourses; j++){ 
                    v[i][j]=(v[i][j] || (v[i][k] && v[k][j]));
                }
            }
        }
        n=queries.size();
        vector<bool> answer(n, false);
        for (int i=0; i<n; i++){
            if (v[queries[i][0]][queries[i][1]]==1) answer[i]=true;
        }
        return answer;
    }
};