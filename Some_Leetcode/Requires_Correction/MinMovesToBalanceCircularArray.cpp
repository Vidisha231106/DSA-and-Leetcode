//Weekly COntest 480 - Q3

//Time Limit Exceeded -

class Solution {
public:
    int left_index(int curr, int n){
        if (curr==0) return n-1;
        return curr-1;
    }
    int right_index(int curr, int n){
        if (curr==n-1) return 0;
        return curr+1;
    }
    long long minMoves(vector<int>& balance) {
        long long sum=0;
        long long n = balance.size();
        long long index=0;
        for (int i=0; i<n; i++){
            sum+=balance[i];
            if (balance[i]<0) index=i;
        }
        if (sum<0) return -1;
        long long left = left_index(index, n);
        long long right = right_index(index, n);
        long long distance=1;
        long long count=0;
        while (balance[index]<0){
            if (balance[left]>0){
                balance[index]+=1;
                balance[left]-=1;
                count+=(distance);
            }            
            else if (balance[right]>0) {
                balance[index]+=1;
                balance[right]-=1;
                count+=(distance);
            }     
            else{
                left = left_index(left, n);
                right = right_index(right, n);
                distance++;
            }
        }
        return count;
    }
};