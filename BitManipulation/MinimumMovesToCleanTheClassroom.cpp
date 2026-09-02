// 3568

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        queue<vector<int>> q;
        int n=classroom.size();
        int m=classroom[0].size();
        vector<vector<int>> litter(n, vector<int>(m,-1));
        int count=0;
        int start_x=-1;
        int start_y=-1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (classroom[i][j]=='L') {
                    litter[i][j]=count;
                    count++;
                }
                else if (classroom[i][j]=='S'){
                    start_x=i;
                    start_y=j;
                }
            }
        }
        int fullmask=(1<<count)-1;
        vector<vector<vector<int>>> v(n, vector<vector<int>>(m, vector<int>(1<<count, -1)));
        q.push({start_x, start_y, 0, energy, 0});
        v[start_x][start_y][0]=0;
        vector<vector<int>> dir={{-1, 0}, {1,0}, {0, 1},{0,-1}};
        while (q.empty()!=true){
            int x=q.front()[0];
            int y=q.front()[1];
            int mask=q.front()[2];
            int curr=q.front()[3];
            int steps=q.front()[4];
            q.pop();
            if (mask==fullmask) return steps;
            if (curr==0) continue;
            for (int i=0; i<4; i++){
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];
                if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
                if (classroom[nx][ny]=='X') continue;
                int ne=curr-1;
                int nm=mask;
                if (classroom[nx][ny]=='L'){
                    int id=litter[nx][ny];
                    nm |=(1<<id);
                }
                if (classroom[nx][ny]=='R'){
                    ne=energy;
                }
                if (ne<=v[nx][ny][nm]) continue;
                v[nx][ny][nm]=ne;
                q.push({nx, ny, nm, ne, steps+1});
            }
        }
        return -1;
    }
};