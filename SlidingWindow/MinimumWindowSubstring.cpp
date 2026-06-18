// 76

class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        if (m<n) return "";
        int left=0; 
        int right=0;
        int count=0;
        int index=0;
        int answer=INT_MAX;
        unordered_map <int, int> mp;
        for (int i=0; i<n; i++) mp[t[i]]++;
        while (right<m){
            if (mp.contains(s[right]) && mp[s[right]]>0) count++;
            mp[s[right]]--;
            
            while (count==n && left<=right){
                if (right-left+1<answer) {
                    answer=right-left+1;
                    index=left;
                }
                mp[s[left]]++;
                if (mp[s[left]]>0) {
                    count--;
                } 
                left++;
            }
            right++;
        }
        if (answer==INT_MAX) return "";
        string ans_s="";
        for (int i=index; i<index+answer; i++){
            ans_s+=s[i];
        }
        return ans_s;
    }
};