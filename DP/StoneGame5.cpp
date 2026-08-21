// 1563

class Solution {
public:
    int recursion(vector<int>& stoneValue, int l, int r, vector<int> &prefix_sum, vector<vector<int>> &dp){
        if (r==l) return 0; // one stone
        if (dp[l][r]!=-1) return dp[l][r];
        int answer=0;
        for(int i=l; i<r; i++){
            if (prefix_sum[i+1]-prefix_sum[l]>prefix_sum[r+1]-prefix_sum[i+1]){
                answer=max(answer, (prefix_sum[r+1]-prefix_sum[i+1])+recursion(stoneValue, i+1, r, prefix_sum, dp));
            }
            else if (prefix_sum[i+1]-prefix_sum[l]<prefix_sum[r+1]-prefix_sum[i+1]){
                answer=max(answer, (prefix_sum[i+1]-prefix_sum[l])+recursion(stoneValue, l, i, prefix_sum, dp));
            }
            else{
                answer=max(answer, (prefix_sum[r+1]-prefix_sum[i+1])+max(recursion(stoneValue, i+1, r, prefix_sum, dp) ,recursion(stoneValue, l, i, prefix_sum, dp)));
            }            
        }
        return dp[l][r]=answer;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> prefix_sum(n+1, 0);
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=0; i<n; i++){
            prefix_sum[i+1]=prefix_sum[i]+stoneValue[i];
        }
        int answer=INT_MIN;
        answer=max(answer, recursion(stoneValue, 0, n-1,prefix_sum, dp));
        return answer;
    }
};