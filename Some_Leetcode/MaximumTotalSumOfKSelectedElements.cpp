// 3974
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end());
        long long answer=0;
        reverse(nums.begin(), nums.end());
        int i=0;
        int n=nums.size();
        while (i<n && k>0){
            answer+=(mul>0)? ((long long) mul*nums[i]):(long long) nums[i];
            i++;
            k--;
            mul--;
        }
        return answer;
    }
};