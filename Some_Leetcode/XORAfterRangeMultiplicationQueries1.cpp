// 3653

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = nums.size();
        for (int i=0; i<n; i++){
            int index= queries[i][0];
            while (index<=m && index<=queries[i][1]){
                nums[index] = ((long long) nums[index]*queries[i][3])%1000000007;
                index+=queries[i][2];
            }
        }
        int result=nums[0];
        for (int i=1; i<m; i++){
            result^=nums[i];
        }
        return result;
    }
};