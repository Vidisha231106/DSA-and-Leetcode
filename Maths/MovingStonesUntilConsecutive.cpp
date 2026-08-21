// 1033

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        // * _ * _ *
        // x   y   z
        
        // * _ _ _ _ * _ *
        // x k k k k y k z

        // * * *
        // * * _ _ _ *
        // 0 1 2 3 4 5
        // * _ _ _ * *
        vector<int> v={a,b,c};
        sort(v.begin(), v.end());
        if (v[2]-v[1]==1 && v[1]-v[0]==1) return {0,0};
        int max_num=(v[2]-1-v[0]-1);
        int min_num=2;
        if (v[2]-v[1]==1 || v[1]-v[0]==1 || v[2]-v[1]==2 || v[1]-v[0]==2) min_num=1;
        return{min_num, max_num};
    }
};