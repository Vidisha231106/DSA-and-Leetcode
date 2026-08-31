// 2542

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> v;
        int n=nums1.size();
        for(int i=0; i<n; i++){
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.rbegin(), v.rend());
        priority_queue<int, vector<int>, greater<>> pq;
        long long answer=INT_MIN;
        long long curr_sum=0;
        for(int i=0; i<n; i++){
            pq.push(v[i][1]);
            curr_sum+=v[i][1];
            if (pq.size()>k){
                curr_sum-=pq.top();
                pq.pop();
            }
            cout<<v[i][0]<<" "<<curr_sum<<endl;
            if (pq.size()==k) answer=max(answer, curr_sum*v[i][0]);
        }
        return answer;
    }
};