// 1209

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.length();
        stack <pair<char, int>> st;
        int curr=0;
        for (int i=0; i<n; i++){
            if (st.empty()==true || s[i]!=st.top().first){
                st.push({s[i], 1});
            }
            else if (s[i]==st.top().first){
                st.top().second++;
            }
            if (st.top().second%k==0) st.pop();
        }
        string answer="";
        while (st.empty()!=true){
            for (int i=0; i<st.top().second; i++) answer+=(st.top().first);
            st.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};