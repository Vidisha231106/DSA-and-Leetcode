// 3471

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int n=nums.size();
        for (int i=0; i<n; i++){
            freq[nums[i]]++;
        }
        if (k==1){
            int m=-1;
            for(auto x: freq){
                if (x.second==1) m=max(m, x.first);
            }
            return m;
        }
        if (k==n) return (*max_element(nums.begin(), nums.end()));
        int ans=-1;
        if (freq[nums[0]]==1) ans=max(ans, nums[0]);
        if (freq[nums[n-1]]==1) ans=max(ans, nums[n-1]);
        return ans;
    }
};