// 123

// better code:

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int buy1=INT_MIN;
        int sell1=0;
        int buy2=INT_MIN;
        int sell2=0;
        for(int price:prices){
            buy1=max(buy1,-price);
            sell1=max(sell1,buy1+price);
            buy2=max(buy2,sell1-price);
            sell2=max(sell2,buy2+price);
        }
        return sell2;
    }
};

// my code:

class Solution {
public:
    int NEGATIVE=-1e9;
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        //dp[index][buy or sell][cap]=profit
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, NEGATIVE)));
        dp[0][0][0]=0;
        dp[0][1][0]=-prices[0];

        for (int i=1; i<n; i++){
            // j==0 -> sell
            // j==1 -> buy
            dp[i][0][0]=dp[i-1][0][0];
            dp[i][1][0]=max(0+ dp[i-1][1][0], -prices[i]+dp[i-1][0][0]);
            for (int k=1; k<=2; k++){
                //k=no. of transactions (at least=0, at most=2);
                dp[i][1][k]=max(-prices[i]+dp[i-1][0][k], 0+dp[i-1][1][k]);
                dp[i][0][k]=max(prices[i]+dp[i-1][1][k-1], 0+dp[i-1][0][k]);
            }
        }
        int answer=0;
        return max({dp[n-1][0][0], dp[n-1][0][1], dp[n-1][0][2]}); 
    }
};