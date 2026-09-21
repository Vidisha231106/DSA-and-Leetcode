// 3524

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<long long>> dp(n+1, vector<long long> (k, 0));
        //int r=nums[0]%k;
        dp[0][nums[0]%k]=1; // one way to make this remainder using the first element
        // for(int j=0; j<k; j++){
        // }
        for(int i=1; i<n; i++){
            for(int j=0; j<k; j++){ // j= old remainder
                long long new_r=((long long)nums[i]*j)%k; // IMPORTANT -> calculation of the new remainder 
                dp[i][new_r]+=dp[i-1][j]; // 
            }
            dp[i][nums[i]%k]++; // single element arrays, form basis
        }
        vector<long long> ans;
        for(int j=0; j<k; j++){
            long long sum=0;
            for(int i=0;i<n; i++){
                sum+=dp[i][j]; // require cumulative at end
            }
            ans.push_back(sum);
        }
        return ans;
    }
};