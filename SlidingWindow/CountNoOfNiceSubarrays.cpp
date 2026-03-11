// 1248

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        int odd_nums=0;
        int count=0;
        int prefixes=0;
        for (int i=0; i<n; i++){
            if (nums[i]%2!=0){
                odd_nums++;
                prefixes=0;
            } 
            while (odd_nums==k) {
                if (nums[left]%2!=0){
                    odd_nums--;
                }
                left++;
                prefixes++;
            }
            count+=prefixes;
        }
        return count;
    }
};