// 3960

class Solution {
public:
    int getLength(vector<int>& nums) {
        int n=nums.size();
        int answer=1;
        for (int i=0; i<n-1; i++){
            unordered_map<int, int> f;
            unordered_map<int, int> fof; // freq of frequencies
            int distinct=0;
            f[nums[i]]++;
            fof[f[nums[i]]]++;
            distinct++;
            for (int j=i+1; j<n; j++){
                int old=f[nums[j]];
                f[nums[j]]++;
                if (old>0){
                    fof[old]--;
                    if (fof[old]==0) fof.erase(old); // imp syntax
                }
                if (f[nums[j]]==1) distinct++;
                fof[f[nums[j]]]++;
                //if (fof.size()>2) break;
                int flag=0;
                if (fof.size()==2){
                    auto it=fof.begin();
                    int freq1=it->first;
                    int freq2=next(it)->first; // imp syntax
                    if (freq1==2*freq2 || freq1*2==freq2) flag=1;
                }
                if (flag==1 || distinct ==1) answer=max(answer, j-i+1);
            }
        }
        return answer;
    }
};