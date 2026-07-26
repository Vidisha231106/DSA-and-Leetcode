// 688

class Solution {
public:
    double recursion (int n, int k, int r, int c, int curr, vector<vector<vector<double>>> &dp){
        if (r>=n || c>=n|| r<0 ||c<0) return 0;
        if (curr==0) return 1;
        if (dp[r][c][curr]!=-1) return dp[r][c][curr];
        double prob=0;
        vector<pair<int,int>> moves={{-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {2,-1},{2, 1}, {-2, -1}, {-2, 1}};
        for (int i=0; i<8; i++){
            prob+=(recursion(n, k, r+moves[i].first, c+moves[i].second, curr-1, dp)/8.0);
        }
        dp[r][c][curr]=prob;
        return dp[r][c][curr];
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>> (n, vector<double>(k+1,-1)));
        return recursion(n, k, row, column, k, dp);
    }
};