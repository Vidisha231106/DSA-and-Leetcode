// 3665

class Solution {
public:
    const int MOD=1e9+7;
    // prev=0 ->right, 1->down, -1->nothing
    vector<vector<int>> dir={{0,-1}, {-1,0}};
    //int count=0;
    int dfs(vector<vector<int>>& grid, int x, int y, int prev, vector<vector<vector<int>>> &dp){
        //if (x>=n || x<0 || y>=m || y<0) return 0;
        if (x==0 && y==0) {
            //cout<<"-------------------------------------"<<endl;
            return 1;
        }
        if (dp[x][y][prev+1]!=-1) return dp[x][y][prev+1];
        int ans=0;
        for(int i=0; i<2; i++){
            long long curr=0;
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            if (nx<0 ||  ny<0) continue;
            //cout<<prev<<" -> "<<nx<<" "<<ny<<endl;
            if (grid[x][y]==0){
                if (nx-x==-1) curr=dfs(grid,nx ,ny , 0, dp);
                else curr=dfs(grid,nx ,ny , 1, dp);
            }
            else{
                if (nx-x==-1 && ny-y==0 && prev!=0) curr=dfs(grid, nx, ny,0, dp);
                else if (nx-x==0 && ny-y==-1 && prev!=1) curr=dfs(grid, nx, ny, 1, dp);   
            }
            ans+=(curr%MOD);
        }
        dp[x][y][prev+1]=(ans%MOD);
        return ans;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (3, -1)));
        long long ans=dfs(grid,n-1, m-1, -1, dp);
        return ans%MOD;
    }
};