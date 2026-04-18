// 300

// IMPORTANT

class Solution {
public:
    int recursion(vector<int>& nums, vector<vector<int>> &dp, int prev_i, int curr_i, int& n){
        if (curr_i==n) return 0;
        if (dp[prev_i][curr_i]!=-1) return dp[prev_i][curr_i];
        int taken=0;
        if (prev_i==n || nums[curr_i]>nums[prev_i]) taken =1 + recursion(nums, dp, curr_i, curr_i+1, n);
        int not_taken= recursion(nums, dp, prev_i, curr_i+1, n);
        dp[prev_i][curr_i]=max(taken, not_taken);
        return dp[prev_i][curr_i];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n,-1));
        int answer=  recursion(nums, dp, n, 0, n); // IMP - prev=n is equivalent to saying prev=nothing yet
        return answer;
    }
};