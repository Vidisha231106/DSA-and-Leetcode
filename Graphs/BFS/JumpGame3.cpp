// 1306

//BFS

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        queue<int> q;
        // q holds the indices that can be reached from each node
        q.push(start);
        vector<int>v (n,0);
        while (q.empty()!=true){
            int i=q.front();//5
            if (v[i]>1) {
                q.pop();
                continue;
            }
            v[i]+=1;
            if (arr[i]==0) return true;
            if (i+arr[i]<n) q.push(i+arr[i]);
            if (i-arr[i] >=0 ) q.push(i-arr[i]);
            q.pop();
        }
        return false;
    }
};