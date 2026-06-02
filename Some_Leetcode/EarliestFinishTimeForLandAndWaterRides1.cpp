// 3633

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int l=landStartTime.size();
        int w=waterStartTime.size();
        int ans=INT_MAX;
        int water=INT_MAX;
        int land=INT_MAX;
        for (int i=0; i<l; i++){
            //land first
            land=(landStartTime[i]+landDuration[i]);
            water=INT_MAX;
            for (int j=0; j<w; j++){
                //water next
                if (waterStartTime[j]>=landStartTime[i] && waterStartTime[j]<=land){ // overlap
                    water=min(water, land+waterDuration[j]);
                }
                else if (landStartTime[i]<=waterStartTime[j]){ // no overlap
                    water=min(water, waterStartTime[j]+waterDuration[j]);
                }
            }
            ans=min(ans, water);
        }
        for (int j=0; j<w; j++){
            //water first
            water=(waterStartTime[j]+waterDuration[j]);
            land=INT_MAX;
                for (int i=0; i<l; i++){
                //land next
                if (landStartTime[i]>=waterStartTime[j] && landStartTime[i]<=water){ // overlap
                    land=min(land, water+landDuration[i]);
                }
                else if (landStartTime[i]>=waterStartTime[j]){ // no overlap
                    land=min(land, landStartTime[i]+landDuration[i]);
                }
            }
            ans=min(ans, land);
        }
        return ans;
    }
};