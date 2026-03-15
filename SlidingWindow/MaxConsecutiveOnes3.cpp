//1004

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left=0; 
        int zeroCount=0;
        int maxCount=0;
        for (int i=0; i<n; i++){
            // i = right pointer
            if (nums[i]==0) zeroCount++;
            if (zeroCount>k) {
                if (nums[left]==0){
                    zeroCount--;
                }
                left++;
            }
            if (i-left+1 > maxCount) maxCount = i-left+1;
        }
        return maxCount;
    }
};