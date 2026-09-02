// 767

class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        char prev='.';
        int prevf=-1;
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq; // freq of element, element
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        int m=INT_MIN;
        for(auto x: mp){
            pq.push({x.second, x.first});
            m=max(m, x.second);
        }
        int remaining=n-m;
        if (remaining+1<m) return "";
        string answer="";
        while (pq.empty()!=true){
            if (pq.top().first==0) return answer;
            int f=pq.top().first;
            char c=pq.top().second;
            pq.pop();
            if (prev==c) return "";
            answer+=c;
            if (prevf!=-1) pq.push({prevf, prev});
            prevf=f-1;
            prev=c;
        }
        return answer;
    }
};