// 4049

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, pair<int,int>> mp; //last occurrence
        int n=nums.size();
        unordered_set <int> ans;
        unordered_map<int,int> freq;
        for (int i=0; i<n; i++){
            freq[nums[i]]++;
        }
        unordered_set<int> banned;
        for(int i=0; i<n; i++){
            if (banned.contains(nums[i])==true) continue;
            if (freq[nums[i]]<3) continue;
            if (mp.contains(nums[i])==false) mp[nums[i]]={i, -1};
            else if (mp[nums[i]].second==-1) mp[nums[i]]={i, i-mp[nums[i]].first};
            else if (mp[nums[i]].second!=i-mp[nums[i]].first) {
                banned.insert(nums[i]);
                if (ans.contains(nums[i])==true) {
                    ans.erase(nums[i]);
                }
                else continue;
            }
            else if (mp[nums[i]].second==i-mp[nums[i]].first){
                ans.insert(nums[i]);
                mp[nums[i]].first=i;
            } 
        }
        return ans.size();
    }
};