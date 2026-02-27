//16

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        long long min=(long long) nums[0] + (long long) nums[1] + (long long) nums[2];
        for (int i=0; i<n-2; i++){
            int left = i+1;
            int right=n-1;
            while (left<right){
                long long sum = nums[left]+nums[right]+nums[i];
                if (abs(sum-target) <abs(min-target) )min = sum;
                if (sum<target)left++;
                else if (sum>target) right--;
                else return sum;
            }
        }
        return min;
    }
};