// 30

class Solution {
public:
    // bool check(unordered_map<string, int> mp, string sub, int w, int n){
    //     for(int i=0; i<w*n; i+=w){
    //         string subsub=sub.substr(i, w);
    //         if(mp.contains(subsub)==false){
    //             return false;
    //         }
    //         else{
    //             mp[subsub]--;
    //             if (mp[subsub]==0) mp.erase(subsub);
    //         }
    //     }
    //     return true;
    // }
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=words.size();
        unordered_map<string, int> mp;
        for(int i=0; i<n; i++){
            mp[words[i]]++;
        }
        int w=words[0].length();
        vector<int> answer;
        int left=0;
        unordered_map<string, int> now;
        int count=0;
        for(int x=0; x<w; x++){
            left=x;
            count=0;
            now.clear();
            for(int i=x; i<s.length(); i+=w){
                string sub=s.substr(i, w);
                if (mp.contains(sub)==true){
                    now[sub]++;
                    count++;
                    while (mp[sub]<now[sub]){
                        string remove=s.substr(left, w);
                        left+=w;
                        count--;
                        now[remove]--;
                    }
                    if (count==n) answer.push_back(left);
                }
                else{
                    now.clear();
                    left=i+w;
                    count=0;
                }
            }
        }
        return answer;
    }
};