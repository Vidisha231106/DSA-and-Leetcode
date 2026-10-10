// 1963

class Solution {
public:
    int minSwaps(string s) {
        int n=s.length();
        int right=n-1;
        int open=0;
        int count=0;
        int close=0;
        for(int i=0; i<n; i++){
            if (s[i]=='[') open++;
            else close++;
            if (close>open){
                while (right>=i && s[right]!='['){
                    right--;
                }
                if (right>=0) s[right]=']';
                s[i]='[';
                open++;
                close--;
                count++;
            }
        }
        return count;
    }
};