// 3946

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        sort(items.begin(), items.end());
        unordered_map <int, int> mp;
        for (int i=0; i<n; i++){
            for (int j=0;j<n; j++){
                if (i!=j && items[j][0]%items[i][0]==0) mp[i]++;
            }
        }
        vector<vector<int>>dp(n+1, vector<int>(budget+1, 0));
        for (int i=1; i<=n; i++){
            for (int j=0; j<=budget; j++){
                dp[i][j]=dp[i-1][j];
                if (j>=items[i-1][1]){
                    dp[i][j]=max(dp[i-1][j], 1+ dp[i-1][j-items[i-1][1]]+mp[i-1]);
                    dp[i][j]=max(dp[i][j], 1+dp[i][j-items[i-1][1]]);
                }
            }
        }
        return dp[n][budget];        
    }
};