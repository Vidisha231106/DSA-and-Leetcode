// 279

class Solution {
public:
    int numSquares(int n) {
        if (n==1) return 1;
        vector<int> nums;
        for (int i=0; i<=pow(n,0.5); i++){
            nums.push_back(i*i);
        }
        int nums_size=nums.size();
        for (int i =0; i<nums_size; i++) cout<< nums[i]<< " ";
        vector<int> dp(n+1, INT_MAX);
        dp[0]=0; //this means that for the 0 cost, i need 0 coins   
        for (int i=1; i<=n; i++){
            for (int j=0; j<nums_size; j++){
                if (i-nums[j]>=0 && dp[i-nums[j]]!=INT_MAX) dp[i]=min(dp[i-nums[j]]+1, dp[i]);
            }
        }
        if (dp[n]==INT_MAX) return -1;
        return dp[n];
    }
};