//1130

class Solution {
public:
    //maximise nodes from left and right branches
    //minimise sum of non-leaf nodes

    //{largest_node, prod}
    pair<int, int> recursion(vector<int> & arr, int start, int end, vector<vector<pair<int, int>>>& dp, int &n){
        if (start==end) return {arr[start], 0};
        if (dp[start][end].first!=-1) return dp[start][end];
        int max_num=INT_MIN;
        int min_sum=INT_MAX;
        for (int i=start; i<end; i++){
            pair<int, int> left=recursion(arr, start, i, dp, n);
            pair<int, int> right=recursion(arr, i+1, end, dp, n);
            max_num=max({max_num, left.first, right.first});
            min_sum=min(min_sum, (left.second+right.second+(left.first*right.first)));
        }
        dp[start][end]={max_num, min_sum};
        return dp[start][end];
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n= arr.size();
        vector<vector<pair<int, int>>> dp(n+1, vector<pair<int, int>>(n+1, {-1, -1}));
        pair <int, int> answer=recursion(arr, 0, n-1, dp, n);
        return answer.second;
    }
};