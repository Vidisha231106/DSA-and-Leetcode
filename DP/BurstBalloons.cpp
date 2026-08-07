// 319

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n+2, 1);
        for (int i=0; i<n; i++) arr[i+1]=nums[i];
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));
        for (int i=n-1; i>=0; i--){
            for (int j=i+2; j<n+2; j++){
                for (int k=i+1; k<j; k++){
                    dp[i][j]=max(dp[i][j], dp[i][k]+dp[k][j]+arr[i]*arr[j]*arr[k]);
                }
            }
        }
        return dp[0][n+1];
    }
};