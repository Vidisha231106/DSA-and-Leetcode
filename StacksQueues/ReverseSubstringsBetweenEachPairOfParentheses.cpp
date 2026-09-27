// 1190

class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        stack<string> st;
        stack <char> chars;
        for(int i=n-1; i>=0; i--){
            chars.push(s[i]);
        }
        while (chars.empty()!=true){
            if (chars.top()=='('){
                string curr=""; // for the word
                st.push("(");
                chars.pop();// remove '('
                while (chars.empty()!=true && (chars.top()!='(' && chars.top()!=')')){
                    curr=curr+chars.top();
                    cout<<curr<<endl;
                    chars.pop();
                }
                //string c(1, chars.top());
                st.push(curr);
                //st.push(c);
            }
            else{
                if (chars.top()==')') {
                    string c(1, chars.top());
                    st.push(c);
                    chars.pop();
                }
                else {
                    string curr="";
                    while (chars.empty()!=true && (chars.top()!='(' && chars.top()!=')')){
                        curr=curr+chars.top();
                        cout<<"here: "<<curr<<endl;
                        chars.pop();
                    }
                    st.push(curr);
                }
                //cout<<"here: "<<c<<endl;
            }
        }
        stack<string> temp;
        while (st.empty()!=true){
            while (st.empty()!=true && st.top()!="("){
                temp.push(st.top());
                st.pop();
            }
            int flag=0;
            if (st.empty()!=true) flag=1;
            if (st.empty()!=true) st.pop();// remove '('
            string curr="";
            //if (st.empty()==true) return curr;
            while (temp.empty()!=true && temp.top()!=")"){
                curr+=temp.top();
                temp.pop();
            }
            if (temp.empty()!=true && temp.top()==")") temp.pop(); // remove ')'
            if (flag==1) reverse(curr.begin(), curr.end());
            st.push(curr);
            while (temp.empty()!=true){
                st.push(temp.top());
                temp.pop();
            }
            if (flag==0) break;
        }
        cout<<"here5"<<endl;
        string ans=st.top();
        
        return ans;
    }
};