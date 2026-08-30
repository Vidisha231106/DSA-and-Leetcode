class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1; i<n; i++){
            prefix[i]=__gcd(prefix[i-1], nums[i]);
        }
        for(int i=n-2; i>=0; i--){
            suffix[i]=__gcd(suffix[i+1], nums[i]);
        }       
        int answer=0;
        for(int i=0; i<n-1; i++){
            if (prefix[i]==suffix[i+1]) {
                answer++;
            }
        }
        for(int i=0; i<n; i++){
            int m=n-1;
            vector<int> miss;
            for(int j=0; j<n; j++){
                if (j!=i) miss.push_back(nums[j]);
            }
            vector<int> prefix(m, 1);
            vector<int> suffix(m, 1);
            prefix[0]=miss[0];
            suffix[m-1]=miss[m-1];
            for(int j=1; j<m; j++){
                prefix[j]=__gcd(prefix[j-1], miss[j]);
            }
            for(int j=m-2; j>=0; j--){
                suffix[j]=__gcd(suffix[j+1], miss[j]);
            }       
            int splits=0;
            for(int j=0; j<m-1; j++){
                if (prefix[j]==suffix[j+1]) {
                    splits++;
                    
                }
            }
            answer=max(answer, splits);
        }
        return answer;
    }
};