// 947

class DSU {
public:
    unordered_map <int,int> parent;
    int find(int x){
        if (parent.find(x)==parent.end()){
            parent[x]=x;
        }
        if (x!=parent[x]){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y){
        parent[find(x)]=find(y);
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu;
        int n=stones.size();
        for (int i=0; i<n; i++){
            dsu.unite(stones[i][0], stones[i][1]+10001);
        }
        unordered_set <int> components;
        for (int i=0; i<n; i++){
            components.insert(dsu.find(stones[i][0]));
        }
        return stones.size()-components.size();
    }
};