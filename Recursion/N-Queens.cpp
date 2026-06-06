// 51

class Solution {
public:
    vector<vector<string>> answer;
    void recursion(vector<vector<char>> &matrix, vector<int>& rows, vector<int>& upper_diag, vector<int>& lower_diag, int n, int y){
        if (y==n){
            vector<string> ans;
            for (int i=0; i<n; i++){
                string s(matrix[i].begin(), matrix[i].end());
                ans.push_back(s);
            }
            answer.push_back(ans);
            return;
        } 
        for (int i=0; i<n; i++){
            if (rows[i]!=1 && lower_diag[n-1+i-y]!=1 && upper_diag[i+y]!=1){
                rows[i]=1;
                lower_diag[n-1+i-y]=1;
                upper_diag[i+y]=1;
                matrix[i][y]='Q';
                recursion(matrix, rows, upper_diag, lower_diag, n, y+1);
                rows[i]=0;
                lower_diag[n-1+i-y]=0;
                upper_diag[i+y]=0;
                matrix[i][y]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> matrix(n, vector<char>(n, '.'));
        int m= (2*n)-1;
        vector<int> rows(n, 0);
        vector<int> upper_diag(m, 0);
        vector<int> lower_diag(m, 0);
        recursion(matrix, rows, upper_diag, lower_diag, n, 0);
        return answer;
    }
};