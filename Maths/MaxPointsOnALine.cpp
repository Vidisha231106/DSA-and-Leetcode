// 149

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int m=INT_MIN;
        for(int i=0; i<n; i++){
            unordered_map<double, int> mp; // slope: count
            for(int j=0; j<n; j++){
                if (i==j) continue;
                double slope=1;
                if ((points[j][0]-points[i][0])==0) slope=INT_MAX; // let 90 deg be 2 in rep
                else slope=(double)(points[j][1]-points[i][1])/(points[j][0]-points[i][0]);
                mp[slope]++;
            }
            for(auto x: mp){
                m=max(m, x.second+1);
            }
        }
        if (m==INT_MIN) return 1;
        return m;
    }
};