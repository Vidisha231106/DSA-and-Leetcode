//3843

class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, int> freq;
        for (int  i=0; i<n; i++){
            freq[nums[i]]++;
        }
        unordered_map <int, int> freq_of_freq;
        for (auto it: freq){
            freq_of_freq[it.second]++;
        }
        for (int i=0; i<n; i++){
            if (freq_of_freq[freq[nums[i]]]==1) return nums[i];
        }
        return -1;
    }
};