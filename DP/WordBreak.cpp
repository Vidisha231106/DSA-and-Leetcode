//139

//Brute Force Recursion - GIVES TLE

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

//Memoisation

class Solution {
public:
    int recursion (string& s, vector<string> &wordDict, vector<int>& dp, int index, int d){
        int n = s.length();
        if (n==index) return 1;
        if (dp[index]!=-1) return dp[index];
        for (int i=index; i<n; i++){
            int answer=0;
            for (int j=0; j<d; j++){
                if (s.substr(index, i-index+1)== wordDict[j]) {
                    if (recursion(s, wordDict,dp , i+1, d)==1) {
                        dp[index]=1;
                        return 1;
                    }
                }
            }
        }
        dp[index]=0;
        return 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int s_n=s.size();
        int n = wordDict.size();
        vector<int> dp(s_n+1, -1);
        recursion(s, wordDict, dp, 0, n) ;
        return dp[0];
    }
};