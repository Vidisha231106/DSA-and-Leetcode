//150

#include <cctype>   // Required for isdigit()
#include <iostream>

class Solution {
public:
    int operation (int op1, int op2, char op){
        if (op=='+') return op1+op2;
        else if (op=='-') return op2-op1;
        else if (op=='*') return op1*op2;
        else if (op=='/') return op2/op1;
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack <int> myst;
        int n = tokens.size();
        for (int i=0; i<n; i++){
            if (tokens[i].size()>1 || isdigit(tokens[i][0])){
                myst.push(stoi(tokens[i]));
            }
            else{
                int op1= myst.top();
                myst.pop();
                int op2 = myst.top();
                myst.pop();
                int answer = operation(op1, op2, tokens[i][0]);
                myst.push(answer);
            }
        }
        int final_answer = myst.top();
        return final_answer;
    }
};