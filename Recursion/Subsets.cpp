//78

class Solution {
public:
    vector<vector<int>> ans;
    void recursion(vector <int> nums, int n, int index, vector <int> curr){
        if (index==n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        recursion(nums, n, index+1, curr);
        curr.pop_back();
        recursion(nums, n, index+1, curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        recursion(nums, n, 0, vector<int>());
        return ans;
    }
};