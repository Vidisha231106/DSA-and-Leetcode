//2367 - NO NEED OF USING TWO POINTERS HERE!!!

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count =0;
        int n = nums.size();
        for (int i =0; i<n-2;i++){
            int first = i+1, second = n-1;
            while (first<second){
                if (nums[first]-nums[i] ==diff && nums[second]- nums[first]==diff){
                    count++;
                    first++;
                    second--;
                }
                else if (nums[first]-nums[i] <diff) first++;
                else second--;
            }
        }
        return count;
    }
};