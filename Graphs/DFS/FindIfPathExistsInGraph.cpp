//1971

class Solution {
public:
    bool recursion(int n,vector<vector<int>>& matrix, int s, int d, int curr, vector<int>& visited){
        if (curr==d){
            return true;
        } 
        visited[curr]=1;
        for (int j=0; j<matrix[curr].size(); j++){
            if (visited[matrix[curr][j]]==0) {
                bool ans =recursion(n, matrix, s,d,matrix[curr][j], visited);
                if (ans==true) return ans;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source==destination) return true;
        int e=edges.size();
        vector<vector<int>> matrix(n);
        for (int i=0; i<e; i++){
            matrix[edges[i][0]].push_back(edges[i][1]);
            matrix[edges[i][1]].push_back(edges[i][0]);
        }
        vector <int> visited(n);
        return recursion(n, matrix,source, destination, source, visited);
    }
};