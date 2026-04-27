// 540

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        int mid = (n/2)+1;
        int left=0;
        int right=n-1;
        while (left<right){
            mid = (left+right)/2;
            if (mid%2!=0) mid-=1;

            if (nums[mid]==nums[mid+1]){
                left=mid+2;
                
            }
            else{
                right=mid;
            }

        }
        return nums[left];
    }
};