// 368

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        for (int i=0; i<n; i++){
            for (int j=0; j<i; j++){
                if (nums[i]%nums[j]==0){
                    dp[i]=max(dp[j]+1, dp[i]);
                    if (dp[i]==dp[j]+1) prev[i]=j;
                }
            }
        }
        vector<int>answer;
        int index=0;
        for (int i=0; i<n; i++){
            if (max(dp[index], dp[i])==dp[i]) index=i;
        }
        int curr=index;
        while (curr!=-1){
            answer.push_back(nums[curr]);
            curr=prev[curr];
        }
        return answer;
    }
};