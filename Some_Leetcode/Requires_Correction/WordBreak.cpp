//139 - TLE

class Solution {
public:
    bool ans=false;
    void recursion(string& s, vector<string>& wordDict, int start, int end, string curr){
        if (ans==true) return;
        if (end>=s.size()) return;
        if (find(wordDict.begin(), wordDict.end(), curr) !=wordDict.end()) {
            if (end==s.size()-1) {
                ans=true;
                return;
            }
            string new_curr;
            new_curr.push_back(s[end+1]);
            recursion(s, wordDict, end+1, end+1, new_curr);
        }
        if (end<s.size()-1){
            curr+=s[end+1];
            recursion(s, wordDict, start, end+1, curr);
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        string small_s="";
        small_s.push_back(s[0]);
        recursion(s, wordDict, 0,0, small_s);
        return ans;
    }
};