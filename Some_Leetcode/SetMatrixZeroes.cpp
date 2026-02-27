//73

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows;
        vector <int> cols;
        int row_size=matrix.size();
        int col_size=matrix[0].size();
        for (int i =0; i<row_size; i++){
            for (int j =0; j<col_size; j++){
                if (matrix[i][j]==0){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for (int i=0; i<rows.size(); i++){
            for (int j=0; j<col_size; j++){
                matrix[rows[i]][j]=0;
            }
            for (int j=0; j<row_size; j++){
                matrix[j][cols[i]]=0;
            }
        }
    }
};