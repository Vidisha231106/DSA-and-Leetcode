// 4094

class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n=nums.size();
        vector<int> mp(100001,0);
        int ans=n;
        for(int i=0; i<n; i++){
            vector<int> opp(n+2, 0);
            vector<int> order;
            mp[nums[i]]++;  
            opp[1]++;
            order.push_back(nums[i]);
            for (int j=i+1; j<n; j++){
                if (mp[nums[j]]>0){
                    opp[mp[nums[j]]]--;
                }
                else{
                    order.push_back(nums[j]);
                }
                mp[nums[j]]++;
                opp[mp[nums[j]]]++;

                int flag=true;
                int o=order.size();
                if ((o*(o+1)/2)!=(j-i+1)) continue;
                if(flag==false) continue;
                int count=1;
                while (count<=o){
                    if (opp[count]!=1){
                        flag=false;
                        break;
                    }
                    count++;
                }
                if(flag==false) continue;
                for(int k=0; k<order.size(); k++){
                    if (mp[order[k]]!=k+1) {
                        flag=false;
                        break;
                    }
                }
                if (flag==true) {
                    ans++;
                }
            }       
            for(int i: order) mp[i]=0;
        }
        return ans;
    }
};