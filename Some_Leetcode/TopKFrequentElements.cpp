// 347

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        int n=nums.size();
        for (int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        vector<vector<int>> freq(n+1);
        //map <int, vector<int>, greater<>> freq;
        for (auto it:mp){
            freq[it.second].push_back(it.first);
        }
        vector<int> answer;
        int index=n;
        for (int i=0; i<k, index>=0; i+=0){
            int j=0;
            while(i<k && j<freq[index].size()){
                answer.push_back(freq[index][j]);
                j++;
                i++;
            }
            index--;
        }
        return answer;
    }
};