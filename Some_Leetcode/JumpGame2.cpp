// 45

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return 0;
        int left=0;
        int maxJump=0;
        int right=0;
        int numJump=0;
        while (right<n-1){
            for (int i=left; i<=right; i++){
                maxJump = max(maxJump, i+ nums[i]);
            }
            left=right+1;
            numJump+=1;
            right= maxJump;
        }
        return numJump;
    }
};