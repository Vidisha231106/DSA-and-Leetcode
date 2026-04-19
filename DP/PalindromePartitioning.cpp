// 131

// DP solution - IMPORTANT!!!

class Solution {
public:
    vector<vector<string>> answer;
    void recursion(string& s, int i, int n, vector<string>& curr, vector<vector<int>> &dp){
        if (i>=n){
            answer.push_back(curr);
            return;
        } 

        for (int j=i; j<n; j++){

            if (dp[i][j]){
                curr.push_back(s.substr(i, j-i+1));
                recursion(s, 1+j, n, curr, dp);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<int>> dp(n+1, vector<int>(n,0));
        for (int i=n-1; i>=0; i--){
            for (int j=i; j<n; j++){
                if (s[i]==s[j] && (j-i<=2 || dp[i+1][j-1])) dp[i][j]=1;
            }
        }
        vector<string> curr;
        recursion(s, 0, n, curr, dp);
        return answer;
    }
};

// O(n^3) approach

class Solution {
public:
    vector<vector<string>> answer;
    bool isPalindrome(string s){
        int n = s.length();
        if (n==1) return true;
        for (int i=0; i<n; i++){
            if (s[i]!=s[n-i-1]) return false; 
        }
        return true;
    }
    void recursion(string s, int i, int n, vector<string> curr){
        if (i>=n){
            answer.push_back(curr);
            return;
        } 
        string new_s="";
        for (int j=i; j<n; j++){
            new_s.push_back(s[j]);
            if (isPalindrome(new_s)){
                curr.push_back(new_s);
                recursion(s, 1+j, n, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<string> curr;
        recursion(s, 0, n, curr);
        return answer;
    }
};