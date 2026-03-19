// 556

class Solution {
public:
    int nextGreaterElement(int n) {
        string s= to_string(n);
        int digits=s.size();
        int index=-1;
        int next_index=0;
        for (int i=digits-2; i>=0; i--){
            if (s[i]<s[i+1]){
                index=i;
                break;
            }
        }
        if (index==-1){
            return -1;
        }
        for (int i=digits-1; i>index; i--){
            if (s[i]>s[index]){
                next_index=i;
                break;
            }
        }
        int temp = s[index];
        s[index]=s[next_index];
        s[next_index]=temp;
        reverse(s.begin()+index+1, s.end());
        long long num = stoll(s);
        if (num>INT_MAX) return -1;
        return (stoll(s)>n)?stoll(s):-1;
    }
};