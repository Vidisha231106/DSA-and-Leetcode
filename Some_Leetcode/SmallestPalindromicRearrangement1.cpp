//3517

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector <int> freq(26, 0);
        for (int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }
        string once="";
        string ans="";
        for (int i=0;i<26; i++){
                for (int j=0; j<freq[i]/2 ; j++) ans+=('a'+i);
            
            if (freq[i]%2!=0){
                once+=('a'+i);
            }
        }
        string rev=ans;
        reverse(rev.begin(), rev.end());
        ans=ans+once+rev;
        return ans;
    }
};