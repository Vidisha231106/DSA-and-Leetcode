// 1872

//Wrong Answer

class Solution {
public:
    int recursion(vector<vector<int>> & dp, vector<int>&stones, int index, int n, int person, int left_stone, int left_stone_value){
        if(index>=n-1) return 0;
        if (dp[index][person]!=LLONG_MIN) return dp[index][person];
        int sum=left_stone_value;
        int answer=0;
        if (person==0){
            answer=INT_MIN;
            for (int i=index+1; i<n; i++){
                sum+=stones[i];
                answer=max(answer, sum-recursion(dp, stones, i+1, n, 1, i+1, sum));
            }
        }
        else {
            answer=INT_MAX;
            for (int i=index+1; i<n; i++){
                sum+=stones[i];
                answer=min(answer, -sum+recursion(dp, stones, i+1, n, 0, i+1, sum));
            }
        }
        return dp[index][person]=answer;
    }
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>> dp(n, vector<int>(2,  LLONG_MIN));
        return recursion(dp, stones, 0, n, 0, 0, 0);
    }
};

// Correct Solution - IMPORTANT

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int> prefix(n);
        prefix[0]=stones[0];
        for(int i=1; i<n; i++){
            prefix[i]=prefix[i-1]+stones[i];
        }
        int best_diff=prefix[n-1];
        for(int i=n-2; i>=1; i--){
            best_diff=max(best_diff, prefix[i]-best_diff);
        }
        return best_diff;
    }
};