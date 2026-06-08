// 1218

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int m=arr.size();
        unordered_map <int, int> dp;
        int answer=1; 
        for (int i=0; i<m; i++){
            dp[arr[i]]=dp[arr[i]-difference]+1;
            answer=max(answer, dp[arr[i]]);
        }
        return answer;
    }
};