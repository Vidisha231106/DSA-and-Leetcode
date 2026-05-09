// 1653

class Solution {
public:
    int minimumDeletions(string s) {
        // our string should look like as in the beginning and bs at the end
        int n = s.length();
        vector<int> bs_before(n+1,0);
        vector<int> as_after(n+1,0);

        for (int i=0; i<n; i++){
            bs_before[i+1]=(s[i]=='b')? bs_before[i]+1 : bs_before[i];
        }
        for(int i=n-1; i>=0; i--){
            as_after[i]=(s[i]=='a')? as_after[i+1]+1 : as_after[i+1];
        }
        int answer=INT_MAX;
        for (int i=0; i<=n; i++){
            answer=min(answer, as_after[i]+bs_before[i]);
        }
        return answer;
    }
};