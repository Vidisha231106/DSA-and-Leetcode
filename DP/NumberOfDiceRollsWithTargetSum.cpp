// 1155

class Solution {
public:
    const int MOD=1e9+7;
    int recursion(vector<vector<long long>> &dp, int n, int target, int k){
        if (n==0) return target==0;
        if (target<=0) return 0;
        if (dp[n][target]!=-1) return dp[n][target];
        dp[n][target]=0;
        for (int i=1; i<=k; i++){
            dp[n][target]=(dp[n][target]+recursion(dp, n-1, target-i, k))%MOD;
        }
        return (dp[n][target]);
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n+1, vector<long long>(target+1, -1));
        return recursion(dp, n, target, k);
    }
};