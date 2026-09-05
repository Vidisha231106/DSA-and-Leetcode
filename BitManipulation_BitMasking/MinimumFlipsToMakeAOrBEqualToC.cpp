// 1318

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        while (a>0 || b>0 || c>0){
            int aa=a&1;
            int bb=b&1;
            int cc=c&1;
            if (cc==0){
                if (aa==1) count++;
                if (bb==1) count++;
            } 
            else{
                if (aa==0 && bb==0) count++;
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return count;
    }
};