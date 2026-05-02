// 152

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp_min(n+1, 1);
        vector <int> dp_max(n+1, 1);
        dp_min[0]=nums[0];
        dp_max[0]=nums[0];
        int answer = nums[0];
        for (int i=1; i<n; i++){
            dp_min[i]=min({1* nums[i], nums[i]*dp_min[i-1], nums[i]*dp_max[i-1]});
            dp_max[i]=max({1*nums[i], nums[i]*dp_min[i-1], nums[i]*dp_max[i-1]});
            answer = max(answer, dp_max[i]);
        }
        return answer; 
    }
};