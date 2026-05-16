//3732

// Really Good Logic

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long M1 = INT_MIN;
        long long M2 = INT_MIN;
        for(auto &y:nums)
        {
            long long x = abs(y);
            if(x > M1)
            {
                M2 = M1;
                M1 = x;
            }
            else if(x == M1) M2 = x;
            else M2 = max(M2,x);
        }
        return M1 * M2 * 1e5;
    }
};
// 0 1 2
// -2 -1 0

// -1 0 1 2 3


//My Solution:

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n =nums.size();
        long long answer=LLONG_MIN;
        sort(nums.begin(), nums.end());
        answer=max(answer, (long long)(pow(10, 5)*nums[n-1]*nums[n-2]));
        answer=max(answer, (long long)(pow(10, 5)*nums[1]*nums[0]));
        answer=max(answer, (long long)(pow(10, 5)*nums[0]*nums[n-1]*-1));
        answer=max(answer, (long long)(pow(10, 5)*nums[n-1]*nums[n-2]*-1));
        return answer;
    }
};

//My Wrong solution: 

class Solution {
public:
    long long dp_fn(vector<vector<long long>>& dp, vector<int>&nums, int i, int already){
        if (already==0) return 1;
        if (i<0) return LLONG_MIN;
        if (dp[i][already]!=-1) return (long long) dp[i][already];
        
        long long dont_take=dp_fn(dp, nums, i-1, already);
        long long take=LLONG_MIN;
        if (already>0){
            long long temp = dp_fn(dp, nums, i-1, already-1);
            if (temp!=LLONG_MIN) take=(long long )nums[i]* (long long )temp;
        } 
        return dp[i][already]=max(take, dont_take);
    }
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        int neg=0;
        int zeros=0;
        int zero_index=0;
        long long smallest_pos_element=INT_MAX;
        long long smallest_neg_element=INT_MIN;
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; i++){
            if (nums[i]<0) {
                neg++;
                smallest_neg_element=max((long long) smallest_neg_element, (long long) nums[i]);
            }
            else if (nums[i]==0) {
                zeros++;
                zero_index=i;
            }
            else if (nums[i]>0) {
                smallest_pos_element=min((long long) smallest_pos_element, (long long) nums[i]);
            }
        }
        cout<< "zeros: "<< zeros << " neg: "<< neg<<endl;
        if (zeros>1) return 0;
        if (zeros==1 && neg%2!=0){
            nums[zero_index]=pow(10,5);
            nums[zero_index]*=-1;
        }
        else if (zeros==1 && neg%2==0){
            nums[zero_index]=pow(10,5);
        }
        else if (neg%2!=0){
            for(int i=0; i<n; i++){
                if (nums[i]==smallest_neg_element){
                    nums[i]=pow(10, 5);
                    break;
                }
            }
        }
        else if (neg%2==0){
            for(int i=0; i<n; i++){
                if (nums[i]==smallest_pos_element){
                    nums[i]=pow(10, 5);
                    break;
                }else if(smallest_pos_element==INT_MAX && nums[i]==smallest_neg_element){
                    nums[i]=pow(10, 5);
                    break;
                }
                
            }
        }
        vector<vector<long long>>dp(n+1, vector<long long> (4, -1));
        return dp_fn(dp, nums, n-1, 3);
    }
};©leetcode