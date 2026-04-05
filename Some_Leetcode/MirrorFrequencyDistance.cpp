// 3889

class Solution {
public:
    int mirrorFrequency(string s) {
        int n=s.length();
        int answer=0;
        sort(s.begin(), s.end());
        cout<<s<<endl;
        if (n==1) return 1;
        for (int i=0; i<n; i++){
            if (i>0 && s[i]==s[i-1]) continue;
            char m = 'a';
            if (s[i]-'a'>=0 && s[i]-'a'<26){
                int c = s[i]-'a';
                m='z'-c;
            }
            else{
                int c = s[i]-'0';
                m = '9'-c;
            }
            if (s[i] > m  && count(s.begin(), s.end(), m)) continue; //imp
            int c_count=0;
            for (int j=0; j<n; j++){
                if (s[j]==s[i]) c_count++;
            }
            int m_count=0;
            for (int j=0; j<n; j++){
                if (s[j]==m) m_count++;
            }
            answer+=abs(c_count-m_count);
        }
        return answer;
    }
};