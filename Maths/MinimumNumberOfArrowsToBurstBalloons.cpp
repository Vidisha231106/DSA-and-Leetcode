// 452

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(), points.end());
        int left=points[0][0];
        int right=points[0][1];
        int ar=0;
        for(int i=1; i<n; i++){
            if (points[i][0]<=right){
                left=max(left, points[i][0]);
                right=min(right, points[i][1]);
            }
            else{
                ar++;
                left=points[i][0];
                right=points[i][1];
            }
        }
        return ar+1;
    }
};