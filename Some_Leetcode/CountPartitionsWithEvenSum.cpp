// 3432
//Easy

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector <int> answer;
        int n = nums.size();
        int count=0;
        int sum=0;
        for (int i=0; i<n; i++){
            sum+=nums[i];
        }
        if (sum%2!=0 || sum==0) return false;
        int sum_till_there=0;
        for (int i=0; i<n; i++){
            if (sum_till_there%2==0 && (sum-sum_till_there)%2==0){
                count++;
            }
            else if (sum_till_there%2!=0 && (sum-sum_till_there)%2!=0){
                count++;
            }
            sum_till_there+=nums[i];
        }
        return count-1;
    }
};