// 4025

class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int m=*max_element(lights.begin(), lights.end());
        int answer=0;

        for (int x:arrivalTime){
            int r=x%period;
            if (r>=m){
                answer=max(answer,(period-r));
            }
        }
        return answer;
    }
};