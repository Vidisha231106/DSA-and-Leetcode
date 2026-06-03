// 875

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int p=piles.size();
        int right=*max_element(piles.begin(), piles.end());
        int left=1;
        long long mid=(left+right)/2;
        long long count=0;
        while (left<=right){
            mid=(left+right)/2;
            count=0;
            for (int i=0; i<p; i++){
                if (piles[i]<=mid) count++;
                else{
                    count+=((long long) piles[i]/mid);
                    if (piles[i]%mid!=0) count++;
                }
            }
            if (count<=h){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};