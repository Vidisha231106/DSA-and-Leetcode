// 4008

class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int m=monsters.size();
        vector<long long> prev_damage(m);
        prev_damage[0]=0;
        for (int i=1; i<m; i++){
            prev_damage[i]=monsters[i-1]+prev_damage[i-1];
        }
        int b=boosts.size();
        vector<long long> diff_array(m+1);
        for (int i=0; i<b; i++){
            diff_array[boosts[i][0]]+=boosts[i][2];
            diff_array[boosts[i][1]+1]-=boosts[i][2];
        }
        vector<long long> bonus(m);
        bonus[0]=diff_array[0];
        for (int i=1; i<m; i++){
            bonus[i]=diff_array[i]+bonus[i-1];
        }
        long long answer=0;
        for (int i=0; i<m; i++){
            if (monsters[i]-bonus[i]<=0){
                answer=max(answer, (long long)0);
            }
            else{
                answer=max(answer, prev_damage[i]+monsters[i]-bonus[i]);
            }
        }        
        return answer;
    }
};