//403 

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map <int, set<int>> mp;
        for (int i=0; i<n; i++){
            mp[stones[i]]={};
        }
        mp[stones[0]]={0};
        for (int i=0; i<n; i++){
            for (auto k: mp[stones[i]]){
                for (int j=k-1; j<=k+1; j++){
                    if (j>0 && mp.count(stones[i]+j)>0) {
                        mp[stones[i]+j].insert(j);
                    }
                }
            }
        }
        if (mp[stones[n-1]].empty()==true) return false;
        return true;
    }
};