// 1547

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int x=cuts.size();
        vector<vector<int>> dp(x, vector<int> (x, 0));
        for (int i=x-1; i>=0; i--){
            for (int j=i+1; j<x; j++){
                dp[i][j]=INT_MAX;
                for (int k=i+1; k<j; k++){
                    dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]+(cuts[j]-cuts[i]));
                }
                if (dp[i][j]==INT_MAX){
                    dp[i][j]=0;
                }
            }
        }
        return dp[0][x-1];
    }
};