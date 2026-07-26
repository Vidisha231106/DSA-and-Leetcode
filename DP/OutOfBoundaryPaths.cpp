// 576

class Solution {
public:
    const int MOD = 1e9+7;
    int recursion(int m, int n, int r, int c, int moves, vector<vector<vector<long long>>>& dp){
        if (r>=m || c>=n || r<0 || c<0){
            return 1;
        }
        if (moves<=0) return 0;
        if (dp[r][c][moves]!=-1) return dp[r][c][moves];
        vector <pair<int, int>> dir={{0,-1}, {0, 1}, {-1, 0}, {1, 0}};
        long long paths=0;
        for (int i=0; i<4; i++){
            paths=(paths+ recursion(m, n, r+dir[i].first, c+dir[i].second, moves-1, dp))%MOD;
        }
        dp[r][c][moves]=paths;
        return paths;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long long>>> dp (m, vector<vector<long long>> (n, vector<long long> (maxMove+1, -1)));
        return recursion(m, n, startRow, startColumn, maxMove, dp);
    }
};