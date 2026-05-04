// 3840

class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n= nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2,0));
        dp[0][0] = nums[0]; // take current
        dp[0][1]= 0; // dont take current
        // imp - you can rob two non-adjacent houses, even if they have the same colour
        for (int i=1; i<n; i++){
            long long take_adj=dp[i-1][1]+nums[i];
            long long dont_take_adj=nums[i]+dp[i-1][0];
            if (colors[i-1]!=colors[i]){
                dp[i][0]=max(take_adj, dont_take_adj);
            }
            else {
                dp[i][0]=take_adj;
            }
            dp[i][1]=max(dp[i-1][0], dp[i-1][1]);
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};