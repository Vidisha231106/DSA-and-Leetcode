// 1027

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<int, int>> dp(n);

        //key is the diff
        int answer=INT_MIN;
        for (int i=0; i<n; i++){
            for (int j=0; j<i; j++){
                int k=nums[i]-nums[j];
                if (dp[j].contains(k)){
                    dp[i][k]=1+ dp[j][k];
                }
                else{
                    dp[i][k]=2;
                }
                answer=max(answer, dp[i][k]);
            }
        }
        return answer;
    }
};