// 84

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack <vector<int>> st;
        vector<int> pse(n, -1);
        vector<int> nse(n, n);
        for (int i=0;i<n; i++){
            while(st.empty()!=true && st.top()[0]>=heights[i]){
                st.pop();
            }
            if (st.empty()!=true) pse[i]=st.top()[1];
            st.push({heights[i], i});
        }
        while (st.empty()!=true) st.pop();
        for (int i=n-1; i>=0; i--){
            while(st.empty()!=true && st.top()[0]>=heights[i]){
                st.pop();
            }
            if (st.empty()!=true) nse[i]=st.top()[1];
            st.push({heights[i], i});
        }
        int max_area=INT_MIN;
        for (int i=0; i<n; i++){
            max_area=max(heights[i]*(nse[i]-pse[i]-1), max_area);
        }
        return max_area;
    }
};