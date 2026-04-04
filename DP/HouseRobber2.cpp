// 213

class Solution {
public:
    int circularRob(vector<int>& nums, int i, int j, int n){
        vector<int> dp(n+1);
        dp[i]=nums[i];
        if (i==j) return dp[i];
        dp[i+1]=max(nums[i], nums[i+1]);
        for (int k=i+2; k<=j; k++){
            int steal = nums[k]+dp[k-2];
            int leave = dp[k-1];
            dp[k]=max(steal, leave);
        }
        return dp[j];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        return max(circularRob(nums, 0, n-2, n), circularRob(nums, 1, n-1, n));
    }
};