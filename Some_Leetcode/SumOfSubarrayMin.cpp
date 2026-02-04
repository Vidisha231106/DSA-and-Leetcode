//907

//Inefficient Solution 1- TLE and complicated

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const long long mod = 1000000007LL;
        int n= arr.size();
        long long sum=0;
        for (int i=0; i<n; i++){
            int min_num = arr[i];
            for (int j=i; j<n; j++){
                min_num= min(min_num, arr[j]);
                sum=(sum+ min_num)%mod;
            }
        }
        return (int)sum;
    }
};

//Inefficient Solution 2- TLE

class Solution {
public:
    vector<vector<int>> subarrays;
    void recursion(vector<int>& arr, int start, int end, vector<int> sub, int n){
        if (start>=n) return;
        if (end>=n) {
            recursion(arr, start+1, start+1, vector<int>(), n);
            return;
        }
        sub.push_back(arr[end]);
        subarrays.push_back(sub);
        recursion(arr, start, end+1, sub, n);
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        recursion(arr, 0, 0, vector<int>(), n);
        int subs_size=subarrays.size();
        int sum=0;

        for (int i=0; i<subs_size; i++){
            if (subarrays[i].empty()==true) continue;
            sum+= *min_element(subarrays[i]. begin(),  subarrays[i].end());
        }
        return sum;
    }
};