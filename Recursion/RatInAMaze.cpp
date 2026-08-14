// Strivers Sheet

class Solution{
    public:
    vector<string> answer;
    void recursion(vector<vector<int>> &grid, int i, int j, string curr){
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return;
        if (grid[i][j]==0 || grid[i][j]==2) return;
        if (i==grid.size()-1 && j==grid[0].size()-1){
            answer.push_back(curr);
            return;
        }
        
        grid[i][j]=2;
        recursion(grid, i+1, j, curr+'D');
        recursion(grid, i, j+1, curr+'R');
        recursion(grid, i-1, j, curr+'U');
        recursion(grid, i, j-1, curr+'L'); 
        grid[i][j]=1;       
    }
    vector<string> findPath(vector<vector<int> > &grid) {
        //your code goes here
        recursion(grid, 0, 0, "");
        return answer;
    }
};