//1758

/*
BETTER SOLUTION:

class Solution {
    public int minOperations(String s) {
        int count1 = 0;
        for(int i = 0 ; i < s.length() ; i++){
            char c = s.charAt(i);
            char expected1 = (i%2 == 0) ? '0':'1';
            if (c != expected1) count1++;
        }
        return Math.min(count1,s.length() - count1);
    }
}

*/
class Solution {
public:
    int startNum(char num, string s){
        char flag=num;
        int count=0;
        int n = s.length();
        for (int i=0; i<n; i++){
            if (s[i]!=flag){
                count++;
            }
            flag=(flag=='0')?'1':'0';
        }
        return count;
    }

    int minOperations(string s) {
        int ansZero = startNum('0',s);
        int ansOne=startNum('1',s);
        return min(ansZero, ansOne);
    }
};