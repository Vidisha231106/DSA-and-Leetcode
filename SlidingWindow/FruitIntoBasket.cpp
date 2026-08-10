// 904

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int> freq;
        int i=0, j=0;
        int max_len=INT_MIN;
        while (j<n){
            freq[fruits[j]]++;
            while (freq.size()>2){
                freq[fruits[i]]--;
                if (freq[fruits[i]]==0){
                    freq.erase(fruits[i]);
                }
                i++;
            }
            max_len=max(max_len, j-i+1);
            j++;
        }
        return max_len;
    }
};