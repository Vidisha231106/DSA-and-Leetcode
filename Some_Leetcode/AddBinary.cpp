// 67

class Solution {
public:
    string addBinary(string a, string b) {
        int a_index=a.length()-1;
        int b_index=b.length()-1;
        int carry=0;
        int sum=0;
        string answer="";
        while (a_index>=0 || b_index>=0 || carry){
            sum=carry;
            if (a_index>=0) sum+=(a[a_index]-'0');
            a_index--;
            if (b_index>=0) sum+=(b[b_index]-'0');
            b_index--;
            carry=sum/2;
            answer+=(sum%2+'0');
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};