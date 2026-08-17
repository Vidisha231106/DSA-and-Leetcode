// 4021

class Solution {
public:
    pair<string, int> shiftLeftCost(string s){
        int n=s.length();
        string ns=s.substr(1, n-1);
        ns.push_back(s[0]);
        int cost=0;
        for(int i=0; i<n/2; i++){
            cost+=min((((ns[n-i-1]-'a')-(ns[i]-'a')+26)%26), (((ns[i]-'a')-(ns[n-i-1]-'a')+26)%26));
        }
        return {ns,cost};
    }
    int minOperations(string s) {
        int n=s.length();
        string curr=s;
        int answer=INT_MAX;
        //case of no rotation
        int temp=0;
        for(int i=0; i<n/2; i++){
            temp+=min((((s[n-i-1]-'a')-(s[i]-'a')+26)%26), (((s[i]-'a')-(s[n-i-1]-'a')+26)%26));
        }
        answer=min(INT_MAX,temp);
        //case of rotations
        for(int i=1; i<n; i++){
            pair<string, int> next=shiftLeftCost(curr);
            answer=min(answer, i+next.second);
            curr=next.first;
        }
        return answer;
    }
};