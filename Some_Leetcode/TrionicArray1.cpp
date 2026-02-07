// 3637

class Solution {
public:
    
    bool isTrionic(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for (int i=1; i<n-1; i++){
            if (nums[i]==nums[i-1] || nums[i]==nums[i+1]) return false;
            if (nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                if (count%2==0) count++;
                else return false;
            } 
            else if (nums[i]<nums[i-1] && nums[i]<nums[i+1]){
                if (count%2!=0) count++;
                else return false;
            } 
        }
        if (count!=2) return false;
        return true;
    }
};