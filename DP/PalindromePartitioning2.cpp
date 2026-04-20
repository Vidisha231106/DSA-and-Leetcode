// 132

//Memoisation - gives TLE 

class Solution {
public:
    
    bool isPalindrome(string s, int b, int e){
        while(b<e){
            if(s[b]!=s[e]) return false;
            b++;
            e--;
        }
        return true;
    }
    int recursion(string s, int index, vector<int>&dp){
        int n = s.length();
        if (index==n || isPalindrome(s, index, n-1)==true) return 0;
        if (dp[index]!=-1) return dp[index];
        int count=INT_MAX;
        for (int i=index; i<n; i++){
            if (isPalindrome(s, index, i)==true){
                int curr_count=1+recursion(s, i+1, dp);
                count=min(count, curr_count);
            }
        }
        dp[index]=count;
        return count;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int>dp(n,-1);
        return recursion(s, 0, dp);
    }
};

//Tabulation - better solution - still gives TLE 

class Solution {
public:
    bool isPalindrome(string s, int b, int e){
        while(b<e){
            if(s[b]!=s[e]) return false;
            b++;
            e--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.length();
        vector<int>dp(n+1,-1);
        // return recursion(s, 0, dp);
        for (int i=n-1;i>=0; i--){
            int count=INT_MAX;
            for (int j=i; j<n; j++){
                if (isPalindrome(s, i, j)==true){
                    if (j==n-1) count=0;
                    else{
                        int curr_count=1+dp[j+1];
                        count=min(count, curr_count);
                    } 
                }
            }
            dp[i]=count;
        }
        return dp[0];
    }
};

//Tabulation - precompute palindrome results like Palindrome Partitioning 1

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> is_palindrome(n+1, vector<int>(n, -1));
        for (int i=n-1; i>=0; i--){
            for (int j=0; j<n; j++){
                if (s[i]==s[j] && (j-i<=1 || is_palindrome[i+1][j-1]!=-1)) is_palindrome[i][j]=1;
            }
        }
        vector<int>dp(n+1,-1);
        // return recursion(s, 0, dp);
        for (int i=n-1;i>=0; i--){
            int count=INT_MAX;
            for (int j=i; j<n; j++){
                if (is_palindrome[i][j]==1){
                    if (j==n-1) count=0;
                    else{
                        int curr_count=1+dp[j+1];
                        count=min(count, curr_count);
                    } 
                }
            }
            dp[i]=count;
        }
        return dp[0];
    }
};