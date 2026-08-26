// 4032

class Solution {
public:
    vector<int> spf;
    unordered_set<int> getFactors(int x){
        unordered_set<int> factors;
        while (x>1){
            int p=spf[x];
            factors.insert(spf[x]);
            while(x%p==0){
                x/=p;
            }
        }
        return factors;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int m=*max_element(nums.begin(), nums.end());
        spf.resize(m+1,0);
        for(int i=2; i<=m; i++){
            if (spf[i]==0){
                for(int j=i; j<=m; j+=i){
                    if (spf[j]==0) spf[j]=i;
                }
            }
        }
        vector<unordered_set<int>> s;
        for(int i=0; i<n; i++){
            unordered_set<int> factors=getFactors(nums[i]);
            s.push_back(factors);
        }
        int left=0;
        unordered_map<int,int> curr;
        int answer=0;
        for(int i=0; i<n; i++){
            for(int x:s[i]){
                curr[x]++;
            }
            while (curr.size()>k){
                for(int x: s[left]){
                    curr[x]--;
                    if (curr[x]==0) curr.erase(x);
                }
                left++;
            }
            answer=max(answer,i-left+1);
        }
        return answer;
    }
};