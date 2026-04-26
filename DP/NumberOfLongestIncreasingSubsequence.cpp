// 673

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n, pair<int,int>{1,1});
        // pair.first = length of longest subsequence
        // pair.second = count of that longest subsequence
        int longest_subs=1;
        for (int i=0; i<n; i++){
            for (int j=0; j<i; j++){
                if (nums[i]>nums[j] && dp[j].first+1>dp[i].first){
                    dp[i].first=dp[j].first+1;
                    dp[i].second=dp[j].second;
                }
                else if (nums[i]>nums[j] && dp[j].first+1==dp[i].first){
                    dp[i].second+=dp[j].second;
                }
            }
            longest_subs=max(longest_subs,dp[i].first);
        }
        int answer=0;
        for (int i=0; i<n; i++){
            if (dp[i].first==longest_subs) answer+=dp[i].second;
        }
        return answer;
    }
};