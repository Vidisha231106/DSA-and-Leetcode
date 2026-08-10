// 424

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int max_len=INT_MIN;
        int max_freq=INT_MIN;
        unordered_map <char, int> freq;
        int i=0, j=0;
        while (j<n){
            freq[s[j]]++;
            max_freq=max(max_freq, freq[s[j]]);
                // illegal char int subsequence
                while (j-i+1>max_freq+k){
                    freq[s[i]]--;
                    i++;
                }
            max_len=max(max_len, j-i+1);
            j++;
        }
        return max_len;
    }
};