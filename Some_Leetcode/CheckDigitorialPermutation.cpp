// 3848

class Solution {
public:
    int fact(int n){
        if (n<=1) return 1;
        return n*fact(n-1);
    }
    bool isDigitorialPermutation(int n) {
        int sum_of_fact=0;
        int n_copy=n;
        vector<int> digits;
        // digits of the number
        n_copy=n;
        while (n_copy>0){
            digits.push_back(n_copy%10);
            n_copy/=10;
        }
        n_copy=n;
        // sum of the factorials
        while (n_copy>0){
            sum_of_fact+=fact(n_copy%10);
            n_copy/=10;
        }
        cout<<sum_of_fact<<endl;
        
        //digits of the sum_of_fact
        vector<int> digits_of_sum;
        n_copy=n;
        while (sum_of_fact>0){
            digits_of_sum.push_back(sum_of_fact%10);
            sum_of_fact/=10;
        }
        
        sort(digits.begin(), digits.end());
        sort(digits_of_sum.begin(), digits_of_sum.end());

        if (digits.size()!=digits_of_sum.size()) return false;
        int s = digits.size();
        for (int i=0;i <s; i++){
            if( digits[i]!= digits_of_sum[i])return false;
        }
        return true;
    }
};