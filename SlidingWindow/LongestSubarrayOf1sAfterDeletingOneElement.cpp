// 1493

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return 0;
        int left=0;
        int longest=INT_MIN;
        int zeros=0;
        for (int i=0; i<n; i++){
            if (nums[i]==0){
                zeros++;
            } 
            while (zeros>1) {
                if (nums[left]==0) zeros--;
                left++;
            }
            longest=max(longest, i-left);
        }
        return longest;
    }
};