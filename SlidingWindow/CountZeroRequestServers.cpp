// 2747

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        // x is the window size
        int l=logs.size();
        int q=queries.size();
        vector<pair<int, int>> ind;
        for(int i=0; i<q; i++) {
            ind.push_back({queries[i], i});
        }
        for(int i=0; i<l ;i++){
            swap(logs[i][0], logs[i][1]);
        }
        sort(logs.begin(), logs.end());
        sort(ind.begin(), ind.end());
        int left=0;
        // for(int ll=0; ll<l; ll++){
        //     if (logs[ll][0]>=queries[0]-x){
        //         left=ll;
        //         break;
        //     }
        // }
        int right=0;
        vector<int> ans(q, n);
        // if (left==-1) return ans;
        unordered_map<int, int> mp;
        for(int i=0; i<q; i++){
            int curr=ind[i].first;
            //int temp=left;
            while(right<l && logs[right][0]<=curr){
                mp[logs[right][1]]++;
                right++;
            }
            while (left<l && logs[left][0]<curr-x){
                mp[logs[left][1]]--;
                if (mp[logs[left][1]]==0) mp.erase(logs[left][1]);
                left++;
            }
            ans[ind[i].second]=n-mp.size();
        }
        return ans;
    }
};