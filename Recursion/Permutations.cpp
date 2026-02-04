// 46

class Solution {
public:
    vector<vector<int>> ans;
    void swap_pos(int& n1, int &n2){
        int temp = n1;
        n1=n2;
        n2=temp;
    }
    void recursion(vector<int>&nums, int index, int n){
        if (index==n) {
            ans.push_back(nums);
            return;
        }
        for (int i=index; i<n; i++){
            swap_pos( nums[i], nums[index]);
            recursion(nums, index+1, n);
            swap_pos(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        recursion(nums, 0, n);
        return ans;
    }
};