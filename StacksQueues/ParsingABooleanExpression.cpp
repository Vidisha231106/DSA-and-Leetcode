// 1106

class Solution {
public:
    bool solveOR(string st){
        bool answer=false;
        for(char x: st){
            if (x=='f') answer=(answer|| false);
            else if (x=='t') answer=(answer || true);
        }
        return answer;
    }
    bool solveAND(string st){
        bool answer=true;
        for(char x: st){
            if (x=='f') answer=(answer && false);
            else if (x=='t') answer=(answer && true);
        }
        return answer;
    }    
    bool solveNOT(string st){
        bool answer;
        if (st=="f") answer=true;
        else if (st=="t") answer=false;
        return answer;
    }
    bool parseBoolExpr(string expression) {
        stack <char> s;
        int n=expression.size();
        int i=0;
        while (i<n){
            if (s.empty()==true) s.push(expression[i]);
            else if (expression[i]==')'){
                string temp="";
                while (s.top()!='('){
                    temp=s.top()+temp;
                    s.pop();
                }
                s.pop();
                bool answer=false;
                if (s.top()=='|') answer=solveOR(temp);
                else if (s.top()=='&') answer=solveAND(temp);
                else if (s.top()=='!') answer=solveNOT(temp);
                s.pop();
                if (answer==false) s.push('f');
                else s.push('t');
            }
            else s.push(expression[i]);
            i++;
        }
        if (s.top()=='f') return false;
        return true;
    }
};