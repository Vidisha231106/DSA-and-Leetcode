// 37

class Solution {
public:
    bool check(vector<vector<char>> &board, int row, int col, char c){
        for (int i=0; i<9; i++){
            if (board[row][i]==c) return false;
            if (board[i][col]==c) return false;
        }
        int box_row=3*(row/3);
        int box_col=3*(col/3);
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                if (board[box_row+i][box_col+j]==c) return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        vector<char> cs={'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for (int i=0; i<9; i++){// traverses thru the columns
            for (int j=0; j<9; j++){
                if (board[i][j]=='.'){
                    for (char c: cs){
                        if (check(board, i, j, c)){
                            board[i][j]=c;
                            if (solve(board)==true) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};