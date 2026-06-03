// 739

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> answer(n,0);
        stack <pair<int ,int>> st;
        
        for (int i=0; i<n; i++){
            pair<int, int> curr={temperatures[i], i};
            while (st.empty()!=true && st.top().first<temperatures[i]){
                answer[st.top().second]=(abs(i-st.top().second));
                st.pop();
            }
            st.push(curr);
        }
        return answer;
    }
};