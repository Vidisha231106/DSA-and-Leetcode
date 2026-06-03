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

/*Better Code:

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       int n = temperatures.size();
        vector<int> ans(n, 0);
        int hottest = 0;
        
        for (int i = n - 1; i >= 0; --i) {
            if (temperatures[i] >= hottest) {
                hottest = temperatures[i];
                continue;
            }
            int days = 1;
            while (temperatures[i + days] <= temperatures[i])
                days += ans[i + days];
            ans[i] = days;
        }
        return ans;
    }
    
};*/