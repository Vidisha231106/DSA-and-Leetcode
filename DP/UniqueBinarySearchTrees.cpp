// 96

class Solution {
public:
    int recursion(vector<int>& dp, int root){
        if (root==0 || root==1) return 1;
        if (dp[root]!=-1) return dp[root];
        dp[root]=0; // since we are directly adding it should be set correctly instead of -1 default
        for (int i=1; i<=root; i++){
            dp[root]+=recursion(dp, i-1)*recursion(dp, root-i);
        }
        return dp[root];
    }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return recursion(dp, n);
    }
};