// 4036

class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int n=nums.size();
        unordered_map <char, int> letters;
        for(int i=0; i<26; i++){
            letters[(char)('a'+i)]=pow(2,i);
            //cout<<(char)('a'+i)<<" "<<letters['a'+i]<<endl;
        }
        vector<string> ans;
        for(int i=0; i<n; i++){
            int a=nums[i];
            string answer="";
            for(int j=25; j>=0; j--){
                //cout<<(char)('a'+j)<<"        "<<letters[(char)('a'+j)];
                while (a/letters[(char)('a'+j)]>0){
                    int x=(a/letters[(char)('a'+j)]);
                    for(int i=0; i<x; i++) answer+=((char)('a'+j));
                    a=a%letters[(char)('a'+j)];
                }
            }
            ans.push_back(answer);
        }
        return ans;
    }
};