//3871

class Solution {
public:
    long long countCommas(long long n) {
        long long digits =0;
        long long n_copy=n;
        while (n_copy>0){
            digits++;
            n_copy/=10;
        }
        if (digits<=3) return 0; 
        long long commas=0;
        for (int i=1; i<=digits/3; i++){
            long long num = pow(10, 3*i) -1;
            if (n<num) break;
            commas+=(n-num );
        }
        return commas;
    }
};©leetcode