// 40

class Solution {
public:
    vector<vector<int>> ans;
    void recursion(vector<int> &candidates, int target, int curr, int index, vector <int> curr_candidates, int n){
        
        if (curr>target) return;
        if (curr==target){
            ans.push_back(curr_candidates);
            return;
        }
        
        for (int i=index; i<n; i++){
            if (i>index && candidates[i]==candidates[i-1]) continue;
            curr_candidates.push_back(candidates[i]);
            recursion(candidates, target, curr+candidates[i], i+1, curr_candidates, n);
            curr_candidates.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        recursion(candidates, target, 0, 0, vector<int>(), n);
        return ans;
    }
};