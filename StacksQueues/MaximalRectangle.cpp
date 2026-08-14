// 85

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        if (matrix.empty() || matrix[0].empty()) return 0;
        vector<vector<int>> added(n, vector<int> (m, 0));
        int answer=0;

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (matrix[i][j]-'0'==0){
                    added[i][j]=matrix[i][j]-'0';
                }
                else if (i==0){
                    added[i][j]=1;
                }
                else{
                    added[i][j]=added[i-1][j]+1;
                }
            }
            vector<int> pse(m, -1);
            vector<int> nse(m, m);
            stack<vector<int>> st;
            for (int k=0; k<m; k++){
                while (st.empty()!=true && st.top()[0]>=added[i][k]){
                    st.pop();
                }
                if (st.empty()!=true){
                    pse[k]=st.top()[1];
                }
                st.push({added[i][k], k});
            }
            while (st.empty()!=true) st.pop();
            for (int k=m-1; k>=0; k--){
                while (st.empty()!=true && st.top()[0]>=added[i][k]){
                    st.pop();
                }
                if (st.empty()!=true){
                    nse[k]=st.top()[1];
                }
                st.push({added[i][k], k});
            }
            for (int k=0; k<m; k++){
                answer=max(answer, added[i][k]*(nse[k]-pse[k]-1));
            }
        }
        return answer;
    }
};