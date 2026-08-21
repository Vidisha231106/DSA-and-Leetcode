// 3302

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int l1=word1.length();
        int l2=word2.size();
        vector<int> dp(l1+1, 0);
        for(int i=l1-1; i>=0; i--){
            if (dp[i+1]<l2 && word1[i]==word2[l2-dp[i+1]-1]) dp[i]=dp[i+1]+1;
            else dp[i]=dp[i+1];
        }
        int i=0, j=0;
        vector<int> answer;
        int flag=1;
        while (i<l1 && j<l2){
            if (word1[i]==word2[j] || (dp[i+1]==dp[i] && (l2-j-1)<=dp[i] && flag)) {
                answer.push_back(i);
                if (word1[i]!=word2[j]) flag=0;
                j++;                
            }
            i++;
        }
        if (j==l2) return answer;
        return {};
    }
};
