// 846

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if (n%groupSize!=0) return false; 
        priority_queue <vector<int>, vector<vector<int>>, greater<>> pq;
        priority_queue <vector<int>> curr;
        unordered_map <int, int> mp;
        for(int x: hand) mp[x]++;
        for(auto x: mp) pq.push({x.first, x.second});
        while (pq.empty()!=true){
            int start=pq.top()[0];
            if (pq.top()[1]>1) curr.push({pq.top()[0], pq.top()[1]-1});
            pq.pop();
            for(int i=1; i<groupSize; i++){
                if (pq.empty()!=true){
                    if (pq.top()[0]!=start+i) {
                        cout<<"start: "<<start<<" , i: "<<i<<" , top: "<< pq.top()[0]<<endl;
                        return false;
                    }
                    if (pq.top()[1]>1) curr.push({pq.top()[0], pq.top()[1]-1});
                    pq.pop();
                }
                else return false;
            }
            while (curr.empty()!=true){
                pq.push(curr.top());
                curr.pop();
            }
        }
        return true;
    }
};