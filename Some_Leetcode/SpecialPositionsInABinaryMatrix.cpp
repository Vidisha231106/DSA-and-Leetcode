// 1582

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        //index:freq
        int m = mat.size();
        int n = mat[0].size();
        vector <int> cols(n,0); //index:freq
        vector <int> rows(m, 0);
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (mat[i][j]==1) {
                    cols[j]++;
                    rows[i]++;
                }
            }
        }
        int count=0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (mat[i][j]==1 && rows[i]==1 && cols[j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};