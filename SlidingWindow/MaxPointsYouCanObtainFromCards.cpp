// 1432

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n =cardPoints.size();

        int sum=0;
       
        for (int i=0; i<k; i++) sum+=cardPoints[i];
        int max=sum;
        int left=k-1;
        int right=n-1;
        for (int i=0; i<k; i++){
            sum-=cardPoints[left];
            left--;
            sum+=cardPoints[right];
            right--;
            if (max<sum) max=sum;            
        }
        return max;
    }
};