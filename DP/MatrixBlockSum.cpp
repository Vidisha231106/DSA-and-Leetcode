// 1314

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector <vector<int>> sum(n+1, vector<int> (m+1, 0));
        for (int i=0; i<n;i++){
            for (int j=0; j<m; j++){
                sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]+mat[i][j]-sum[i][j];
            }
        }
        vector <vector<int>> answer(n, vector<int> (m, 0));

        for(int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                int r_begin=max(0, i-k);
                int r_end=min(n-1, i+k);
                int c_begin=max(0, j-k);
                int c_end=min(m-1, j+k);
                answer[i][j]= sum[r_end+1][c_end+1]-sum[r_begin][c_end+1]-sum[r_end+1][c_begin]+sum[r_begin][c_begin];
            }
        }
        return answer;
    }
};