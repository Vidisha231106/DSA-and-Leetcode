// 4071

class Solution {
public:
    int minRotations(int n, string s) {
        int x=s.length();
        vector<int> front(x,0);
        for (int i=0; i<x; i++){
            if (i==0) {
                front[i]=min(s[i]-'0', 10-(s[i]-'0')+(0));
            }
            else {
                front[i]=front[i-1]+min(max(s[i]-'0', s[i-1]-'0')-min(s[i]-'0', s[i-1]-'0'), 10-max(s[i]-'0', s[i-1]-'0')+min(s[i]-'0', s[i-1]-'0'));
            }
        } 

        vector<int> back(x,0);
        for (int i=x-1; i>=0; i--){
            if (i==x-1) {
                back[i]=0;
            }
            else {
                back[i]=back[i+1]+min(max(s[i]-'0', s[i+1]-'0')-min(s[i]-'0', s[i+1]-'0'), 10-max(s[i]-'0', s[i+1]-'0')+min(s[i]-'0', s[i+1]-'0'));
            }
        } 

        int ans=min(front[x-1], min(s[x-1]-'0', 10-(s[x-1]-'0'))+back[0]);
        for(int i=1; i<x; i++){
            int extra=min(max(s[i-1]-'0', s[x-1]-'0')-min(s[i-1]-'0', s[x-1]-'0'), 10-max(s[i-1]-'0', s[x-1]-'0')+min(s[i-1]-'0', s[x-1]-'0'));
            ans=min(ans, front[i-1]+back[i]+extra);
        }
        return ans;
    }
};