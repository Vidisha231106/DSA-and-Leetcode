// 856

class Solution {
public:
    int scoreOfParentheses(string str) {
        int n=str.length();
        // push all elements to the stack
        //INT_MIN for opening brackets 
        // INT_MAX for closing brackets
        stack <int> s;
        int i=0;
        while (i<n){
            if (str[i]=='('){
                s.push(INT_MIN);
            }
            else if (str[i]==')'){
                int ans=0;
                while (s.top()!=INT_MIN){
                    ans+=s.top();
                    s.pop();
                }
                s.pop();// pop (
                ans=ans*2;
                if (ans==0) ans=1;
                s.push(ans);
            }
            i++;
        }
        int a=0;
        while (s.empty()!=true){
            a+=s.top();
            s.pop();
        }
        return a;
    }
};