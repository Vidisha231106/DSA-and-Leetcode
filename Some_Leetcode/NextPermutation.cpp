// 31

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index=-1;
        int next_index=0;
        for (int i=n-2; i>=0; i--){
            if (nums[i]<nums[i+1]) {
                index=i;

                break;
            }
        }
        if (index==-1){
            reverse(nums.begin(), nums.end());
            return;
        } 
        for (int i=n-1; i>index; i--){
            if (nums[i]>nums[index]) {
                next_index=i;
                break;
            }
        }
        int temp= nums[index];
        nums[index]=nums[next_index];
        nums[next_index] =temp;

        reverse(nums.begin()+index+1, nums.end());
    }
};