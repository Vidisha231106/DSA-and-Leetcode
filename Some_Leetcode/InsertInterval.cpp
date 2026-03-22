// 57

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int index=0;
        int n = intervals.size();
        while (index<n && intervals[index][1]<newInterval[0]){
            answer.push_back(intervals[index]);
            index++;
        }
        while (index<n && intervals[index][0]<=newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1]=max(newInterval[1], intervals[index][1]);
            index++;
        }
        answer.push_back(newInterval);
        while (index<n){
            answer.push_back(intervals[index]);
            index++;
        }
        return answer;
    }
};