//334 - TLE 

class Solution {
public:
    int recursion(vector<int>& nums, vector<vector<int>>& dp, int k, int index, int n){
        if (k==0) return 0;
        if (index>=n) return INT_MAX;
        int result =0;
        int take_curr= max(nums[index], recursion(nums, dp, k-1, index+2, n));
        int dont_take_curr=recursion(nums,dp, k, index+1, n);
        result=min(take_curr, dont_take_curr);
        dp[index][k]=result;
        return result;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp (n, vector<int>(k+1, 0));
        return recursion(nums, dp, k, 0, n);
    }
};