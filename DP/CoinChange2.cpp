// 518

//Memoisation
class Solution {
public:
    int recursion(int target, vector <vector <int>> &dp, vector<int>&coins, int index){
        if (index<0) return 0;
        if (index==0)return (target%coins[0]==0);
        if (dp[index][target]!=-1) return dp[index][target];
        // if not taken, target doesnt change, the next index is referred to for the coins
        int not_taken = recursion(target, dp, coins, index-1);
        // if taken, target gets reduced once by that denomination, but we continue to refer to same index in next recursion
        int taken = 0;
        if (coins[index]<=target) taken = recursion(target-coins[index], dp, coins, index); 
        // we count both cases taken and not_taken since we need to find all ways to reach target
        dp[index][target] = taken+not_taken;
        return dp[index][target];
    }
    int change(int amount, vector<int>& coins) {
        int coin_size=coins.size();
        vector<vector<int>> dp(coin_size, vector<int>(amount+1, -1));
        return recursion(amount, dp, coins, coin_size-1);
    }
};

//Tabulation - 2D DP

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int coins_size=coins.size();
        vector<vector<unsigned long long>> dp(coins_size, vector<unsigned long long>(amount+1, 0));
        // intial condition - if that amount is diivisible by initial amount, we can directly set to 1
        for (int i=0; i<=amount; i++){
            if (i%coins[0]==0) dp[0][i]=1;
        }
        for (int i =1; i<coins_size; i++){
            for(long j=0; j<=amount; j++){
                unsigned long long not_taken = dp[i-1][j];
                unsigned long long taken=0;
                if (coins[i]<= j) taken = dp[i][j-coins[i]];
                dp[i][j] = (not_taken+taken);
            }
        }
        return dp[coins_size-1][amount];
    }
};

// Tabulation - 1D DP

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector <unsigned long long > dp(amount+1, 0);
        dp[0]=1;
        for (int i=0; i<n; i++){
            for (int j=coins[i]; j<=amount; j++){
                dp[j]+=(dp[j-coins[i]]);
            }
        }
        return dp[amount];
    }
};