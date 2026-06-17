// 3614

class Solution {
public:
    char processStr(string s, long long k) {
        long long n=s.length();
        long long max_length=0;
        vector<long long> v(n);
        for (int i=0; i<n; i++){
            if (s[i]>='a' && s[i]<='z'){
                max_length++;
            }
            else if (s[i]=='*' && max_length>0){
                max_length--;
            }
            else if (s[i]=='#'){
                max_length*=2;
            }
            else if (s[i]=='%'){
                //max_length wont change
            }
            v[i]=max_length;
        }
        if (k>=v[n-1]) return '.';
        for (int i=n-1; i>=0; i--){
            if (s[i]>='a' && s[i]<='z'){
                if (k==v[i]-1) return s[i];
            }
            else if (s[i]=='*' && i>0){
                //if (k==v[i]-1) return s[i-1];
            }
            else if (s[i]=='#'){
                if (v[i]/2>0) k%=(v[i]/2);
            }
            else if (s[i]=='%'){
                k=v[i]-k-1;
            }
        }
        return '.';
    }
};