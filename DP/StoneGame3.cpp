// 1406

class Solution {
public:
    int recursion(vector<vector<int>> & dp, vector<int> & stoneValue, int r, int person){
        if (r>stoneValue.size()-1) return 0;
        if (dp[r][person]!=INT_MIN) return dp[r][person];
        int answer=INT_MIN;
        int sum=0;
        int x=min(r+3, (int)stoneValue.size());
            for(int i=r; i< x; i++){
                sum+=stoneValue[i];
                answer=max(answer, sum-recursion(dp, stoneValue, i+1, 1-person));
            }
        dp[r][person]=answer;
        return answer;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(3, INT_MIN));
        int answer=recursion(dp, stoneValue, 0, 0);
        
        if (answer==0){
            return "Tie";
        }
        if (answer>0) return "Alice";
        return "Bob";
    }
};