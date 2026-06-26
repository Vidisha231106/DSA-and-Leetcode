//

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mins=0;
        queue <vector<int>> q;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j]==2) q.push({i, j, 0});
            }
        }
        while (q.empty()!=true){
            int curr_x=q.front()[0];
            int curr_y=q.front()[1];
            int curr_min=q.front()[2];
            q.pop();
            if (curr_x < 0 || curr_x >= n || curr_y < 0 || curr_y >= m)
                continue;
            if (grid[curr_x][curr_y]==2 && curr_min!=0){
                continue;
            } 
            if (grid[curr_x][curr_y]==0) {
                continue;
            }
                grid[curr_x][curr_y]=2;
                q.push({curr_x-1, curr_y, curr_min+1});
                q.push({curr_x+1, curr_y, curr_min+1});
                q.push({curr_x, curr_y-1, curr_min+1});
                q.push({curr_x, curr_y+1, curr_min+1});
            mins=max(mins, curr_min);

        }
            for (int i=0; i<n; i++){
                for (int j=0; j<m; j++) {
                    if (grid[i][j]==1) return -1;
                }
            }
        return mins; 
    }
};


// Better Approach:

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mins = 0;
        queue<vector<int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j, 0});
            }
        }

        while (!q.empty()) {
            int curr_x = q.front()[0];
            int curr_y = q.front()[1];
            int curr_min = q.front()[2];
            q.pop();

            // Direction arrays
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            for (int k = 0; k < 4; k++) {
                int nx = curr_x + dx[k];
                int ny = curr_y + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    grid[nx][ny] == 1) {

                    grid[nx][ny] = 2;
                    q.push({nx, ny, curr_min + 1});
                    mins = max(mins, curr_min + 1);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return mins;
    }
};