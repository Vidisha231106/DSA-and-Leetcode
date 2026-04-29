// 2033

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        if (n*m==1) return 0;
        vector<int> nums;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                nums.push_back(grid[i][j]);
            }
        } 
        auto mid= nums.begin() + n*m/2;
        nth_element(nums.begin(), mid, nums.end());
        int median = *mid;
        int answer=0;
        
        for (int i=0; i<n*m; i++){

                if (abs(nums[i]-median)%x!=0) return -1;
                answer+=(abs(nums[i]-median)/x);
        }
        return answer;
    }
};