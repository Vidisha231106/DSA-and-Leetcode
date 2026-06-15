// 354

//Better Solution

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        // first we sort based on width
        // then we sort based on height
        //then we take max of both answers
        int n=e.size();
        sort(e.begin(), e.end(), [](vector<int>&a, vector<int> &b){
            return (a[0]==b[0])? a[1]>b[1]: a[0]<b[0];
        });
        vector<int> heights;
        for (int i=0; i<n; i++){
            //IMPORTANT!!!!
            //The std::lower_bound algorithm relies on binary search to find the first element that does not compare less than the target value. 
            auto it =lower_bound(heights.begin(), heights.end(), e[i][1]);
            if (it==heights.end()) heights.push_back(e[i][1]);
            else *it=e[i][1];
        }
        return heights.size();
    }
};

//TLE Solution

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        // first we sort based on width
        // then we sort based on height
        //then we take max of both answers
        int n=e.size();
        sort(e.begin(), e.end());
        vector<int> dp1(n,1);
        for (int i=1; i<n; i++){
            for (int j=0; j<i; j++){
                if (e[i][0]>e[j][0] && e[i][1]>e[j][1]){
                    dp1[i]=max(dp1[i], 1+dp1[j]);
                }
            }
        }
        int ans=*max_element(dp1.begin(), dp1.end());
        return ans;
    }
};