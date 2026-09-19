// 1520

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.length();
        unordered_map<char, int> freq;
        unordered_map<char, pair<int,int>> mp;
        for (int i=0; i<n; i++){
            mp[s[i]]={-1, -1};
            freq[s[i]]++;
        }
        for(int i=0; i<n; i++){
            if (mp[s[i]].first==-1) mp[s[i]].first=i;
            mp[s[i]].second=i;
        }
        vector<vector<int>> parts;
        vector<vector<int>> ans;
        //cout<<"here1"<<endl;
        for(auto x: mp){
            int start=x.second.first;
            int end=x.second.second;
            int valid=1;
            for (int i=start; i<=end; i++){
                if (mp[s[i]].first<start) {
                    valid=0;
                    break;
                }
                end=max(end, mp[s[i]].second);
            }
            if (valid==1) ans.push_back({start, end});
        }
        // for(auto x: mp){
        //     //int t=(x.second.second=-1)
        //     if (freq[x.first]==(x.second.second-x.second.first+1)) ans.push_back({x.second.first, x.second.second});
        //     else parts.push_back({x.second.first, x.second.second});
        // }
        // cout<<"ans: "<<endl;
        // for(int i=0; i<ans.size(); i++){
        //     cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
        // }
        // cout<<"parts: "<<endl;
        // for(int i=0; i<parts.size(); i++){
        //     cout<<parts[i][0]<<" "<<parts[i][1]<<endl;
        // }
        // sort(parts.begin(), parts.end(), [](vector<int>& a, vector<int>& b){
        //     if (a[1]!= b[1]) return a[1]< b[1];
        //     return a[0]<b[0];
        // });
        //cout<<"here2"<<endl;
        int x=parts.size();
        // for(int i=0; i<x; i++){
        //     int end=parts[i][1];
        //     int start=parts[i][0];
        //     //cout<<start<<" ,"<< end<<" ";
        //     while (i<x && end<=parts[i][1]){
        //         start=min(start, parts[i][0]);
        //         end=max(parts[i][1], end);
        //         i++;
        //     }
        //     i--;
        //     // cout<<start<<" "<<end<<endl;
        //     // cout<<"here3"<<endl;
        //     ans.push_back({start, end});
        // }
        // cout<<"here4"<<endl;
        // cout<<"ans: "<<endl;
        // for(int i=0; i<ans.size(); i++){
        //     cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
        // }
        sort(ans.begin(), ans.end(), [](vector<int>& a, vector<int>& b){
            if (a[1]!= b[1]) return a[1]< b[1];
            return a[0]<b[0];
        });
        int curr_end=INT_MIN;
        parts.clear();
        int y=ans.size();
        vector<string> answer;
        cout<<"here6"<<endl;
        for(int i=0; i<y; i++){
            cout<<curr_end<<" "<<ans[i][0]<<endl;
            if (curr_end>=ans[i][0]) continue;
            curr_end=max(curr_end, ans[i][1]);
            parts.push_back(ans[i]);
        }
        for(int i=0; i<parts.size(); i++){
            cout<<parts[i][0]<<" "<<parts[i][1]<<endl;
        }
        x=parts.size();
        for(int i=0; i<x; i++){
            answer.push_back(s.substr(parts[i][0], parts[i][1]-parts[i][0]+1));
        }
        //cout<<"here5"<<endl;
        sort(answer.begin(), answer.end());
        return answer;
    }
};