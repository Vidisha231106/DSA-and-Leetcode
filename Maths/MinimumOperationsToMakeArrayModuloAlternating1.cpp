// 3937

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n= nums.size();
        int answer=INT_MAX;
        for (int x=0; x<k; x++){
            for (int y=0; y<k; y++){
                int cost=0;
                if (x==y) continue;
                for (int i=0; i<n; i++){
                    int target=(i%2==0)? x:y;
                    int rem=nums[i]%k;
                    cost+=min(abs(rem-target), (k-abs(rem-target)));
                }
                answer=min(answer,cost);
            }
        }
        return answer;
    }
};