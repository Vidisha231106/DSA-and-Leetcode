// 4066

class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n=nums.size();
        map<pair<int, int>, int> mp; 
        int count=0;
        for(int i=1; i<n; i++){
            if (nums[i]==nums[i-1]) count++;
        }
        int ans=0;
        for(int i=1; i<n; i++){
            if (nums[i]==nums[i-1]) continue;
            int x=min(nums[i], nums[i-1]);
            int y=max(nums[i], nums[i-1]);
            mp[{x,y}]++;
            ans=max(ans, mp[{x,y}]);
        }
        return ans+count;
    }
};