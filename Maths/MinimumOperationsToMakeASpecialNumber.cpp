// 2844

class Solution {
public:
    int minimumOperations(string num) {
        unordered_map <int,vector<int>> mp;
        int n=num.length();
        for (int i=0; i<n; i++){
            if (num[i]=='0' ||num[i]=='7'||num[i]=='2'||num[i]=='5') mp[num[i]-'0'].push_back(i);
        }
        int ans=(mp[0].size()==0) ? n: n-1;
        for (int i=0; i<mp[2].size(); i++){
            for (int j=0; j<mp[5].size(); j++){
                if (mp[2][i]>mp[5][j]) continue;
                ans=min(ans, (n-1-mp[5][j])+mp[5][j]-mp[2][i]-1);
            }
        }
        for (int i=0; i<mp[5].size(); i++){
            for (int j=0; j<mp[0].size(); j++){
                if (mp[5][i]>mp[0][j]) continue;
                ans=min(ans, (n-1-mp[0][j])+mp[0][j]-mp[5][i]-1);
            }
        }
        for (int i=0; i<mp[7].size(); i++){
            for (int j=0; j<mp[5].size(); j++){
                if (mp[7][i]>mp[5][j]) continue;
                ans=min(ans, (n-1-mp[5][j])+mp[5][j]-mp[7][i]-1);
            }
        }
        for (int i=0; i<mp[0].size(); i++){
            for (int j=0; j<mp[0].size(); j++){
                if (mp[0][i]>mp[0][j]) continue;
                if (i==j) continue;
                ans=min(ans, (n-1-mp[0][j])+mp[0][j]-mp[0][i]-1);
            }
        }
        return ans;
    }
};