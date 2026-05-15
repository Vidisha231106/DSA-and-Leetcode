// 494

class Solution {
public:
    int recursion(vector<vector<int>>& dp,vector<int>& nums, int index, int target){
        if (index==0 && target==0 && nums[0]==0) return 2;
        else if (index==0 && (target==0 || target==nums[0])) return 1;
        else if (index==0) return 0;

        if (dp[index][target]!=-1) return dp[index][target];
        int positives=recursion(dp, nums, index-1, target);
        int negatives=0;
        if (nums[index]<=target){
            negatives=recursion(dp, nums, index-1, target-nums[index]);
        }
        return dp[index][target] = positives+negatives;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        
        int n=nums.size();
        for (int i=0; i<n; i++){
            total+=nums[i];
        }
        if ((total-target)<0 || (target-total)%2!=0) return 0;
        if (n==1 && target!=nums[0] && target!=(-1*nums[0])) return 0;
        //s1+s2 = total -> [positives + negatives]
        //s1-s2 = target -> [positives - (already negatives)]
        int s2 = (total - target)/2;
        vector<vector<int>> dp(n, vector<int>(s2+1, -1));
        return recursion(dp, nums, n-1, s2);
    }
};