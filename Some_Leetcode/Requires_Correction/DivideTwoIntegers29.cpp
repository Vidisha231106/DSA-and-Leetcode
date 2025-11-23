//Extremely inefficent code- 

/*
Accepted
994 / 994 testcases passed
vidishadewan
vidishadewan
submitted at Nov 23, 2025 12:18

Solution

Runtime
1179ms
Beats
7.39%
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (divisor==1) return (int ) dividend;
        if (divisor==-1) return (int) -dividend;
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long quotient=0;
        int flag=1;
        if ((dividend<0 && divisor>0) || (dividend>0 && divisor<0)) flag=0;
        while (a>=b){
            a-=b;
            quotient++;
        }
        if (flag==0) return (int) quotient-(2*quotient);
        return (int) quotient;
    }
};