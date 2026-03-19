// 3862

class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long prod=1;
        long long sum=0;
        int n = nums.size();
        for (int i=0; i<n; i++){
            sum+=nums[i];
        }
        int answer=-1;
        for (int i=n-1; i>=0; i--){
            
            sum-=nums[i];
            if (sum==prod) answer=i;
            // imp to check if overflow occurs!!!
            /*LLONG_MAX is a macro in C/C++ (<climits> or <limits.h>) defining the maximum value for a signed long long integer.
            */
            if (prod>sum) break;
            if (nums[i] != 0 && prod > LLONG_MAX / nums[i]) break;
            prod*=nums[i];
        }
        return answer;
    }
};