// 79

class Solution {
public:
    bool recursion(vector<vector<char>>& board, string word, int index, int row, int col, vector<vector<char>> &visited){
        if (index>=word.size()) return true;
        if (row<0 || row>=board.size() || col<0 || col>=board[0].size()){
            return false;
        }
        if (visited[row][col]=='.') return false;
        
        visited[row][col]='.';
        bool up=false, down=false, left=false, right=false;
        if (board[row][col]==word[index]){
            up=recursion(board, word, index+1, row-1, col, visited);
            down=recursion(board, word, index+1, row+1, col, visited);
            left=recursion(board, word, index+1, row, col-1, visited);
            right=recursion(board, word, index+1, row, col+1, visited);
        }
        visited[row][col]='#';
        return (up || down || right || left);
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        bool answer=false;
        int m=board[0].size();

        vector<vector<char>> visited(n, vector<char>(m , '#'));
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (word[0]==board[i][j]){
                    answer=(answer || recursion(board, word, 0, i, j, visited));
                }
            }
        }
        return answer;
    }
};