//53

//INEFFICIENT METHOD - O(n^2)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int max_sum=INT_MIN;
        for (int i=0; i<n; i++){
            int sum=0;
            for (int j=i; j<n; j++){
                sum+=nums[j];
                if (sum>max_sum) max_sum=sum;
            }
            
        }
        return max_sum;
    }
};

//Efficient MEthod - O(n)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int sum=INT_MIN;
        int max_sum=INT_MIN;
        for (int i=0; i<n; i++){
            if (sum<0){
                //start_index=i;
                sum=0;
            }
            sum+=nums[i];
            if (sum>max_sum) max_sum=sum;
        }
        return max_sum;
    }
};