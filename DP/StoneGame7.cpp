// 1690

class Solution {
public:
    int recursion(int l, int r, vector<vector<vector<int>>>& dp, int curr_sum, int n, vector<int> &stones, int person){
        if (l>r || l>=n) return 0; 
        if (dp[person][l][r]!=-1) return dp[person][l][r];
        int diff;
        if (person==0){
            diff=INT_MIN;
            diff=max(diff, curr_sum-stones[l]+ recursion(l+1, r, dp, curr_sum-stones[l], n, stones, 1));
            diff=max(diff, curr_sum-stones[r]+ recursion(l, r-1, dp, curr_sum-stones[r], n, stones, 1));
        } 
        else{
            diff=INT_MAX;
            diff=min(diff, -(curr_sum-stones[l])+recursion(l+1, r, dp, curr_sum-stones[l], n, stones, 0));
            diff=min(diff, -(curr_sum-stones[r])+recursion(l, r-1, dp, curr_sum-stones[r], n, stones, 0));            
        }
        dp[person][l][r]=diff;
        return diff;
    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        if (n==1) return stones[0];
        int sum=accumulate(stones.begin(), stones.end(), 0);
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int> (n, -1)));
        return recursion(0, n-1, dp, sum, n, stones, 0);
    }
};