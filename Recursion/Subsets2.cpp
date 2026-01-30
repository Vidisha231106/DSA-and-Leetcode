//90

class Solution {
public:
    vector<vector<int>> ans;
    void recursion(vector<int>& nums, int index, vector<int> curr, int n){
        ans.push_back(curr);
        for (int i=index; i<n; i++){
            if (index<i && nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            recursion(nums, i+1, curr, n);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        recursion(nums, 0, vector<int>(), n);
        return ans;
    }
};