//3635

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int l=landStartTime.size();
        int w=waterStartTime.size();
        int land_ended=INT_MAX;
        int water_ended=INT_MAX;
        int answer=INT_MAX;
        // land + water
        for (int i=0; i<l; i++){
            land_ended=min(land_ended, landStartTime[i]+landDuration[i]);
        }
        for (int j=0; j<w; j++){
            water_ended=min(water_ended, max(land_ended, waterStartTime[j])+waterDuration[j]);
        }
        answer=min(answer, water_ended);

        // water + land
        land_ended=INT_MAX;
        water_ended=INT_MAX;
        for (int i=0; i<w; i++){
            water_ended=min(water_ended, waterStartTime[i]+waterDuration[i]);
        }
        for (int j=0; j<l; j++){
            land_ended=min(land_ended, max(water_ended, landStartTime[j])+landDuration[j]);
        }
        answer=min(answer, land_ended);
        return answer;
    }
};