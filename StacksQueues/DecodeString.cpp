// 394

#include <stack>

class Solution {
public:
    string decodeString(string s) {
        stack <string> st;
        int n = s.length();
        string answer="";
        string current="";
        string current_num="";
        int index=0;
        while (index<n){
            st.push(string(1, s[index]));
            if (!st.empty() && st.top()=="]"){
                st.pop();
                while (!st.empty() && st.top()!="["){
                    current=(st.top())+current;
                    st.pop();
                }
                st.pop(); // pop "["
                while (!st.empty() && isdigit(st.top()[0])==true) {
                    current_num.push_back(st.top()[0]);
                    st.pop();
                }
                reverse(current_num.begin(), current_num.end());
                int num = stoi(current_num); 
                for (int i=0; i<num; i++)answer+=current; 
                st.push(answer);
                current.clear();
                answer.clear();
                current_num.clear();
            }
            index++;
        }
        while (!st.empty()){
            answer=st.top()+ answer;
            st.pop();
        }
        return answer;
    }
};