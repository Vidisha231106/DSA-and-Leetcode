//  435

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i=0; i<n; i++){
            int temp = intervals[i][0];
            intervals[i][0] = intervals[i][1];
            intervals[i][1]= temp;
        }
        sort(intervals.begin(), intervals.end());
        int count=0;
        int prev_ending= intervals[0][0];
        for (int i=1; i<n; i++){
            if (intervals[i][1]<prev_ending){
                count++;
            }
            else {
                prev_ending = intervals[i][0];
            }
        }
        return count;
    }
};