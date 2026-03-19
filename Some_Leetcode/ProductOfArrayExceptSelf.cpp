// 238

//O(n) approach
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> arr(n,1);
        for (int i=n-2; i>=0; i--){
            arr[i]=nums[i+1]*arr[i+1];
        }
        int prev=1;
        for (int i=0; i<n; i++){
            arr[i]=arr[i]*prev;
            prev=prev*nums[i];
        }
        return arr;
    }
};

