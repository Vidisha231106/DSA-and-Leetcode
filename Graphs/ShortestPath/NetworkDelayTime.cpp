// 743

// Dijkstra's algorithm

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int root) {
        int m=times.size();
        vector<vector<pair<int, int>>> list(n+1);
        // list = {1: [{}], 2: [{1,1}, {3,1}], 3:[{4,1}]} // index: vector at that position (node, distance)
        for (int i=0; i<m; i++){
            list[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<int> v(n+1, INT_MAX);
        v[root]=0;
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        // {dist_from_root, node_number}
        pq.push({0, root});
        int answer=INT_MAX;
        while(pq.empty()!=true){
            int curr_dist=pq.top().first;// 0
            int curr_node=pq.top().second;//2
            pq.pop();
            if (curr_dist>v[curr_node]) continue;
            
            int m=list[curr_node].size();//2
            for (int i=0; i<m; i++){
                if (curr_dist+list[curr_node][i].second<v[list[curr_node][i].first]){
                    v[list[curr_node][i].first]=curr_dist+list[curr_node][i].second;
                    pq.push({v[list[curr_node][i].first], list[curr_node][i].first});
                }
            }
        } 
        answer=*max_element(v.begin()+1, v.end());
        if (answer==INT_MAX) return -1;
        return answer;
    }
};