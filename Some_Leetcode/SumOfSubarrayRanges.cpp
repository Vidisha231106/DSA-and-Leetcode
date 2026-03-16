// 2104

//O(n^3) solution: 

class Solution {
public:
    long long sum=0;
    void recursion(vector<int>& nums, int curr, int max_index){
        if (max_index==curr) return;
        for (int i=curr; i<max_index; i++){
            long long range = *max_element(nums.begin()+curr, nums.begin()+i+1)- *min_element(nums.begin()+curr, nums.begin()+i+1);
            sum+=range;
        }
        recursion(nums, curr+1, max_index);
    }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        recursion(nums, 0, n);
        return sum;
    }
};

// O(n) solution: 

class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
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
        long long ans_min=0;
        for (int i=0; i<n; i++) ans_min += (long long) arr[i]*(i- pse[i])*(nse[i]-i);
        return ans_min;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        // nums[i] * left[i] * right[i]
        stack <int> st;
        vector <int> ple(n,0);
        vector <int> nle(n,0);
        //prev largest element
        for (int i=0; i<n; i++){
            if (st.empty()==true) {
                ple[i]=-1;
            }
            else{
                while (st.empty()!=true && arr[st.top()]<arr[i]) st.pop();
                ple[i]= (st.empty()==true)? -1: st.top();
            }
            st.push(i);
        }
        while(st.empty()!=true) st.pop();
        //next largest element
        for (int i=n-1; i>=0; i--){
            if (st.empty()==true) nle[i]=n;
            else {
                while (st.empty()!=true && arr[st.top()]<=arr[i]) st.pop();
                nle[i]=(st.empty()==true) ? n: st.top();
            }
            st.push(i);
        }
        long long ans_max=0;
        for (int i=0; i<n; i++) ans_max += (long long) arr[i]*(i- ple[i])*(nle[i]-i);
        return ans_max;
    }
    long long subArrayRanges(vector<int>& nums) {
        return (long long) sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};