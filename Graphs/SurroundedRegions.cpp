// 130

class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board){
        if (r<0 || c<0 || r>=board.size() || c>=board[0].size()) return;
        if (board[r][c]=='X' || board[r][c]=='.') return;
        board[r][c]='.';
        dfs(r-1, c, board);
        dfs(r+1, c, board);
        dfs(r, c-1, board);
        dfs(r, c+1, board);
    }
    void solve(vector<vector<char>>& board) {
        int n =board.size();
        int m=board[0].size();
        //traverse the edges, mark all the connectd boxoes of 'O' with -1;
        // top edge
        for (int i=0; i<m; i++){
            if (board[0][i]=='O'){
                dfs(0, i, board);
            }
        }
        //bottom edge
        for (int i=0; i<m; i++){
            if (board[n-1][i]=='O'){
                dfs(n-1, i, board);
            }
        }
        //left edge
        for (int i=0; i<n; i++){
            if (board[i][0]=='O'){
                dfs(i, 0, board);
            }
        }
        //right edge
        for (int i=0; i<n; i++){
            if (board[i][m-1]=='O'){
                dfs(i, m-1, board);
            }
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (board[i][j]=='X' || board[i][j]=='O') board[i][j]='X';
                else if (board[i][j]=='.') board[i][j]='O'; 
            }
        }
    }
};