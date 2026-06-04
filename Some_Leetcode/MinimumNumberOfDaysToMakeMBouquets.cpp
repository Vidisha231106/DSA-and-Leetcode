// 1482

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if (n<1LL*m*k) return -1;
        int left=*min_element(bloomDay.begin(), bloomDay.end()); // 1st day
        int right=*max_element(bloomDay.begin(), bloomDay.end());
        int count=0;
        int answer=left;
        while (left<=right){
            int bouquets=0;
            int mid=(left+right)/2;
            cout<<left<<" "<<right<<endl;
            count=0;
            for (int i=0; i<n; i++){
                if (bloomDay[i]<=mid){
                    count++;
                    if ((count)%k==0) bouquets++;
                }
                else{
                    count=0;
                }
            }
            if (bouquets>=m){
                right=mid-1;
                answer=mid;
            }
            else{
                left=mid+1;
            }
        }
        return answer;
    }
};