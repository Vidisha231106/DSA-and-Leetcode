// 215. Kth Largest Element in an Array

/*Time Limit Exceeded
39 / 44 testcases passed
Last Executed Input
Use Testcase
nums =
[4609,1245,1090,-7811,3316,-3695,-9115,-5413,-1407,-5563,-5936,2393,-7132,5703,-2798,-5369,-2226,-2797,7536,-4994,-3785,9598,1915,9722,6481,9668,-4148,-9339,387,4886,-1706,5035,-1737,-3107,-3627,-564,9327,7099,6982,1768,-3004,2600,-7010,2966,3870,-2269,-9324,-4209,9131,6153,5042,5680,3227,4216,8977,8657,9561,1217,-8917,-5032,2535,1520,-7979,6643,2992,8843,-6998,6506,9800,3815,-1080,7400,-2178,1980,-7347,713,-2913,2816,3421,7614,1882,-1514,4692,3987,-1849,-357,-8757,4508,-9514,3760,-2779,-9258,5647,3473,5715,-7113,-611,3547,547,-7221,6048,-8349,385,-8590,7261,-7781,-7408,-1766,6873,-7599,-3297,1294,-7557,5291,5386,-8611,-5790,-6911,-6111,5319,843,-1801,2459,-4863,2640,-2219,9183,8716,-8298,-2123,
View more
k =
13377
Code
C
Analyze Complexity*/

#include <limits.h>
int findKthLargest(int* nums, int numsSize, int k) {
    int smallest = nums[0];
    for (int i =0; i<numsSize; i++){
        if (nums[i]<smallest) smallest = nums[i];
    }
    int largest =0;
    while (k!=0){
        largest=INT_MIN;
        for (int i=0; i<numsSize; i++){
            if (largest<nums[i]){
                largest = nums[i];
            } 
        }
        for (int i=0; i<numsSize; i++){
            if (nums[i]==largest) {
                nums[i]=smallest;
                break;
            }
        }
        k--;
    }
    return largest;
}