// 1477

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int left=0;
        int right=0;
        int curr=0;
        int ans=INT_MAX;
        vector<int> windows(n+1, INT_MAX);
        while (right<n){
            curr+=arr[right];
            while (curr>target){
                curr-=arr[left];
                left++;
            }
            windows[right+1]=windows[right];
            if (curr==target) {
                windows[right+1]=min((right-left+1), windows[right]);
                if (windows[left]!=INT_MAX) ans=min(ans,windows[right]+(right-left+1));
            }
            right++;
        }
        if (ans==INT_MAX) return -1;
        return ans;
        
    }
};