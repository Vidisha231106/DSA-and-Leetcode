// 1283

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int right=*max_element(nums.begin(), nums.end());
        int n=nums.size();
        int curr=0;
        int left=1;
        while (left<=right){
            int div=(left+right)/2;
            curr=0;
            for (int i=0; i<n; i++){
                curr+=ceil((double) nums[i]/div);
            }
            if (curr>threshold){
                left=div+1;
            }
            if (curr<=threshold) right=div-1;
        }
        return left;
    }
};