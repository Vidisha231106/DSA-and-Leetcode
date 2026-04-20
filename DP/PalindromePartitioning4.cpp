// 1745

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n,-1));
        for (int i=n-1; i>=0; i--){
            for (int j=i; j<n; j++){
                if (s[i]==s[j] && (j-i<=1 || dp[i+1][j-1]!=-1)) dp[i][j]=1;
            }
        }
        for (int i=0; i<n-2; i++){
            for (int j=i+1; j<n-1; j++){
                if (dp[0][i]==1 && dp[i+1][j]==1 && dp[j+1][n-1]==1) return true;
            }
        }
        return false;
    }
};