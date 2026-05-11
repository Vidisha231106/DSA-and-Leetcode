// 3844

class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.length();
        int answer=2;
        vector<vector<int>> palindrome(n, vector<int>(n,0));
        vector<vector<int>> almost_pal(n, vector<int>(n,0));
        for (int i=0; i<n-1; i++){
            // one letter palindromes
            palindrome[i][i]=1;
            almost_pal[i][i]=1;
            // two letter palindromes
            if (s[i]==s[i+1]) palindrome[i][i+1]=1;
            almost_pal[i][i+1]=1;
        }
        for (int i=n-3; i>=0; i--){
            for (int j=1; j<n; j++){
                //two cases - s[i]==s[j]  || s[i]!=s[j]

                if (s[i]==s[j]){
                    // prev is an almost palindrome
                    if (almost_pal[i+1][j-1]==1) {
                        almost_pal[i][j]=1;
                        answer=max(answer, j-i+1);
                    }
                    // prev is a palindrome
                    if (palindrome[i+1][j-1]==1)palindrome[i][j]=1;                  
                }
                else {
                    if (palindrome[i+1][j] || palindrome[i][j-1]){
                        almost_pal[i][j]=1;
                        answer=max(answer, j-i+1);
                    }
                }
            }
        }
        return answer;
    }
};