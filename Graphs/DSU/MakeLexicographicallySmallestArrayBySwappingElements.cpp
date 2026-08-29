// 2948

class DSU{
public:
    vector<int> parent,size;
    DSU(int n){
        parent.resize(n);
        size.resize(n, 0);
        for(int i=0; i<n; i++){
            parent[i]=i;
            size[i]++;
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
        if (size[ulp_x]>size[ulp_y]){
            parent[ulp_y]=ulp_x;
            size[ulp_x]+=size[ulp_y];
        }
        else{
            parent[ulp_x]=ulp_y;
            size[ulp_y]+=size[ulp_x];
        }
    }
};
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> temp=nums;
        sort(temp.begin(), temp.end());
        int m=temp[n-1];
        int ids=0;
        unordered_map<int,int> index;
        for(int x: temp){
            if (index.contains(x)==false) {
                index[x]=ids;
                ids++;
            }
        }
        DSU dsu(ids);
        for(int i=1; i<n; i++){
            if (abs(temp[i-1]-temp[i])<=limit) dsu.unite(index[temp[i-1]], index[temp[i]]);
        }
        vector<int> answer;
        unordered_map<int, multiset<int>>mp; //IMPORTANT
        for (int i=0; i<n; i++){
            mp[dsu.find(index[temp[i]])].insert(temp[i]);            
        }
        for(int i=0; i<n;i++){
            auto it=mp[dsu.find(index[nums[i]])].begin();
            answer.push_back(*it);
            mp[dsu.find(index[nums[i]])].erase(it);
        }
        return answer;
    }
};