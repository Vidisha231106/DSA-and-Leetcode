// 198

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        vector <int> dp(n+1);
        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]); //IMP
        for (int i=2; i<n; i++){
            int steal = nums[i]+dp[i-2];
            int leave = dp[i-1];
            dp[i]=max(steal, leave);
        }
        return dp[n-1];
    }
};