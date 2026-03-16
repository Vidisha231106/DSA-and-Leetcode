// 907

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        // nums[i] * left[i] * right[i]
        stack <int> st;
        vector <int> pse(n,0);
        vector <int> nse(n,0);
        //prev smallest element
        for (int i=0; i<n; i++){
            if (st.empty()==true) {
                pse[i]=-1;
            }
            else{
                while (st.empty()!=true && arr[st.top()]>arr[i]) st.pop();
                pse[i]= (st.empty()==true)? -1: st.top();
            }
            st.push(i);
        }
        while(st.empty()!=true) st.pop();
        //next smallest element
        for (int i=n-1; i>=0; i--){
            if (st.empty()==true) nse[i]=n;
            else {
                while (st.empty()!=true && arr[st.top()]>=arr[i]) st.pop();
                nse[i]=(st.empty()==true) ? n: st.top();
            }
            st.push(i);
        }
        long long ans=0;
        for (int i=0; i<n; i++) ans += (long long) arr[i]*(i- pse[i])*(nse[i]-i);
        return ans%1000000007;
    }
};