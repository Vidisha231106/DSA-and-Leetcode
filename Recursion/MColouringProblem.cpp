// Strivers Sheet

class Solution{
public:
    bool recursion(unordered_map<int, set<int>>& mp, int index, int n, vector<int>  colours_assigned){
        if (index==n) return true;
        if (colours_assigned[index]!=0) return recursion(mp, index+1, n, colours_assigned); 
        for (int i=1; i<=m; i++){
            bool flag=true;

            for (auto it: mp[index]){
                if (colours_assigned[it]==i) {
                    flag=false;
                    break;
                }
            }
            if (flag==true){
                colours_assigned[index]=i;
                if (recursion(mp, index+1, n, colours_assigned)==true) return true;
                colours_assigned[index]=0;
            }
        }
        return false;
    }
    bool graphColoring(vector<vector<int> >& edges, int m, int n) {
    	//your code goes here
        vector<int> colours_assigned(n, 0); // 0->no colour is assigned
        int x=edges.size();
        unordered_map<int, set<int>> mp;
        for (int i=0; i<x; i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        return recursion(mp, 0, n, colours_assigned);
    }
};