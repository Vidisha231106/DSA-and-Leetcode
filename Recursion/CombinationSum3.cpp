//216

class Solution {
public:
    vector<vector<int>> ans;
    void recursion(int k, int n, int curr, vector<int>& curr_n, int num){
        if (curr>n) return;
        if (curr_n.size() > k) return;
        if (curr==n){
            if (curr_n.size()==k) ans.push_back(curr_n);
            return;
        }
        if (num>9) return;
        recursion(k, n, curr, curr_n, num+1);
        curr_n.push_back(num);
        recursion(k, n, curr+num, curr_n, num+1);
        curr_n.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        recursion(k, n, 0, temp, 1);
        return ans;
    }
};