// 3286

//Better Solution: 0 1 BFS - IMPORTANT

typedef tuple<int, int, int> tiii;

class Solution {
    const int mov[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int row = grid.size(), col = grid[0].size();
        int life[row][col];
        memset(life, -1, sizeof(life));
        life[0][0] = health - grid[0][0];
        deque<tiii> dq;
        dq.push_back({0, 0, life[0][0]});
        while(!dq.empty()) {
            auto [r, c, hp] = dq.front();
            dq.pop_front();
            if (hp < life[r][c])
                continue;
            for (int dir = 0; dir < 4; dir++) {
                int newR = r + mov[dir][0], newC = c + mov[dir][1];
                if (newR >= 0 && newR < row && newC >= 0 && newC < col) {
                    int newHP = hp - grid[newR][newC];
                    if (newHP <= life[newR][newC])
                        continue;
                    life[newR][newC] = newHP;
                    if (newHP == hp) {
                        dq.push_front({newR, newC, newHP});
                    } else {
                        dq.push_back({newR, newC, newHP});
                    }
                }
            }
        }
        return life[row - 1][col - 1] > 0;
    }
};

//My solution

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue <vector<int>> pq; //curr_health, x, y 
        health=(grid[0][0]==1) ? health-1: health; 
        pq.push({health,0,0});
        vector<int> dir={0,-1,1};
        vector<vector<int>> visited(n, vector<int> (m, -1));
        while (pq.empty()!=true){
            int curr=pq.top()[0];
            int x=pq.top()[1];
            int y=pq.top()[2];
            pq.pop();
            if (curr<1) continue; 
            if (curr<=visited[x][y]) continue;
            visited[x][y]=curr;
            if (x==n-1 && y==m-1) return true;
            for (int i=0; i<3; i++){
                if (x+dir[i]<0 || x+dir[i]>n-1) continue;
                for (int j=0; j<3; j++){
                    if (dir[i]==dir[j] || dir[i]==-dir[j]) continue;
                    if (y+dir[j]<0 || y+dir[j]>m-1) continue;
                    pq.push({curr-grid[x+dir[i]][y+dir[j]], x+dir[i], y+dir[j]});
                }
            }
        }
        return false;
    }
};