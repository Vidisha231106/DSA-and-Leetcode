// 3936

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n=nums.size();
        int answer=0;
        int left=0;
        int right=n-1;
        while (left<right){
            if (nums[left]==0 && nums[right]!=0){
                swap(nums[left], nums[right]);
                answer++;
                right--;
                left++;
            }
            else if (nums[right]==0) right--;
            else if (nums[left]==0){
                while(right>left && nums[right]!=0) right--;
                left++;
            }
            else left++;
        }
        return answer;
    }
};