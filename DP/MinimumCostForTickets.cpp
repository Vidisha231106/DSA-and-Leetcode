// 983

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=*max_element(days.begin(), days.end());
        vector <int> dp(n+1,0);
        unordered_set<int> s(days.begin(), days.end());
        //dp[i]=min cost to be paid till ith day
        for (int i=1; i<=n; i++){
            if (s.find(i)==s.end())dp[i]=dp[i-1];
            else{
                int one=(i-1>=0)? dp[i-1]:dp[0];
                int seven=(i-7>=0)? dp[i-7]:dp[0];
                int thirty=(i-30>=0)? dp[i-30]:dp[0];
                dp[i]=min({costs[0]+one ,costs[1]+seven, costs[2]+thirty});
            }
        }
        return dp[n];
    }
};