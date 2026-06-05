// 1011

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n= weights.size();
        int left=*max_element(weights.begin(), weights.end());
        int right=accumulate(weights.begin(), weights.end(), 0);
        while(left<=right){
            int mid=(left+right)/2;
            cout<<left<<" "<<right<<endl;
            int i=0; 
            int curr=0;
            int count=1;
            while (i<n){
                if (curr+weights[i]>mid) {
                    curr=0;
                    count++;
                }
                else{
                    curr+=weights[i];
                    i++; // IMPORTANT: go to next package only when overflow is taken care of  
                }
            }
            if (count<=days){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};