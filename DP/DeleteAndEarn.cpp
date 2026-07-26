// 740

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> freq;
        int n=nums.size();
        int count=1;
        for (int i=1; i<n; i++){
            if (nums[i]!=nums[i-1]){
                freq.push_back({nums[i-1], count});
                count=1;
            }
            else {
                count++;
            }
        }
        freq.push_back({nums[n-1], count});
        int m=freq.size();
        if (m==1) return freq[0].first*freq[0].second;
        vector<int> dp(m,  0);
        dp[0]=freq[0].first*freq[0].second;

        int take =(freq[1].first*freq[1].second);
        if (freq[0].first+1!=freq[1].first){
            take=dp[0]+(freq[1].first*freq[1].second);
        }
        int dont_take=dp[0];
        dp[1]=max(take, dont_take);

        for (int i=2; i<m; i++){
            int take = dp[i-2] + (freq[i].first*freq[i].second);
            if (freq[i-1].first+1!=freq[i].first){
                take=dp[i-1]+(freq[i].first*freq[i].second);
            }
            int dont_take=dp[i-1];
            dp[i]=max(take, dont_take);
        }
        return dp[m-1];
    }
};