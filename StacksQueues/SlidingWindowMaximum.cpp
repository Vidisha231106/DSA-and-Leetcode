// 239

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int i=0; 
        vector<int> answer;
        int n=nums.size();
        while (i<n){
            while (dq.empty()!=true && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            while (dq.front()<=i-k) {
                dq.pop_front();
            }
            if (i>=k-1) answer.push_back(nums[dq.front()]);
            i++;
        }
        return answer;
    }
};