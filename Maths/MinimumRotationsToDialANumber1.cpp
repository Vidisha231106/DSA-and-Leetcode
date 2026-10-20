// 4070

class Solution {
public:
    int minRotations(string s) {
        int sum=0;
        int prev=0;
        int n=s.length();
        for (int i=0; i<n; i++){
            int x=s[i]-'0';
            sum+=min(abs(x-prev), 9+min(prev,x)-max(prev,x)+1);
            prev=x;
            cout<<sum<<endl;
        }
        return sum;
    }
};