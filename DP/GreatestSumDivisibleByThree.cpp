// 1262

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector <vector<int>> dp(n+1,vector<int>(3, -1));
        dp[0][0]=0;
        dp[0][nums[0]%3]=nums[0];
        for (int i=1; i<n; i++){
            for (int j=0; j<3; j++){
                dp[i][j]=max(dp[i][j], dp[i-1][j]); // dont take
                int new_r=(j+ nums[i]%3)%3;
                if (dp[i-1][j]!=-1) dp[i][new_r]=max(dp[i][new_r], dp[i-1][j]+nums[i]); //take
            } 
        }
        return dp[n-1][0];
    }
};