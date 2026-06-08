// 646

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        for (int i=0; i<n; i++){
            swap(pairs[i][0], pairs[i][1]);
        }
        sort(pairs.begin(), pairs.end());
        for (int i=0; i<n; i++){
            swap(pairs[i][0], pairs[i][1]);
        }
        int end=pairs[0][1];
        int count=1;
        for (int i=1; i<n; i++){
            if (end>=pairs[i][0]) continue;
            end=pairs[i][1];
            count++;
            
        }
        return count;
    }
};