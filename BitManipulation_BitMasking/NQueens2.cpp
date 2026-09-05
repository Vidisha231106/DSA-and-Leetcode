// 52

// Requires conversion to bitmasking: 

class Solution {
public:
    bool check(int row,int col,vector<vector<int>> positions){
        int x=positions.size();
        for(int i=0; i<x; i++){
            if (abs(positions[i][0]-row)==abs(positions[i][1]-col)) return false;
        }
        return true;
    }
    int count=0;
    void recursion(unordered_set <int>& used_cols, int row, int n, vector<vector<int>> positions){
        if (row>=n) {
            for(int i:used_cols) cout<<i<<" ";
            cout<<endl;
            count++;
            return;
        }
        for(int i=0; i<n; i++){
            if (used_cols.contains(i)==false && check(row, i, positions)){
                used_cols.insert(i);
                positions.push_back({row, i});
                recursion(used_cols, row+1, n, positions);
                used_cols.erase(i);
                positions.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        unordered_set <int> used_cols;
        vector<vector<int>> positions;
        recursion(used_cols, 0, n, positions);
        return count;
    }
};