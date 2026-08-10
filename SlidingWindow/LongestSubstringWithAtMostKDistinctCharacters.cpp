// 340

class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
        int n=s.length();
        int i=0, j=0;
        unordered_map <char,int> freq;
        int max_len=INT_MIN;
        while (j<n){
            freq[s[j]]++;
            while (freq.size()>k){
                freq[s[i]]--;
                if (freq[s[i]]==0) freq.erase(s[i]);
                i++;
            }
            max_len=max(max_len, j-i+1);
            j++;
        }
        return max_len;
    }
};