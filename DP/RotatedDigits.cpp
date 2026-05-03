// 788

class Solution {
public:
    void fn(int n, vector<int>& dp){
        if (n==3 || n==4 || n==7){
            dp[n]=0;
            return;
        } 
        else if (n==1 || n== 8 || n==0){
            dp[n]=1;
            return;
        }
        else if (n==2 || n==5 || n==6 || n==9) {
            dp[n]=2;
            return;
        }
        int digit= n%10;
        if (digit==3 || digit==4 || digit==7){
            dp[n]=0;
        }
        else if (digit==1 || digit== 8 || digit==0){
            dp[n]=dp[n/10];
        }
        else if (dp[n/10]==0) dp[n]=0;
        else dp[n]=2;
    }
    int rotatedDigits(int n) {
        // we can store a number result in a dp array and then for a number x, if x/10 sol exists in the dp array, we get that itself as the answer;
        vector<int> dp(n+1, -1);
        for (int i=0; i<=n; i++) fn(i, dp);
        int count=0;
        for (int i=0; i<=n; i++){
            if (dp[i]==2) count++; 
        }
        return count;
    }
};