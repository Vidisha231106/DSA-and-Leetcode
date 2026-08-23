//

// TLE - O(n^2) solution

class Solution {
public:
    unordered_map<int,pair<int,int>> mp; // curr_index: min_index, max_index till which diff is valid
    vector<int> visited;
    bool dfs(int num, int to_find){
        if (num==to_find) return true;
        if (mp.contains(num)==false) return false;
        if (visited[num]==1) return false;
        visited[num]=1;
        if(mp[num].first<=to_find && mp[num].second>=to_find) return true;
        for(int i=mp[num].first; i<=mp[num].second; i++){
            if (dfs(i, to_find)) return true;
        }
        return false;
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> answer;
        visited.resize(n,0);
        for(int i=0; i<n; i++){
            int l=i; 
            int r=n-1;
            while (l<=r){
                int mid=(l+r)/2;
                if (abs(nums[mid]-nums[i])>maxDiff){
                    r=mid-1;
                }
                else if (abs(nums[mid]-nums[i])<=maxDiff){
                    mp[i].second=mid;
                    l=mid+1;
                }
            }
            l=0; 
            r=i;
            while (l<=r){
                int mid=(l+r)/2;
                if (abs(nums[mid]-nums[i])>maxDiff){
                    l=mid+1;

                }
                else if (abs(nums[mid]-nums[i])<=maxDiff){
                    mp[i].first=mid;
                    r=mid-1;                    
                }

            }
        }
        for(auto t: mp){
            cout<<t.first<<" : "<<t.second.first<<" to "<<t.second.second<<endl;
        }
        int x=queries.size();
        for(int i=0;i<x;i++){
            visited.assign(n, 0);
            if (dfs(queries[i][0], queries[i][1])) answer.push_back(true);
            else answer.push_back(false);
        }
        return answer;
    }
};

// O(n logn+ qa(n)) solution

class DSU {
public:    
    vector<int> parent; vector<int> size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++) {
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
        int upx=find(x);
        int upy=find(y);
        if (upx==upy) return;
        if (size[upx]<size[upy]) {
            parent[upx]=upy;
            size[upy]+=size[upx];
        }
        else{
            parent[upy]=upx; 
            size[upx]+=size[upy];
        } 
    }
};
class Solution {
public:
    unordered_map<int,pair<int,int>> mp;
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> answer;
        //visited.resize(n,0);
        DSU dsu(n);
        for(int i=0; i<n; i++){
            int l=i; 
            int r=n-1;
            while (l<=r){
                int mid=(l+r)/2;
                if (abs(nums[mid]-nums[i])>maxDiff){
                    r=mid-1;
                }
                else if (abs(nums[mid]-nums[i])<=maxDiff){
                    dsu.unite(mid, i);
                    mp[i].second=mid;
                    l=mid+1;
                }
            }
            l=0; 
            r=i;
            while (l<=r){
                int mid=(l+r)/2;
                if (abs(nums[mid]-nums[i])>maxDiff){
                    l=mid+1;

                }
                else if (abs(nums[mid]-nums[i])<=maxDiff){
                    mp[i].first=mid;
                    dsu.unite(mid, i);
                    r=mid-1;                    
                }
            }
        }
        // for(auto t: mp){
        //     cout<<t.first<<" : "<<t.second.first<<" to "<<t.second.second<<endl;
        // }
        int x=queries.size();
        for(int i=0;i<x;i++){
            if (dsu.find(queries[i][0])==dsu.find(queries[i][1])) answer.push_back(true);
            else answer.push_back(false);
        }
        return answer;        
    }
};