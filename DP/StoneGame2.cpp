// 1140

class Solution {
public://0->Alice, 1->Bob;
    int recursion(vector<vector<vector<int>>>& dp, vector<int>& piles, int index, int m, int person){
        if (index>=piles.size()) return 0;
        if (dp[person][index][m]!=-1) return dp[person][index][m];
        int n=piles.size();
        int x=2*m;
        int answer;
        if (person==1) answer=INT_MAX;
        else answer=INT_MIN;
        int sum=0;
        for (int i=index; i<min(index+x, n); i++){
            sum+=piles[i];
            if (person==1) answer=min(answer, recursion(dp, piles, i+1, max(m, i-index+1), 0));
            else answer=max(answer,sum+recursion(dp, piles, i+1, max(m, i-index+1), 1));
        }
        dp[person][index][m]=answer;
        return answer;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n+1, vector<int>(2*n+1, -1)));
        return recursion(dp, piles, 0, 1, 0);
    }
};