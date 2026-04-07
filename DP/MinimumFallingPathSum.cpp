// 931 

//TABULATION

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m =matrix[0].size();
        vector<vector <int>> dp(n, vector<int> (m, -1));
        dp[0]=matrix[0];
        for (int i=1; i<n; i++){
            for (int j=0; j<m; j++){
                int first=INT_MAX, second=INT_MAX, third=INT_MAX;
                if (j>0 && j<m-1){
                    first = matrix[i][j]+dp[i-1][j-1];
                    second = matrix[i][j]+dp[i-1][j];
                    third = matrix[i][j]+dp[i-1][j+1];
                }
                else if (j==0){
                    second=matrix[i][j]+dp[i-1][j];
                    third = matrix[i][j]+dp[i-1][j+1];
                }
                else if(j==m-1){
                    first = matrix[i][j]+dp[i-1][j-1];
                    second=matrix[i][j]+dp[i-1][j];
                }
                dp[i][j]=min(first, min(second, third));
            }
        } 
        int min_fall=INT_MAX;
        for (int j=0; j<m; j++){
            min_fall=min(min_fall, dp[n-1][j]);
        }
        return min_fall;
    }
};


//MEMOISATION

class Solution {
public:
    int recursion(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int col_max){
        if (i==0) return matrix[0][j];
        if(dp[i][j]!=-1)
        return dp[i][j];
        if (i<0 || j<0) return 1e9;
        int first=INT_MAX, second=INT_MAX, third=INT_MAX;
        if (j>0 && j<col_max-1){
            first= matrix[i][j]+recursion(matrix, dp, i-1, j-1, col_max);
            second = matrix[i][j]+recursion(matrix, dp, i-1, j, col_max);
            third = matrix[i][j]+recursion(matrix, dp, i-1, j+1, col_max);
        }
        else if (j==0){
            second = matrix[i][j]+recursion(matrix, dp, i-1, j, col_max);
            third = matrix[i][j]+recursion(matrix, dp, i-1, j+1, col_max);
        }
        else if (j==col_max-1){
            first= matrix[i][j]+recursion(matrix, dp, i-1, j-1, col_max);
            second = matrix[i][j]+recursion(matrix, dp, i-1, j, col_max);            
        }
        dp[i][j]=min(first, min(second, third));
        return dp[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector <vector<int>> dp(n, vector<int>(m, -1));
        int answer=INT_MAX;
        for (int i=0; i<m; i++){
            answer = min(answer, recursion (matrix, dp, n-1, i,m));
        }
        return answer;
    }
};