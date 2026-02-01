// 921

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack <char> st;
        int n = s.length();
        for (int i=0; i<n; i++){
            if(st.empty()!=true && st.top()=='(' && s[i]==')'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        int count=0;
        while (st.empty()!=true){
            st.pop();
            count++;
        }
        return count;
    }
};