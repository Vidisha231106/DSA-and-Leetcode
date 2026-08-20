// 1510

class Solution {
public:
    vector<int> sqs;
    bool recursion(vector<vector<int>>& dp, int n , int person){
        if(n==0) return false;
        if (dp[n][person]!=INT_MIN) return dp[n][person];
        for(int i=0; i<sqs.size() && sqs[i]<=n; i++){
            if (recursion(dp, n-sqs[i], 1-person)==false) return dp[n][person]=true;
        } 
        dp[n][person]=false;
        return false;
    }
    bool winnerSquareGame(int n) {
        for(int i=1; i*i<=n; i++){
            sqs.push_back(i*i);
        }
        int x=sqs.size();
        vector<vector<int>> dp(n+1, vector<int>(2, INT_MIN));
        return recursion(dp, n, 0);
    }
};