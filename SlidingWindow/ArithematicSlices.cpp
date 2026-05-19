// 413

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        if (n<3) return 0;
        int prev=nums[1]-nums[0];
        for (int left=0; left<n-2; left++){
            prev=nums[left+1]-nums[left];
            for (int i=left+1; i<n-1; i++){ //right
                int diff=nums[i+1]-nums[i];
                if (diff!=prev) break;
                if ((i+1)-left+1>=3) count++; // (i +1)-left + 1
            }
        }
        return count;
    }
};