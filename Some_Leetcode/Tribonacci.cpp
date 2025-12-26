//1137

class Solution {
public:
    int tribonacci(int n) {
        int index=0;
        int a =0, b=0;
        long long c=1;
        if (n==0) return b;
        else if (n==1) return c;
        while (index<n){
            int temp = c;
            c = a+b+c;
            a=b;
            b=temp;
            index++;
        }
        return b;
    }
};