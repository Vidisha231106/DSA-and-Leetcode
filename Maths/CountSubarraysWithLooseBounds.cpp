// 4089

class Solution {
public:
    map<pair<int, int>, int> mp;
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int left=0;
        int i=0;
        int n=nums.size();
        while (i<n){
            if (nums[i]<minK){
                // int count=i-left;
                // ans+=(pow(2, count)-1);
                left=i+1;
                i++;
                if (left>=n) break;
                continue;
            }
            if (nums[i]>maxK){
                //int count=i-left;
                //ans+=(pow(2, count)-1);
                left=i+1;
                i++;
                if (left>=n) break;
                continue;
            }
            while (i<n && nums[i]<=maxK && nums[i]>=minK){
                i++;
                ans+=(i-left);
            }
        }
        // cout<<left<<i;
        // int count=i-left;
        // // if (count==1) ans++;
        // //if (abs(count)!=1) 
        // ans+=pow(2,count)-1;
        return ans;
    }
};