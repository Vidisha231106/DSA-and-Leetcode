// 4039

class Solution {
public:
    const int MOD=1e9+7;
    long long power(long long x, long long y){
        long long ans=1;
        while (y>0){
            if (y%2!=0) ans=(x*ans)%MOD;
            x=(x*x)%MOD;
            y/=2;
        }
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        int n=nums.size();
        long long answer=0;
        for(int i=0; i<n; i++){
            int width=nums[i]%10;
            long long d=(nums[i]/10);
            long long x=0;
            long long y=0;
            vector<int> v;
            long long temp=nums[i];
            int count=0;
            while (temp>0){
                v.push_back(temp%10);
                temp/=10;
                count++;
            }            
            reverse(v.begin(), v.end());
            int j=0;
            while (j<width){
                x=(x*10)+v[j];
                j++;
            }
            while (j<count-1){
                y=(y*10)+v[j];
                j++;
            }
            answer+=(power(x,y)%MOD);
        }
        return answer%MOD;
    }
};