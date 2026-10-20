// 3551

class Solution {
public:
    int sum_of_digits(int num){
        int sum=0;
        while(num>0){
            sum+=(num%10);
            num/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> indices;
        for(int i=0; i<n; i++){
            indices[nums[i]]=i;
        }
        map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            int s=sum_of_digits(nums[i]);
            mp[s].push_back(nums[i]);
        }
        vector<int> v;
        for(auto x: mp){
            sort(x.second.begin(), x.second.end());
            for(int i: x.second){
                v.push_back(indices[i]);
            }
        }
        // now n has the positions of the numbers after sorting
        int i=0;
        int count=0;
        int ans=0;
        vector<int> visited(n,0);
        for(int i=0; i<n; i++){
            if (visited[i]==1) continue;
            int curr=i;
            while(count<n && visited[curr]!=1){
                visited[curr]=1;
                curr=v[curr];
                count++;
            }
            ans+=max(0, count-1);
            count=0;
        }
        return ans;
    }
};