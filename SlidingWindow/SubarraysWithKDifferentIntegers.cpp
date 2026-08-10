// 992

class Solution {
public:
    //IMP: exactly(k) = atMost(k) - atMost(k-1)
    int fn(vector<int> &nums, int k){
        int n=nums.size();
        int count=0;
        unordered_map <int, int> freq;
        for (int i=0; i<n; i++) freq[nums[i]]=0;
        int i=0, j=0;
        while (j<n){
            if (freq[nums[j]]==0) k--;
            freq[nums[j]]++;

            while (k<0){
                freq[nums[i]]--;
                if (freq[nums[i]]==0) k++;
                i++; 
            }
            count+=(j-i+1);            
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fn(nums, k)-fn(nums, k-1);
    }
};