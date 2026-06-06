// 4

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if (m>n) return findMedianSortedArrays(nums2, nums1);
        int cut1=m/2;
        int cut2=n/2;
        int left=0;
        int right=m;
        while (left<=right){
            int cut1=(left+right)/2;
            int cut2=(n+m+1)/2 - cut1;

            int l1=(cut1==0)? INT_MIN: nums1[cut1-1];
            int l2=(cut2==0) ? INT_MIN: nums2[cut2-1];
            int r1=(cut1==m) ? INT_MAX: nums1[cut1];
            int r2=(cut2==n) ? INT_MAX: nums2[cut2];
            
            if (l1<=r2 && l2<=r1) {
                if ((n+m)%2 == 0) {
                    return ((double)(max(l1, l2)+min(r1, r2)))/2;
                }
                else{
                    return max(l1,l2);
                }
            }
            else if (l1>r2) right=cut1-1;
            else left=cut1+1;
        } 
        return nums1[m/2];
    }
};