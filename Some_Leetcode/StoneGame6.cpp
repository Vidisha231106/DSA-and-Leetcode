// 1686

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        //IMPORTANT: Greedily choose the stone with the maximum aliceValues[i] + bobValues[i].
        int n=aliceValues.size();
        priority_queue<vector<int>> sums;
        for (int i=0; i<n; i++) {
            sums.push({aliceValues[i]+bobValues[i], i}); 
        }       
        int chance=0;
        int alice=0;
        int bob=0;
        while (sums.empty()!=true){
            vector<int> curr=sums.top();
            cout<<curr[0]<<" "<<curr[1]<<endl;
            sums.pop();
            if (chance==0){
                alice+=aliceValues[curr[1]];
            }
            else{
                bob+=bobValues[curr[1]];
            }
            chance=(chance==0) ? 1: 0;
        }
        cout<<alice<<" "<<bob<<endl;
        if (alice==bob) return 0;
        if (alice>bob) return 1;
        return -1;
    }
};