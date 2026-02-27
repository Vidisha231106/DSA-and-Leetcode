//54

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> answer;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int num = rows*cols;
        int left =0;
        int right=cols-1;
        int top=0;
        int bottom = rows-1;
        while (right>=left && top<=bottom){
            for (int j=left; j<=right; j++){
                answer.push_back(matrix[top][j]);
            }
            top++;
            for (int j=top; j<=bottom; j++){
                answer.push_back(matrix[j][right]);
            }
            right--;
            if (top<=bottom){
                for (int j=right; j>=left; j--){
                    answer.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            if (left<=right){
                for (int j=bottom; j>=top; j--){
                    answer.push_back(matrix[j][left]);
                }
                left++;
            }
        }
        return answer;
    }
};