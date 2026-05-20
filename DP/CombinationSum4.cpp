// 377

class Solution {
public:
    int recursion(vector<int> & nums, int target, int& n, vector <int>& dp){
        if (target<0) return 0;
        if (target==0) {
            return 1;
        }
        if (dp[target]!=-1) return dp[target];
        dp[target]=0;
        for (int i=0; i<n; i++){
            dp[target]+=recursion(nums, target - nums[i], n, dp);
        }
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(target+1, -1);
        return recursion(nums, target, n, dp);
    }
};