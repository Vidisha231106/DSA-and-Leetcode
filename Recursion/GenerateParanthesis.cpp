//22

class Solution {
public:
    vector <string> para;
    void recursion(int n, int open, int closed, string s){
        if (s.length()==n*2){
            para.push_back(s);
            return;
        }
        if (open<n){
            recursion(n, open+1, closed, s+"(");
        }
        if (closed<open){
            recursion(n, open, closed+1, s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        recursion(n, 0, 0, "");
        return para;
    }
};