class Solution {
public:
    long long minCost(int r, int c, vector<vector<int>>& waitCost) {
        vector<vector<long long>> dp(r+1, vector<long long>(c, 0));
        dp[0][0]=1;//no waiting at first box
        for(int j=1; j<c; j++){
            dp[0][j]=dp[0][j-1]+waitCost[0][j]+(0+1)*(j+1);
        }
        for(int i=1; i<r;i++){
            dp[i][0]=dp[i-1][0]+waitCost[i][0]+(i+1)*(0+1);
        }      
        //here seconds=i+j
        for(int i=1; i<r; i++){
            for(int j=1; j<c; j++){
                dp[i][j]=min(dp[i-1][j], dp[i][j-1])+waitCost[i][j]+(i+1)*(j+1);
            }
        }  
        //here the transition is: (move - wait) - (move - wait) moving doesnt involve extra time, only waiting does, so per box, we have to use 1 sec. so it becomes a normal dp transition
        return dp[r-1][c-1]-waitCost[r-1][c-1];
    }
};