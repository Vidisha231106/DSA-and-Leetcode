// 3

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0; 
        int n = s.length();
        int right=0;
        int maxLength=0;
        unordered_map <char, int> mp;
        for (int i=0; i<n; i++){
            while (mp[s[i]]>0) {
                mp[s[left]]--;
                left++;
            }
            mp[s[i]]++;
            if (maxLength < i-left+1) maxLength=i-left+1;
        }
        return maxLength;
    }
};