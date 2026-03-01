//454
//IMPORTANT

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count =0; 
        unordered_map <int, int> mp1;
        unordered_map <int, int> mp2;
        int n= nums1.size();
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                mp1[nums1[i]+nums2[j]]++;
            }
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                mp2[nums3[i]+nums4[j]]++;
            }
        }
        for(auto it: mp1){
            int complement = -(it.first);
            if (mp2.find(complement)!= mp2.end()){
                count+= (it.second)*mp2[complement];
            }
        }
        return count;
    }
};