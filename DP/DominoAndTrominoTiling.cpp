// 790

const long long MOD =1e9+7; 
class Solution {
public:
    int numTilings(int n) {
        if (n<3) return n;
        vector <vector<long long>> dp(n+1, vector<long long>(3, 0));
        // [i-2][0], [i-2][0], [i-1][0]
        // [i-2][1], [i-2][2]
        dp[0][0]=1;
        dp[0][1]=0;
        dp[0][2]=0;
        dp[1][0]=1;
        dp[1][1]=1;
        dp[1][2]=1;
        for (int i=2; i<=n; i++){
            dp[i][0]= (dp[i-1][0]+dp[i-2][0]+dp[i-2][1]+dp[i-2][2])%MOD;
            dp[i][1]=(dp[i-1][0]+dp[i-1][2])%MOD;
            dp[i][2]=(dp[i-1][0]+dp[i-1][1])%MOD;
        }
        return dp[n][0];
    }
};