// 3558

class Solution {
public:
    stack <pair<int, int>> s;
    void countDist(unordered_map <int, vector<int>>& mp, int i, int parent, int height){
        if (mp.contains(i)==false) return;
        int m=mp[i].size();
        for (int j=0; j<m; j++) {
            int child=mp[i][j];
            if (child==parent) continue;
            s.push({mp[i][j], height+1});
            countDist(mp, mp[i][j], i, height+1);
        }
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end());
        int n=edges.size();
        unordered_map <int, vector<int>> mp;
        for (int i=0; i<n; i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        countDist(mp, 1, -1, 0);
        int count=0;
        while (s.empty()!=true){
            pair<int,int> curr=s.top();
            count=max(count, curr.second);
            s.pop();
        }
        long long answer=1;
        for (int i=0; i<count-1; i++){
            answer=(answer*2)%(1000000000 + 7);
        }
        return answer;
    }
};