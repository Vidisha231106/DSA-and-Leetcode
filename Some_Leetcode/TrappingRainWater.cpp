// 42

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left_max=0;
        int right_max=0;
        int left=0, right=n-1;
        int answer=0;
        while (left<right){
            if (height[left]<=height[right]) {
                left_max= max(height[left], left_max);
                answer+=(left_max-height[left]);
                left++;
            }
            else if (height[left]>height[right]) {
                right_max=max(height[right], right_max);
                answer+=(right_max-height[right]);
                right--;
            }
        }
        return answer;
    }
};