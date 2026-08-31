// 621

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> last_time;
        unordered_map<char, int> freq;
        int x=tasks.size();
        for(int i=0; i<x; i++){
            freq[tasks[i]]++;
            last_time[tasks[i]]=0;
        }
        priority_queue<pair<int, char>> pq;
        for(auto it: freq){
            pq.push({it.second, it.first});
        }
        int counter=0;
        int remaining=x;
        while (remaining>0){
            for(auto x: last_time){
                if (counter>0 && x.second==counter && freq[x.first]>0) pq.push({freq[x.first], x.first});
            }
            if (pq.empty()==false){
                freq[pq.top().second]--;
                last_time[pq.top().second]=counter+n+1;
                pq.pop();      
                remaining--;
            }
            counter++;
        }
        return counter;
    }
};