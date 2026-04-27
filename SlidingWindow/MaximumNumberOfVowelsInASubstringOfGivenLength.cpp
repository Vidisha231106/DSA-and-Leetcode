// 1456

class Solution {
public:
    int maxVowels(string s, int k) {
        int left=0;
        int n =s.length();
        int count=0;
        int max_count=0;
        int i=0;
        while(i<n){
            if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                count++;
            }
            if (i-left+1>k){
                if (s[left]=='a' || s[left]=='e' || s[left]=='i' || s[left]=='o' || s[left]=='u'){
                    count--;
                }
                left++;
            }
            if (i-left+1==k && count>max_count) max_count=count;
            i++;
        }
        return max_count;
    }
};