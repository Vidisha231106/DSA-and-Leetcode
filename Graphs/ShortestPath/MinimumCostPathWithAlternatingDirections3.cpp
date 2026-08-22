// 4003

class Solution {
public:
    bool check(int r, int c, int m, int n){
        if (r<0 || c<0 || r>=m || c>=n) return false;
        return true;
    }
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        priority_queue <vector<long long>, vector<vector<long long>>, greater<>> pq;
        // {cost, x, y, move, waiting_flag}
        vector<vector<int>> odd={{0, 1}, {1, 0}};
        vector<vector<int>> even={{0, -1},{-1,0} };
        pq.push({1, 0, 0, 0, 0});
        vector<vector<vector<long long>>> visited(m , vector<vector<long long>> (n, vector<long long>(2, LLONG_MAX)));
        visited[0][0][0]=1;
        while(pq.empty()!=true){
            vector<long long> curr=pq.top();
            pq.pop();
            long long cost=curr[0];
            long long r=curr[1];
            long long c=curr[2];
            long long move=curr[3];
            long long waiting=curr[4];
            if (visited[r][c][move%2]<cost) continue;
            // if (waiting!=0){
            //     if (visited[r][c]>cost) visited[r][c]=cost;
            // }
            visited[r][c][move%2]=cost;
            if (r==m-1 && c==n-1) return cost;
            int nr, nc;
            if (move%2==0){
                for (int i=0; i<2; i++){
                    nr=r+odd[i][0];
                    nc=c+odd[i][1];
                    if (check(nr, nc, m, n)){
                        if (visited[nr][nc][(move+1)%2]>1LL* (nr+1)*(nc+1)+cost){
                            visited[nr][nc][(move+1)%2]=1LL* (nr+1)*(nc+1)+cost;
                            pq.push({1LL* (nr+1)*(nc+1)+cost, nr, nc, move+1, 0});
                        }
                    } 
                }
                for (int i=0; i<2; i++){
                    nr=r+even[i][0];
                    nc=c+even[i][1];
                    if (check(nr, nc, m, n)){
                        if (visited[nr][nc][(move+1)%2]>1LL* (penalty[r][c]+(nr+1)*(nc+1)+cost)){
                            visited[nr][nc][(move+1)%2]=1LL* (penalty[r][c]+(nr+1)*(nc+1)+cost);
                            pq.push({1LL* (penalty[r][c]+(nr+1)*(nc+1)+cost), nr, nc, move+1, 0});
                        }
                    } 
                }     
            }
            else{
                for (int i=0; i<2; i++){
                    nr=r+even[i][0];
                    nc=c+even[i][1];
                    if (check(nr, nc, m, n)){
                        if (visited[nr][nc][(move+1)%2]>1LL* (nr+1)*(nc+1)+cost){
                            visited[nr][nc][(move+1)%2]=1LL* (nr+1)*(nc+1)+cost;
                            pq.push({1LL* (nr+1)*(nc+1)+cost, nr, nc, move+1, 0});
                        }
                    } 
                }    
                for (int i=0; i<2; i++){
                    nr=r+odd[i][0];
                    nc=c+odd[i][1];
                    if (check(nr, nc, m, n)){
                        if (visited[nr][nc][(move+1)%2]>1LL* (penalty[r][c]+(nr+1)*(nc+1)+cost)){
                            visited[nr][nc][(move+1)%2]=1LL* (penalty[r][c]+(nr+1)*(nc+1)+cost);
                            pq.push({1LL* (penalty[r][c]+(nr+1)*(nc+1)+cost), nr, nc, move+1, 0});
                        }
                    } 
                }           
            }
            if (waiting==0) {
                if (visited[r][c][(move+1)%2]>1LL* penalty[r][c]+cost){
                    visited[r][c][(move+1)%2]=1LL* penalty[r][c]+cost;
                    pq.push({1LL* penalty[r][c]+cost, r, c, move+1, 1});
                }
            }
        }
        return -1;
    }
};