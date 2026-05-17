// 97

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        //dp[i][j]= if s3 substring can be made using 0-ith of s1 and 0-jth of s2
        // -1: not computed, 0: false, 1: true
        if (n+m< s3.length()) return false;
        dp[0][0]=1;
        //since the beginning letter can only match with either one or both, we will set the first row and first col approriately
        for(int i=1; i<=n; i++){
            dp[i][0]=dp[i-1][0] && (s1[i-1]==s3[i-1]);
        }
        for (int i=1; i<=m; i++){
            dp[0][i]=dp[0][i-1] && (s2[i-1]==s3[i-1]);
        }
        
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m;j++){
                dp[i][j]= (dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (dp[i][j-1] && s2[j-1]==s3[i+j-1]);
            }
        }
        return (bool) dp[n][m];
    }
};