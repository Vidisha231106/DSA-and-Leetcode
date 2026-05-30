// 7 - Check how it is optimised

class Solution {
public:
    int reverse(int x) {
        long long n=0;
        while (x!=0){
            int digit=x%10;
            x/=10;
            
            if (INT_MAX/10<n || INT_MIN/10>n) return 0;
            n=(n*10)+digit;
        }
        
        return n;
    }
};