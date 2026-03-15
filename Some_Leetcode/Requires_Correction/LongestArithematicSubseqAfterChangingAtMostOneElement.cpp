// 3872

class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int one_diff=nums[1]-nums[0];
        int n = nums.size();
        int global_consistent=0;
        int local_consistent=1;
        vector <int> copy=nums;
        vector <int> sivarnolqe=nums;
        for (int i=1; i<n; i++){
            if ((i<n-1 && one_diff!=nums[i]-nums[i-1] && nums[i+1]-nums[i-1]==2*one_diff) || one_diff==nums[i]-nums[i-1] || (i==n-1 && one_diff!=nums[i]-nums[i-1])) {
                local_consistent++;
                if (i<n-1 && one_diff!=nums[i]-nums[i-1] && nums[i+1]-nums[i-1]==2*one_diff) nums[i]=nums[i-1]+one_diff;
            }
            else{
                local_consistent+=1;
                if (local_consistent>global_consistent) global_consistent=local_consistent;
                if (i<n-1 && (nums[i+1]-nums[i-1])%2==0){
                    one_diff=(nums[i+1]-nums[i-1])/2;
                    nums[i]=nums[i-1]+one_diff;
                    local_consistent=3;
                } else {
                    local_consistent=2;
                    if (i<n-1) one_diff=nums[i+1]-nums[i];
                }
            }
            if (local_consistent>global_consistent) global_consistent=local_consistent;
        }
        nums=copy;
        int second_global=0;
        one_diff=nums[n-1]-nums[n-2];
        local_consistent=1;
        for (int i=n-1; i>0; i--){
            if ((i<n-1 && one_diff!=nums[i]-nums[i-1] && nums[i+1]-nums[i-1]==2*one_diff) || one_diff==nums[i]-nums[i-1] || (i==n-1 && one_diff!=nums[i]-nums[i-1])) {
                local_consistent++;
                if (i<n-1 && one_diff!=nums[i]-nums[i-1] && nums[i+1]-nums[i-1]==2*one_diff) nums[i]=nums[i-1]+one_diff;
            }
            else{
                local_consistent+=1;
                if (local_consistent>second_global) second_global=local_consistent;
                if (i>1 && (nums[i+1]-nums[i-1])%2==0){
                    one_diff=(nums[i+1]-nums[i-1])/2;
                    nums[i]=nums[i-1]+one_diff;
                    local_consistent=3;
                } else {
                    local_consistent=2;
                    if (i<n-1) one_diff=nums[i+1]-nums[i];
                }
            }
            if (local_consistent>second_global) second_global=local_consistent;
        }
        return max(second_global, global_consistent);
    }
};©leetcode