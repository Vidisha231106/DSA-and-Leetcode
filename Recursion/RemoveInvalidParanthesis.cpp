// 301

class Solution {
public:
    int max_length=-1;
    set<string> ans;
    void recursion(string &s, string curr, int i, int balance, int brac, int open, int close){
        if (i>=s.length()){
            if (balance==0) {
                if ((int)curr.length()>max_length) {
                    ans.clear();
                    ans.insert(curr);
                    max_length=curr.length();
                }
                else if ((int)curr.length()==max_length){
                    ans.insert(curr);
                }
            }
            //else return false;
            return;
        }
        if (open>brac || close>brac) return;
        if ((int)curr.length()+ (int)s.length()-i < max_length) return;
        int n=s.length();
        int x=0;
        if (s[i]=='(') x++;
        else if (s[i]==')') x--;
        if (balance+x>=0){
            curr.push_back(s[i]);
            if (s[i]=='(') recursion(s, curr, i+1, balance+x, brac, open+1, close);
            else if (s[i]==')') recursion(s, curr, i+1, balance+x, brac, open, close+1);
            else recursion(s, curr, i+1, balance+x, brac, open, close);
            curr.pop_back();
        }

        recursion(s, curr, i+1, balance, brac, open, close);
        //return true;
    }
    vector<string> removeInvalidParentheses(string s) {
        int n=s.length();
        int open=0;
        int close=0;
        for(int i=0; i<n; i++){
            if (s[i]=='(') open++;
            else if (s[i]==')') close++;
        }
        int brac=min(open, close);
        recursion(s, "", 0, 0, brac, 0, 0);
        int x=ans.size();
        vector<string> answer(ans.begin(), ans.end());
        return answer;
    }
};