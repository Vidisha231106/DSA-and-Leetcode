// 277

class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int n=M.size();
        int top=0;
        int bottom=n-1;
        while (top<bottom){
            if (top==bottom) return top;
            if (M[top][bottom]==1) top++;
            else if (M[bottom][top]==1) bottom--;
            else {
                top++;
                bottom--;
            }
        }
        if (top>bottom) return -1;
        for (int i=0; i<n; i++){
            if (i==top) continue;
            if (M[top][i]==1 || M[i][top]==0) return -1;
        }
        return top;
    }
};
