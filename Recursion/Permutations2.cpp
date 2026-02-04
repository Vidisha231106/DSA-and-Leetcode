// 47

class Solution {
public:
    vector <vector<int>> ans;
    void swap_pos(int & n1, int & n2){
        int temp = n1;
        n1=n2;
        n2=temp;
    }
    void recursion(vector <int> nums, int n, int index){
        if (index==n){
            ans.push_back(nums);
            return;
        }
        for (int i=index; i<n; i++){
            if (i!=index  && nums[i]==nums[index]) continue;
            swap_pos(nums[i], nums[index]);
            recursion(nums, n, index+1);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        recursion(nums, n, 0);
        return ans;
    }
};