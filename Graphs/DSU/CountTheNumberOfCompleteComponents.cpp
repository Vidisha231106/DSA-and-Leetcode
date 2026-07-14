// 2685

class DSU {
public:
    vector <int> parent, size;
    DSU (int n){
        parent.resize(n+1);
        size.resize(n+1);
        for (int i=0; i<n; i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int find(int x){
        if (x!=parent[x]){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y){
        int ulp_x=find(x);
        int ulp_y=find(y);
        if (ulp_x==ulp_y) return;
        if (size[ulp_x]<size[ulp_y]){
            parent[ulp_x]=ulp_y;
            size[ulp_y]+=size[ulp_x];
        }
        else{
            parent[ulp_y]=ulp_x;
            size[ulp_x]+=size[ulp_y];
        }
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        vector<int> degree(n);
        int x=edges.size();
        for (int i=0; i<x; i++){
            dsu.unite(edges[i][0], edges[i][1]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        unordered_map< int, vector<int>> components;
        for (int i=0; i<n; i++){
            components[dsu.find(i)].push_back(i);
        }
        int count=0;
        for (auto& it: components){
            int flag=1;
            int x=it.second.size();
            for (int i=0; i<x; i++){
                if (degree[it.second[i]]!=x-1){
                    flag=0;
                    break;
                }
            }
            if (flag==1) count++;
        }
        return count;
    }
};