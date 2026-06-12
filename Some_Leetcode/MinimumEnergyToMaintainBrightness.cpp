// 3951

class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long count=0;
        long long pos=0;
        for (int i=1; pos<brightness; i+=3){
            pos+=3;
            count++;
        }
        int x=intervals.size();

        sort(intervals.begin(), intervals.end());
        long long prev_start=intervals[0][0];
        long long prev_end=intervals[0][1];
        long long total=0;
        for (int i=1; i<x; i++){
            if (intervals[i][0]<=prev_end) {
                prev_end=max(prev_end, (long long)intervals[i][1]);
                continue;
            }
            total+=prev_end-prev_start+1;
            prev_start=intervals[i][0];
            prev_end=intervals[i][1];
        }
        total+=prev_end-prev_start+1;
        return total*count;
    }
};