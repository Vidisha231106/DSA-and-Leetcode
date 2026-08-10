// 44

class Solution {
public:
    bool check(int i, int j, string& s, string& p, vector<vector<int>> &dp){
        if (i==-1 && j==-1) return true;
        if (i<0 && j>=0){
            for (int k=j; k>=0; k--){
                if (p[k]!='*') return false;
            }
            return true;
        }
        if (i>=0 && j<0) return false;
        if (dp[i][j]!=-1) return dp[i][j];
        if (s[i]==p[j] || p[j]=='?'){
            dp[i][j]=check(i-1, j-1, s, p, dp);
            return dp[i][j];
        }
        bool a1=false;
        bool a2=false;
        if (p[j]=='*'){
            a1=check(i-1, j, s, p, dp);
            a2=check(i, j-1, s, p, dp);            
        }
        dp[i][j]=a1|| a2;
        return a1|| a2;
    }
    bool isMatch(string s, string p) {
        int sl=s.length();
        int pl=p.length();
        vector<vector<int>> dp(sl, vector<int> (pl,-1));
        return check(sl-1, pl-1, s, p, dp);
    }
};