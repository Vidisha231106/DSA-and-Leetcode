// 3733

// VERY VERY VERY IMPORTANT

class Solution {
public:
    long long lcm(long long n, long long m) {
        return (1LL*n*m)/__gcd(n,m);
    }
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long left=d[0]+d[1];
        long long right=2e11;
        while (left<right){
            long long t=(left+right)/2;
            long long c0= t-floor(t/r[0]);
            long long c1=t-floor(t/r[1]);
            long long shared = c0+c1-t+(floor(t/lcm(r[0], r[1])));
            long long exclusive0= c0-shared;
            long long exclusive1=c1-shared;
            //IMPORTANT - i cannot use negative values of  d[i]-exclusivei
            long long x = max(0LL, ((long long)d[0]-exclusive0))+max(0LL, ((long long)d[1]-exclusive1));
            if (x<=shared) right=t;
            else left=t+1;
        }
        return left;
    }
};