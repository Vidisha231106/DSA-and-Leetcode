// 2958

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int answer=INT_MIN;
        unordered_map<int,int> mp;
        unordered_map<int,vector<int>> freq;
        int l=0,r=0;
        for (r=0; r<n; r++){
            mp[nums[r]]++;
            int flag=0;
            if (mp[nums[r]]>k) flag=1;
            if(mp[nums[r]]>1) erase(freq[mp[nums[r]]-1], nums[r]);
            freq[mp[nums[r]]].push_back(nums[r]);
            if (flag==1){
                while (l<=r && mp[nums[r]]>k){
                    mp[nums[l]]--;
                    if (mp[nums[l]+1]==1){ //delete entire key from map
                        freq.erase(mp[nums[l]+1]);
                    }
                    else{ // delete number from 
                        erase(freq[mp[nums[l]+1]],nums[l]);
                    }
                    l++;
                }
            }
            answer=max(answer, r-l+1);
        }
        return answer;
    }
};