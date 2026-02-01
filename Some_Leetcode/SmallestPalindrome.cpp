// 214 - IMPORTANT 

// Better Solution
class Solution {
public:
    string shortestPalindrome(string s) {
        string revS = s;
        reverse(revS.begin(), revS.end());
        string str = s+"#"+revS;

        int n = str.length();
        vector<int > lps(n+1, 0);
        int i=1, j=0;

        while(i < n){
            if(str[i] == str[j]){
                lps[++i] = ++j;
            }
            else if(j == 0){
                i++;
            }
            else{
                j = lps[j];
            }
        }

        string temp = s.substr(lps[n]);
        reverse(temp.begin(), temp.end());

        return temp+s;
    }
};

//My Solution
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s=="") return "";
        int n = s.length();
        string rev=s;
        reverse(rev.begin(), rev.end());
        if (s==rev) return s;
        for (int i=0; i<n; i++){
            if (memcmp(s.c_str(), rev.c_str()+i, n-i)==0) return rev.substr(0, i)+s;
        }
        return s;
    }
};