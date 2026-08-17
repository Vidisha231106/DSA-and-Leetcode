// 4007

class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        int n=planks.size();
        unordered_map<long long, int> mp;
        int answer=0;
        for (int i=0; i<n; i++){
            mp[planks[i]]++;
            answer=max(answer, mp[planks[i]]);
        }
        unordered_set <int> s(planks.begin(), planks.end());
        vector<int> v(s.begin(), s.end());
        int x=v.size();
        unordered_map <long long, int> mp2=mp;
        for (int i=0; i<x; i++){
            for (int j=i; j<x; j++){
                mp2[1LL* v[i]+v[j]]+=(v[i]==v[j])? mp[v[i]]/2:min(mp[v[i]], mp[v[j]]);
                answer=max(answer, mp2[1LL*v[i]+v[j]]);
            }            
        }
        return answer;
    }
};