// 416

class Solution {
public:
    bool recursion(vector<int>& nums, vector<vector<int>>& dp, int index, int curr, int half_sum){
        if (curr==half_sum) return true;
        if (index>=nums.size()) return false;
        if (dp[index][curr]!=-1) return dp[index][curr];
        bool used=false;
        bool unused = false;
        if (nums[index]+curr<=half_sum) used = recursion(nums, dp, index+1, curr+nums[index], half_sum);
        unused = recursion(nums, dp, index+1, curr, half_sum);
        dp[index][curr]=used || unused;
        return used || unused;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i=0; i<n; i++){
            sum+=nums[i];
        }
        if (sum%2!=0) return false;
        int half_sum=sum/2;
        vector<vector <int>> dp(n, vector<int>(half_sum+1, -1));
        
        return recursion(nums, dp, 0, 0, half_sum);
    }
};