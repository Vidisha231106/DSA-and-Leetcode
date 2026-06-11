// 1048

class Solution {
public:
    int checkWords(string w1, string w2){
        if ((w1.size()-w2.size())!=1) return false;
        int flag=0;
        int n=w1.size();
        int m=w2.size();
        int i1=0,i2=0;

        while(i1<n && i2<m){
            if (flag>1) return false;
            if (w1[i1]!=w2[i2]){
                flag++;
                i1++;
            }
            else{
                i1++;
                i2++;
            }
        }
        if(flag<=1)
        return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(), words.end(), [](string& a, string& b){
            return a.size()<b.size();
        });
        vector <int> dp(n, 1);
        for (int i=0; i<n; i++){
            for (int j=0; j<i; j++){
                if (checkWords(words[i], words[j])){
                    dp[i]=max(dp[i], dp[j]+1);
                }
            }
        }
        int ans=*max_element(dp.begin(), dp.end());
        return ans;
    }
};