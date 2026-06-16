// 3961

class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m=units.size();
        int n=units[0].size();
        int min_num=INT_MAX;
        for (int i=0; i<m; i++){
            sort(units[i].begin(), units[i].end());
            min_num=min(min_num, units[i][0]);
        }
        long long answer=0;
        // we need to choose n total units
        if (n>1){
            sort(units.begin(), units.end(), [](vector<int>& a, vector<int>& b){
                return (a[1]==b[1])? a[0]<b[0]: a[1]<b[1];
            });
            
        }
        else{
            sort(units.begin(), units.end());
        }
        answer+=min_num;
        cout<<answer;
        int x=(n>1)?1:0;
        for (int i=1; i<m; i++){
            answer+=units[i][x];
        }
        return answer;
    }
};