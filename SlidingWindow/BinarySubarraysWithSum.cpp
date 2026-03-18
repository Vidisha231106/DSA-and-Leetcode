//930

class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if (goal<0) return 0;
        int left=0;
        int n = nums.size();
        int curr=0;
        int count=0;
        for (int i =0; i<n; i++){
            // i = right

            curr+=nums[i];
            while (curr>goal){
                curr-=nums[left];
                left++;   
            }
            count+=(i-left+1);
        }
        return count;
    }
    int numSubarraysWithSum(vector <int> & nums, int goal){
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
};