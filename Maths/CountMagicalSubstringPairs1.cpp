// 4090

class Solution {
public:
    int countMagicalPairs(string s) {
        int n=s.length();
        int ans=0;
        for(int j=0; j<n-1; j++){
            vector<int> left(27,0);
            vector<int> right(27,0);
            unordered_map<char, int> mp;
            for(int i=j; i>=0; i--){
                mp[s[i]]++;
                left[mp.size()]++;
            }
            mp.clear();
            for(int k=j+1; k<n; k++){
                mp[s[k]]++;
                right[mp.size()]++;
            }
            for(int i=1; i<=26; i++){
                ans+=(left[i]*right[i]);
            }
        }
        return ans;
    }
};