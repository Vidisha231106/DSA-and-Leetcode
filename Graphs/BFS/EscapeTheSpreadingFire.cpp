// 2258

class Solution {
public:
    int check(int r, int c, int n, int m){
        if (r<0 || c<0 || r>=n || c>=m) return false;
        return true;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> fire(n, vector<int>(m ,INT_MAX));
        queue <vector<int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (grid[i][j]==1) {
                    q.push({i, j, 0});
                    fire[i][j]=0;
                }
            }
        }
        vector<vector<int>> dir={{-1,0}, {1,0}, {0, -1},{0,1}};

        while (q.empty()==false){
            vector<int> curr=q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nr=curr[0]+dir[i][0];
                int nc=curr[1]+dir[i][1];
                if (check(nr, nc, n, m)==false) continue;
                if (fire[nr][nc]!=INT_MAX) continue;
                if (grid[nr][nc]==0) {
                    fire[nr][nc]=curr[2]+1;
                    q.push({nr, nc, curr[2]+1});
                }
            }
        }
        int l=0, r=1000000000; //max(fire[0][1], fire[1][0]);
        int answer=-1;
        // fire represents the number of moves after which a grass cell will catch fire
        while(l<=r){
            int mid= (l+r)/2;
            int flag=0;
            if (fire[0][0]<=mid){
                r=mid-1;
                continue;
            }
            queue<vector<int>> q;
            q.push({0,0, mid});
            vector<vector<int>> visited(n, vector<int>(m, 0));
            //visited[0][0]=1;
            while (q.empty()==false){
                vector<int> curr=q.front();
                q.pop();
                if (visited[curr[0]][curr[1]]==1) continue;
                visited[curr[0]][curr[1]]=1;
                if (grid[curr[0]][curr[1]]!=0) continue;
                if (curr[0]!=n-1 || curr[1]!=m-1){
                    if (fire[curr[0]][curr[1]]<=curr[2]) continue; // faulty path
                }
                if (curr[0]==n-1 && curr[1]==m-1){
                    flag=1;
                    break;
                } 
                for(int i=0; i<4; i++){
                    int nr=curr[0]+dir[i][0];
                    int nc=curr[1]+dir[i][1];
                    if (grid[curr[0]][curr[1]]!=0) continue;
                    if (check(nr, nc, n, m)==false) continue;
                    
                    if (nr==n-1 && nc==m-1){
                        if (fire[nr][nc]<curr[2]+1) continue;
                    } 
                    else {
                        if (fire[nr][nc]<=curr[2]+1) continue;
                    }
                    q.push({nr, nc, curr[2]+1});
                }
            }
            if (flag==1){
                answer=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return answer;
    }
};