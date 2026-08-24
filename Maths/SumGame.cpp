// 1927

class Solution {
public:
    bool sumGame(string num) {
        int n=num.length();
        int left_sum=0;
        int right_sum=0;
        int left=0;
        int right=0;
        for(int i=0; i<n/2; i++){
            if (num[i]=='?') left++;
            else left_sum+=(num[i]-'0');
        }
        for(int i=n/2; i<n; i++){
            if (num[i]=='?') right++;
            else right_sum+=(num[i]-'0');
        }
        int requirement=(abs(left-right));
        cout<<left<<" "<<right<<endl;
        cout<<left_sum<<" "<<right_sum<<endl;
        if ((left+right)%2==1) return true;
        if (left+right==0 && left_sum==right_sum) return false;
        if ((left-right)%2==0 && (left_sum-right_sum)==(-9*(left-right)/2)) {
            return false;
            // if (left_sum>right_sum && left>right) return false; 
            // if (left_sum<right_sum && left<right) return false;
        } 
        return true;
    }
};