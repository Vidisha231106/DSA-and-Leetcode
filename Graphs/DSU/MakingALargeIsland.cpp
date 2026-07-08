// 827

class DSU {
public:
    vector <int> parent, island_size;
    DSU (int n){
        parent.resize(n+1);
        island_size.resize(n+1);
        for (int i=0; i<n; i++){
            parent[i]=i;
            island_size[i]=1;
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
        if (island_size[ulp_x]<island_size[ulp_y]){
            parent[ulp_x]=ulp_y;
            island_size[ulp_y]+=island_size[ulp_x];
        }
        else{
            parent[ulp_y]=ulp_x;
            island_size[ulp_x]+=island_size[ulp_y];
        }
    }
};
class Solution {
public:
    bool isValid(int n, int r, int c){
        return (r<=n-1 && r>=0 && c>=0 && c<=n-1);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DSU dsu(n*n);
        vector<pair<int, int>> dir {{-1,0}, {1, 0}, {0, -1}, {0,1 }};
        // first build the islands
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]==0) continue;
                int cell_no=i*n+j;
                for (int k=0; k<4; k++){
                    int r=i+dir[k].first;
                    int c=j+dir[k].second;
                    if (isValid(n, r,c)==true && grid[r][c]==1){
                        int adj_cell=r*n+c;
                        dsu.unite(cell_no, adj_cell);
                    }
                }
            }
        }
        int answer=INT_MIN;

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]==1) continue;
                int cell_no=i*n+j;
                set <int> components;
                for (int k=0; k<4; k++){
                    int r=i+dir[k].first;
                    int c=j+dir[k].second;
                    if (isValid(n, r,c)==true && grid[r][c]==1){
                        int adj_cell=r*n+c;
                        components.insert(dsu.find(adj_cell));
                    }
                }
                int total=0;
                for (auto it:components){
                    total+=dsu.island_size[it];
                    
                }
                answer=max(answer,total+1);
            }
        }
        for (int i=0; i<n*n; i++){
            answer=max(answer, dsu.island_size[dsu.find(i)]);
        }
        return answer;
    }
};