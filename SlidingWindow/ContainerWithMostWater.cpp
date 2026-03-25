// 11

class Solution {
public:
    int maxArea(vector<int>& height) {
        //water is equal to the distance bw the two pointers * the smaller pointer height
        int left=0;
        int n = height.size();
        int max_size=0;
        int curr_size=0;
        int i=n-1; // right
        while (i>left){
            int max_height=min(height[left], height[i]);
            int curr_size = max_height*(i-left);
            max_size = max(max_size, curr_size);
            if (height[left]<height[i]){
                left++;
            }
            else {
                i--;
            }
        }
        return max_size;
    }
};