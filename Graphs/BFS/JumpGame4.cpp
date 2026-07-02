// 1345

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map <int, vector<int>> mp; // pair.first=count, pair.second=same number indices
        for (int i=0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
        queue <int> q;
        vector<int> v(n,0);
        q.push(0);
        v[0]=1;
        int count=0;
        if (n==1) return 0;
        while (q.empty()!=true){
            int s=q.size();
            while (s>0){
                int i=q.front();
                if (i>0 && v[i-1]!=1) {
                    v[i-1]=1;
                    q.push(i-1);
                }
                if (i<n-1 && v[i+1]!=1){
                    v[i+1]=1;
                    q.push(i+1);
                } 
                if (i==n-1) return count;
                for (auto it:mp[arr[i]]){
                    if (it==i) continue;
                    if (v[it]!=1){
                        q.push(it);
                        v[1]=1;
                    }
                }
                q.pop();
                s--;
                mp[arr[i]].clear(); // IMPORTANT
            }
            count++; //after processing each level i increment the count
        }
        return -1;
    }
};