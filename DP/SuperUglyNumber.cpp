// 313

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> dp(n+1, INT_MAX);
        int  p=primes.size();
        vector<long long> counter(p,0);
        dp[0]=1;
        for(int i=1; i<=n;i++){
            for (int j=0; j<p; j++){
                dp[i]=min(dp[counter[j]]*primes[j], dp[i]);
            }
            for (int j=0; j<p; j++){
                if (dp[i]==dp[counter[j]]*primes[j]){
                    counter[j]++;
                }
            }
        }
        return dp[n-1];
    }
};