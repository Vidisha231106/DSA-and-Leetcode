// 1009

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n==0) return 1;
        else if (n==1) return 0;
        string s = "";
        while (n!=0){
            s.push_back(n%2 + '0');
            n/=2;
        }
        reverse(s.begin(), s.end());
        int ans=0;
        int num=s.size();
        for (int i=0; i<num; i++){
            if (s[i]=='0') s[i]='1';
            else s[i]='0';
        }
        
        for (int i=0; i< num; i++){
            ans+=(pow(2,num-i-1)* (s[i]-'0'));
        }
        return ans;
    }
};