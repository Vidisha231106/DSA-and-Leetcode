// 74

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int outer_left=0;
        int outer_right=n-1;
        while (outer_left<=outer_right){
            int outer_mid=(outer_left+outer_right)/2;
            if (matrix[outer_mid][0]>target){
                outer_right=outer_mid-1;
            }
            else if (matrix[outer_mid][0]<=target){
                if (matrix[outer_mid][m-1]>=target){
                    int inner_left=0;
                    int inner_right=m-1;
                    while (inner_left<=inner_right){
                        int inner_mid=(inner_left+inner_right)/2;
                        if (matrix[outer_mid][inner_mid]>target){
                            inner_right=inner_mid-1;
                        }
                        else if (matrix[outer_mid][inner_mid]<target){
                            inner_left=inner_mid+1;
                        }
                        else {
                            return true;
                        }
                    }
                }
                outer_left=outer_mid+1;
            }
            else return true;
            
        }
        return false;
    }
};