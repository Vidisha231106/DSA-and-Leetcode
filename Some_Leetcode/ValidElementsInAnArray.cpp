class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer;
        answer.push_back(nums[0]);
        if (n==1) return answer;
        for (int i=1; i<n-1; i++){
            int flag=0;
            for (int j=0; j<i; j++){
                if (nums[j]>=nums[i]){
                    flag=1;
                    break;
                }
            }
            if (flag==1){
                for (int j=i+1; j<n; j++){
                    if (nums[j]>=nums[i]){
                        flag=0;
                        break;
                    } 
                }
                if (flag==1) answer.push_back(nums[i]);
            }
            else{
                answer.push_back(nums[i]);
            }
        }
        answer.push_back(nums[n-1]);
        return answer;
    }
};