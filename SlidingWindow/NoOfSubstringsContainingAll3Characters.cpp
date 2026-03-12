// 1358

class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0;
        int a=0, b=0, c=0;
        int n = s.length();
        int count=0;
        for (int i=0; i<n; i++){ // i=right
            if (s[i]=='a') a++;
            else if (s[i]=='b') b++;
            else if (s[i]=='c') c++;
            while (a>0 && b>0 && c>0){
                count+=(n-i);
                if (s[left]=='a') a--;
                else if (s[left]=='b') b--;
                else if (s[left]=='c') c--;
                left++;
            }
        }
        return count;
    }
};