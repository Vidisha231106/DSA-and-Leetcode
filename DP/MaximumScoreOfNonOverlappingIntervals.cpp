// 3414

struct Node{
    long long m; // max value
    vector <int> indices; // indices till now
};
class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int left=0;
        int right=0;
        for(int i=0; i<n; i++){
            intervals[i].push_back(i);
            swap (intervals[i][0], intervals[i][1]);
        }
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<n; i++){
            swap (intervals[i][0], intervals[i][1]);
        }
        vector<vector<Node>> dp(n+1, vector<Node> (5));
        for(int r=1; r<5; r++){
            for(int i=0; i<n; i++){
                int left=0;
                int right=i-1;
                int prev=-1;
                while (left<=right){
                    int mid=(left+right)/2;
                    // mid represents the prev interval 
                    if (intervals[mid][1]< intervals[i][0]) {
                        prev=mid;
                        left=mid+1;
                    } 
                    else right=mid-1;
                }
                //dp[i+1][r].m=max(dp[i][r].m, intervals[i][2]+dp[prev+1][r-1].m);
                Node take=dp[prev+1][r-1];
                take.m=dp[prev+1][r-1].m+intervals[i][2];
                take.indices.push_back(intervals[i][3]);
                sort(take.indices.begin(), take.indices.end());

                if (dp[i][r].m>take.m) {
                    dp[i+1][r]=dp[i][r];
                }
                else if (dp[i][r].m<take.m) {
                    dp[i+1][r]=take;
                }
                else{
                    if (dp[i][r].indices<take.indices){
                        dp[i+1][r]=dp[i][r];
                        
                    }
                    else dp[i+1][r]=take;
                }
            }
        }
        Node ans=dp[n][0];
        for(int i=0; i<5; i++){
            if (dp[n][i].m>ans.m){
                ans=dp[n][i];
            }
            else if (dp[n][i].m==ans.m && dp[n][i].indices<ans.indices){
                ans=dp[n][i];
            }
        }
        return ans.indices;
    }
};