// 4067

/*
Check whether sums contains nums[i].

If not, check whether nums[i] + nums[j] exists in mp for any j in the current window.

If either condition is true, remove nums[left] and update both maps.

Repeat until the window is valid.

Add the new pairs and frequency, then update ans.*/

class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int ans=0;
        unordered_map<int, int> sums;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            // i=right
            int invalid=0;
            while (left<i){
                invalid=(sums.contains(nums[i]))? 1: 0;
                //if (invalid==1) break;
                for(int j=left; j<i; j++){
                    if (mp.contains(nums[i]+nums[j])) {
                        invalid=1;
                    }
                }
                if (invalid==0) break;
                mp[nums[left]]--;
                if (mp[nums[left]]==0) mp.erase(nums[left]);
                for(int j=left+1; j<i; j++){
                    sums[nums[left]+nums[j]]--;
                    if (sums[nums[left]+nums[j]]==0) sums.erase(nums[left]+nums[j]);
                }
                left++;
            }
            for(int j=left; j<i; j++){
                sums[nums[j]+nums[i]]++;//adding curr to sums
            }
            mp[nums[i]]++;
            ans=max(ans, i-left+1);
        }
        return ans;
    }
};