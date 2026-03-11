//1980

class Solution {
public:
    string convert(int num, int digits){
        
        string s ="";
        while (num!=0){
            int rem = num%2;
            s.push_back(rem + '0');
            num/=2;
        }
        while(s.size() < digits) s.push_back('0');
        reverse(s.begin(), s.end());
        return s;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int digits=nums[0].length();
        int max_num = pow(2, digits);
        int n = nums.size();
        vector <int> nums_marker(max_num, 0);
        for (int i=0; i<n; i++){
            int decimal=0;
            for (int j=0; j<digits; j++){
                decimal = decimal * 2 + (nums[i][j] - '0');
            }
            nums_marker[decimal]=1;
        }
        for (int i=0; i<max_num; i++){
            if (nums_marker[i]!=1) return convert(i, digits);
        }
        return nums[0];
    }
};