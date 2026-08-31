// 1383

class Solution {
public:
    const int MOD=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> v;
        for (int i=0; i<n; i++){
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.rbegin(), v.rend());
        priority_queue<int, vector<int>, greater<>> pq;
        long long speed_sum=0;
        long long ans=INT_MIN;
        for(int i=0; i<n; i++){
            pq.push(v[i][1]);
            speed_sum+=v[i][1];
            if (pq.size()>k){
                speed_sum-=pq.top();
                pq.pop();
            }
            long long x = (v[i][0]*speed_sum);
            ans=(max(ans, x));
        }
        return ans%MOD;
    }
};