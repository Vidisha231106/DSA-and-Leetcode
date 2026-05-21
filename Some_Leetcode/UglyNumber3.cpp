// 1201

class Solution {
public:
    long long lcm(long long a, long long b){
        return a*b/__gcd(a,b);
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        long long left=1;
        long long right=2e9;
        while (left<right){
            long long mid=(left+right)/2;
            long long count=(mid/a)+(mid/b)+(mid/c) - (mid/lcm(a,b)) - (mid/lcm(c,b)) - (mid/lcm(a,c)) + (mid/lcm(lcm(a,b),c));
            if (count>=n){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};