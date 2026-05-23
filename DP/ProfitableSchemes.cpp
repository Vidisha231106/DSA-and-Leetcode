// 879

class Solution {
public:
    int count=0;
    int recursion(int n, int min_profit, vector<int>&group, vector<int>& profit, vector<vector<vector<int>>>&dp, int i, int curr_profit, int curr_ppl){
        int x=group.size();
        if (i==x){
            if (curr_profit>=min_profit) return 1;
            return 0;
        }
        if (dp[i][curr_ppl][curr_profit]!=-1) return dp[i][curr_ppl][curr_profit];
        int dont_take = recursion(n, min_profit, group, profit, dp, i+1, curr_profit, curr_ppl);
        int take=0;
        if (curr_ppl+group[i]<=n){
            take=recursion(n, min_profit, group, profit, dp, i+1, min(min_profit, curr_profit+profit[i]), curr_ppl+group[i]);
        }      
        dp[i][curr_ppl][curr_profit]=(int)((take+dont_take)%(1000000000+7));
        return dp[i][curr_ppl][curr_profit];
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int x=group.size();
        vector<vector<vector<int>>>dp(x+1, vector<vector<int>>(n+1, vector<int>(minProfit+1, -1)));
        //dp[index][men][profit]
        return recursion(n, minProfit, group, profit, dp, 0, 0, 0);
    }
};