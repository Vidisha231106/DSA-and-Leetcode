// 1541

class Solution {
public:
    int minInsertions(string s) {
        stack <char> st;
        int n=s.length();
        int index=0;
        int prev=-1;
        int open=0;
        int close=0;
        while (index<n){
            st.push(s[index]);
            if (s[index]==')'){
                if(prev==-1){
                    prev=index;
                    index++;
                    continue;
                }
                else if (prev+1==index && st.size()>=2){
                    st.pop();// remove )
                    st.pop();// remove )
                    //st.pop();// remove (
                    if (st.empty()==true || st.top()!='('){
                        open++;
                    }
                    else if (st.top()=='(') st.pop();
                    prev=-1;
                }
                else if (index-prev!=1) {
                    stack <char> temp;
                    st.pop();
                    temp.push(')');
                    while (st.empty()!=true && st.top()!=')'){
                        temp.push(st.top());
                        st.pop();
                    }
                    if (st.empty()!=true) st.pop(); // pop )
                    if (st.empty()!=true){
                        st.pop(); // remove  (
                    }
                    else open++;
                    close++;
                    while (temp.empty()!=true){
                        st.push(temp.top());
                        temp.pop();
                    }
                    prev=index;
                }
            }
            if (st.empty()!=true) cout<<st.top()<<st.size()<<endl;
            index++;
        }
        while(st.empty()!=true){
            if (st.top()==')'){
                st.pop();
                if (st.empty()==true){
                    open++;
                    close++;
                    continue;
                }
                if (st.top()!=')'){
                    close++;
                    st.pop();// remove (
                }
                else{
                    st.pop();//remove )
                    if (st.empty()==true || st.top()!='(') open++;
                }
            }
            else{
                st.pop();
                close+=2;
            }
        }
        return open+close;
    }
};