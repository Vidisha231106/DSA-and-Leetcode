// 209

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int left=0;
        int n=nums.size();
        int curr=0;
        for (int i=0; i<n; i++){
            curr+=nums[i];
            while (left<n && curr>=target){
                curr-=nums[left];
                left++;
            }
            if (left>0 && curr<target){
                left--;
                curr+=nums[left];
            }
            if (curr>=target) ans=min(ans, i-left+1);
        }
        if (ans==INT_MAX) return 0;
        return ans;
    }
};