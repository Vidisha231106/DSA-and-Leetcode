// 542

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue <vector<int>> q;
        // traverse dfs from all the 0s to all the other nearby boxes, and update it, with min value 
        vector<vector<int>> v(m, vector<int> (n, INT_MAX));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (mat[i][j]==0){
                    q.push({i, j, 0});
                    v[i][j]=0;
                } 
            }
        }
        while (q.empty()!=true){
            vector<int> curr=q.front();
            q.pop();
            // if (mat[curr[0]][curr[1]]!=0) v[curr[0]][curr[1]]=min(v[curr[0]][curr[1]], curr[2]+1);
            if (curr[0]>0 && v[curr[0]-1][curr[1]]==INT_MAX){
                v[curr[0]-1][curr[1]]=curr[2]+1;
                q.push({curr[0]-1, curr[1], curr[2]+1});
            }
            if (curr[0]<m-1 && v[curr[0]+1][curr[1]]==INT_MAX) {
                v[curr[0]+1][curr[1]]=curr[2]+1;
                q.push({curr[0]+1, curr[1], curr[2]+1});
            }
            if (curr[1]>0 && v[curr[0]][curr[1]-1]==INT_MAX) {
                v[curr[0]][curr[1]-1]=curr[2]+1;
                q.push({curr[0], curr[1]-1, curr[2]+1});
            }
            if (curr[1]<n-1 && v[curr[0]][curr[1]+1]==INT_MAX){
                v[curr[0]][curr[1]+1]=curr[2]+1;
                q.push({curr[0], curr[1]+1, curr[2]+1});
            }
        }
        return v;
    }
};