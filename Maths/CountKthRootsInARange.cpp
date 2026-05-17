// 3932

// Dont overthink and use log, not needed if you can optimise the q for TLE and edge cases

//wrong solution: some random logic that failed

class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int count=0; 
        for(int i=l; i<=r; i++){
            if (((log(i)/log(k))-(int)(log(i)/log(k)))==0) {
                cout<<i<<" "<<endl;
                count++;
            }
        }
        return count;
    }
};©leetcode


//Correct solution:

class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int count=0; 
        long long p=0;
        int start=(l==0)?0:1;
        if (k==1) return r-l+1;
        for(long long i=start; i<=r; i++){
            p=pow(i,k);
            if (p>=l && p<=r) count++;
            if (p>r) break;
        }
        return count;
    }
};©leetcode