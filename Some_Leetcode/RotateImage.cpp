//48

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // first find transpose
        int n = matrix.size();
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                int temp =matrix[j][i];
                matrix[j][i]= matrix[i][j];
                matrix[i][j]=temp;
            }
        }
        for (int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};