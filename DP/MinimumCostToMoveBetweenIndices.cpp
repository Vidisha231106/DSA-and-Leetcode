//3919

class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> closest; 
        closest.push_back(1); 
        for (int i=1; i<n-1; i++){ 
            if (abs(nums[i]-nums[i-1])<=abs(nums[i]-nums[i+1])) closest.push_back(i-1); 
            else closest.push_back(i+1); 
        } 
        closest.push_back(n-2);

        vector<long long > forwardDP(n,0);
        forwardDP[0] = 0;
        vector<long long> backwardDP(n, 0);
        backwardDP[n-1] = 0;
        for (int i=1; i<n; i++){
            if (closest[i-1]==i) forwardDP[i] = min(forwardDP[i-1] + 1, forwardDP[i-1] + nums[i]-nums[i-1]);
            else forwardDP[i]=forwardDP[i-1] + nums[i]-nums[i-1];
        }
        for (int i=n-2; i>=0; i--){
            if (closest[i+1]==i) backwardDP[i] = min(backwardDP[i+1] + 1, backwardDP[i+1] + nums[i+1]-nums[i]);
            else backwardDP[i]=backwardDP[i+1] + nums[i+1]-nums[i];
        }
        
        int q = queries.size();
        vector<int> answer(q);
        for (int i=0; i<q; i++){
            if (queries[i][0]<queries[i][1]) {
                answer[i]=forwardDP[queries[i][1]] - forwardDP[queries[i][0]] ;
            }
            else {
                answer[i]=backwardDP[queries[i][1]] - backwardDP[queries[i][0]] ;
            }
        }
        return answer;
    }
};
