// 3876

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd=0;
        int even =0;
        int minEven=INT_MAX;
        int minOdd=INT_MAX;
        int n = nums1.size();
        for (int i=0; i<n; i++){
            if (nums1[i]%2==0) {
                even++;
                minEven = min(minEven, nums1[i]);
            }
            else{
                odd++;
                minOdd = min(minOdd, nums1[i]);
            } 
        }
        if (odd==0 || even==0) return true;
        for (int i=0; i<n; i++){
            if (nums1[i]%2==0){
                if (nums1[i]-minOdd<1) return false;
            }
        }
        return true;
    }
};