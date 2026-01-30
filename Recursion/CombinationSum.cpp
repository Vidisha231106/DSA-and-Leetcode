//39

class Solution {
public:
    vector<vector<int>> ans;
    void recursion(vector<int>& candidates, int index, int target, int curr, vector<int> curr_candidates, int n){
        if (curr>target) return;
        if (curr==target){
            ans.push_back(curr_candidates);
            return;
        } 
        for (int i=index; i<n; i++){
            curr_candidates.push_back(candidates[i]);
            recursion(candidates, i, target, curr+candidates[i], curr_candidates, n);
            curr_candidates.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        recursion(candidates, 0, target, 0, vector<int>(), n);
        return ans;
    }
};