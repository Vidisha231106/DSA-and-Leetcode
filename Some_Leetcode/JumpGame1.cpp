//55

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();      
        int jump=0;
        for (int i=0; i<n; i++){
            if (i>jump){
                return false;
            }
            jump = max(i+nums[i], jump);
            if (jump>n-1) return true;
        }
        return true;
    }
};
