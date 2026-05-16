// 1092

class Solution {
public:
    void recursion(vector<vector<string>> dp){
        
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int s1=str1.size();
        int s2=str2.size();
        vector<vector<int>> dp (s1+1, vector<int>(s2+1, 0));      
        for (int i=1; i<=s1; i++){
            for(int j=1; j<=s2; j++){
                if (str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string answer="";

        while (s1>0 && s2>0){
            if (str1[s1-1]==str2[s2-1]){
                answer+=str1[s1-1];
                s1--;
                s2--;
            }
            else if (dp[s1-1][s2]>dp[s1][s2-1]){
                answer+=str1[s1-1];
                s1--;
            }
            else{
                answer+=str2[s2-1];
                s2--;
            }
        }
        while(s1>0){
            answer+=str1[s1-1];
            s1--;
        }
        while(s2>0){
            answer+=str2[s2-1];
            s2--;
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};