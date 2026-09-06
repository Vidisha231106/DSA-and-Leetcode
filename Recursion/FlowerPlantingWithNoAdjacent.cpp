// 1042 

//Time complexity: O(4^n) where n is the number of gardens.

class Solution {
public:
    bool recursion(unordered_map<int, vector<int>>& mp, int n, int curr, vector<int>& assigned){
        if (curr==n+1) return true;
        if (assigned[curr]!=0) return recursion(mp, n, curr+1, assigned);
        for (int i=1; i<=4; i++){
            bool flag=true;
            for (auto it: mp[curr]){
                if (assigned[it]==i){
                    flag=false;
                    break;
                }
            }
            if (flag==true){
                assigned[curr]=i;
                if (recursion(mp, n, curr+1, assigned)==true) return true;
                assigned[curr]=0;
            }
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map <int, vector<int>> mp;
        int x=paths.size();
        for (int i=0; i<x; i++){
            mp[paths[i][0]].push_back(paths[i][1]);
            mp[paths[i][1]].push_back(paths[i][0]);
        }
        vector<int> colours_assigned(n+1, 0);
        recursion(mp, n, 1, colours_assigned);
        colours_assigned.erase(colours_assigned.begin());
        return colours_assigned;
    }
};

//Better code: O(n) time complexity and O(n) space complexity

