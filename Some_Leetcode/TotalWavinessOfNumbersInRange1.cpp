// 3751

//more optimised code: 

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int t = 0;
        for (int i=num1; i <= num2; i++) {
            t += wavy(i);
        }
        return t;
    }

private:
    int wavy(int n) {
        if (n < 101) return 0;
        int w = 0, a, b, c;

        c = n%10, n /= 10;
        b = n%10, n /= 10;
    
        while (n) {
            a = n%10;
            if ((b>a && b>c) || (b<a && b<c)) w++;
            c=b, b=a, n /= 10;
        }

        return w;
    }
};

// my code:

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        vector<int> v(5,-1);
        int count=0;
        for (int i=max(100,num1); i<=num2; i++){
            int n=i;
            v={-1,-1,-1,-1,-1};
            int ind=0;
            while (ind<5 && n>0){
                v[ind]=n%10;
                n/=10;
                ind++;
            }
            if (ind<3) continue;
            for (int j=1; j<4; j++){
                if (j<4 && v[j+1]==-1) break;
                if ((v[j]>v[j-1] && v[j]>v[j+1]) || (v[j]<v[j-1] && v[j]<v[j+1])){
                    count++;
                    cout<<v[j]<<" ";
                }
            }
            cout<<endl;
        }
        return count;
    }
};