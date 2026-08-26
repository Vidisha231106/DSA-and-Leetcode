// 2904

class Solution {
public:
    
    string shortestBeautifulSubstring(string s, int k) {
        int left=0;
        string answer="";
        string temp="";
        int n=s.length();
        for(int i=0; i<120; i++) answer+='0';
        string initial=answer;
        int curr=0;
        for(int i=0; i<n; i++){
            if (s[i]=='1'){
                curr++;
                if (curr>=k){
                    while (curr>k){
                        if (s[left]=='1') curr--;
                        left++;
                    }
                    while(s[left]=='0') left++;
                    temp=s.substr(left, i-left+1);
                    if (answer.length()>temp.length()) answer=temp;
                    else if (answer.length()==temp.length() && temp<answer) answer=temp;
                }
            }
        }
        if (answer==initial) return "";
        return answer;
    }
};