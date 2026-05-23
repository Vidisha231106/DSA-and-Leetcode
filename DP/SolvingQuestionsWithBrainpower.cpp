// 2140

class Solution {
public:
    long long recursion(vector<vector<int>>& q, vector<long long>& dp, int i, int n){
        if (i>n-1) return 0;
        if (dp[i]!=-1) return dp[i];
        long long dont_take = recursion(q,dp,i+1,n);
        long long take=q[i][0]+recursion(q,dp,i+q[i][1]+1,n);
        dp[i]=max(take, dont_take);
        return dp[i];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n =questions.size();
        vector <long long>dp(n, -1);
        return recursion(questions,dp,0, n);
    }
};