//1752. Check if an Array is sorted and rotated

class Solution {
public:
    bool check(vector<int>& nums) {
        int index=0;
        int last_index= nums.size()-1;
        if (last_index==0) return true;
        int equal_elements =1; //1 for sorted
        for (int i=0; i<nums.size()-1; i++){
            if (nums[i]!=nums[i+1]) equal_elements=0;
        }
        if (equal_elements==1) return true;
        while (nums[index]>=nums[last_index]){
            nums.push_back(nums[index]);
            index++;
            last_index++;
        }
        for (int i=index; i<nums.size()-1; i++){
            if (nums[i]>nums[i+1]){
                return false;
            }
        }       
        return true;
    }
};