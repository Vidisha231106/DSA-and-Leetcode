// 1288

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int answer=0;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            if (a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        int n=intervals.size();
        int max_end=0;
        for (int i=0; i<n; i++){ //key
            if (intervals[i][1]>max_end){
                answer++;
                max_end=intervals[i][1];
            }
        }
        return answer;
    }
};