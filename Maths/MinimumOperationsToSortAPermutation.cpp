// 3942

class Solution {
public:
    int minOperations(vector<int>& nums) {
        //if diff bw two consecutive elements is not zero, then return -1
        int n=nums.size();
        int decreasing=1;
        int increasing=1;
        int zero=0;
        for (int i=0; i<n; i++){
            if (nums[i]==0) {
                zero=i;
                break;
            }
        }
        for (int i=0; i<n; i++){
            if (nums[(zero+i)%n]!=i) {
                increasing=0;
                break;
            } 
        }   
        for (int i=0; i<n; i++){
            if (nums[(n+zero-i)%n]!=i) {
                decreasing=0;
                break;
            } 
        }   
        int ans=INT_MAX;
        if (decreasing==0 && increasing==0) return -1;
        if (increasing==1){
            int a=n-1-zero;
            ans=min({zero, (a+1)%n +2, (n-a-1)+2});//2 reverses wrapping around some k rotates
        }
        if (decreasing==1){
            ans=min({ans, 1+(n-1-zero), 1+(zero+1)%n});
        }
        return ans;
    }
};