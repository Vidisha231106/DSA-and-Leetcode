// 727

class Solution {
public:
    string minWindow(string s1, string s2) {
        // User code goes here
        int n=s1.length(), m=s2.length();
        int s1_right=0;
        int final_left=0;
        int final_right=0;

        int min_len=INT_MAX;
        int i2=0;
        while (s1_right<n){
            if (s1[s1_right]==s2[0]){
                i2=0;
                int temp=s1_right;
                while (i2<m && s1_right<n){
                    if (s2[i2]==s1[s1_right]){
                        i2++;
                    }
                    s1_right++;
                }
                if (i2!=m) return "";
                i2--;// i2=m-1 now
                s1_right--;
                int end=s1_right;
                while(i2>=0){
                    if (s2[i2]==s1[s1_right]){
                        i2--;
                    }
                    s1_right--;
                }
                s1_right++;//correct window
                if (min_len>end-s1_right+1){
                    final_left=s1_right;
                    final_right=end;
                }
                min_len=min(min_len, end-s1_right+1);
                
                s1_right=temp;
            }
            s1_right++;
        }
        string answer;
        if (min_len==INT_MAX) return "";
        for (int i=final_left; i<=final_right; i++){
            answer.push_back(s1[i]);
        }
        return answer;        
    }
};
