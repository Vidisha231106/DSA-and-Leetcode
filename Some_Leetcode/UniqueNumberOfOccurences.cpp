// 1207

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        map <int, int> mp;
        for (int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        map <int, int> mp_for_unique_freq;
        for (auto it:mp){
            mp_for_unique_freq[it.second]++;
            if (mp_for_unique_freq[it.second]!=1) return false;
        }
        return true;
    }
};