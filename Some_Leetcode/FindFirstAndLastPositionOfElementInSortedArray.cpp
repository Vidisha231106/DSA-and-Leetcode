// 34

//IMPORTANT

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector <int> answer(2, -1);
        int left =0;
        int right=n-1;
        
        while(left<=right){
            int mid = (left+right)/2;
            if (target>nums[mid]) left = mid+1;
            else if (target< nums[mid]) right = mid-1;
            else {
                if (mid>0 && target==nums[mid-1]) right = mid-1;
                else answer[0]=mid;
                if (answer[0]!=-1){
                    right=n-1;
                    if (mid <n-1 && target==nums[mid+1]) left = mid+1;
                    else answer[1]=mid;
                }
                if (answer[0] != -1 && answer[1] != -1) break;
            }
        }
        return answer;
    }
};