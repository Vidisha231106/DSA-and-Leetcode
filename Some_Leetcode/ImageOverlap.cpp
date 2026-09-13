// 835

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>> i1;
        vector<pair<int,int>> i2;

        for(int r1=0; r1<n; r1++){
            for (int c1=0; c1<n; c1++){
                if (img1[r1][c1]==1) i1.push_back({r1,c1});
            }
        }
        for(int r2=0; r2<n; r2++){
            for(int c2=0; c2<n; c2++){
                if (img2[r2][c2]==1) i2.push_back({r2,c2});
            }
        }
        int x=i1.size();
        int y=i2.size();
        int max_count=0;
        vector<vector<int>> counts(2*n, vector<int> (2*n,0));
        for(int j=0; j<x; j++){
            for(int k=0; k<y; k++){
                int dx=i1[j].first-i2[k].first+n;
                int dy=i1[j].second-i2[k].second+n;
                counts[dx][dy]++;
                
            }
        }
        for(int r1=0; r1<2*n; r1++){
            for (int c1=0; c1<2*n; c1++){
                max_count=max(max_count, counts[r1][c1]);
            }
        }
        return max_count;
    }
};