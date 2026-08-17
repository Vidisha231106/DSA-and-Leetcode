// 486

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        if (n%2==0 || n==1) return true;
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for (int i=0; i<n; i++){
            dp[i][i]=nums[i];
        }
        for (int i=n-1; i>=0; i--){
            for (int j=i+1; j<n; j++){
                dp[i][j]=max({ nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]});
            }
        }
        if (dp[0][n-1]>=0) return true;
        return false;
    }
};