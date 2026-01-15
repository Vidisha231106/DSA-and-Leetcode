//547

class Solution {
public:
    int count=0;
    void dfs(int num, int n, vector<vector<int>>& isConnected, vector <int>& v){
        v[num]=1;
        for (int i=0; i<n; i++){
            if (isConnected[num][i]==1 && v[i]==0){
                dfs(i,n, isConnected,v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector <int> v(n,0);
        for (int i =0; i<n; i++){
            if (v[i]==0){
            dfs(i, n, isConnected, v);
            count++;
            }
        }
        return count;
    }
};