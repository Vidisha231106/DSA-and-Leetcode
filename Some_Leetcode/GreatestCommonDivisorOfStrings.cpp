//1071

class Solution {
public:
    int fn(int n, int m){
        for (int i=min(m,n); i>=1; i--){
            if (n%i==0 && m%i==0) {
                return i;
            }
        }
        return 1;
    }
    string gcdOfStrings(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int gcd = fn(n,m);
        string answer=str1.substr(0, gcd);
        for (int i=0; i<n; i+=gcd){
            if (answer!=str1.substr(i, gcd)) return "";
        }
        for (int i=0; i<m; i+=gcd){
            if (answer!=str2.substr(i, gcd)) return "";
        }
        return answer;
    }
};