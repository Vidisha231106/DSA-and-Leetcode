// 3890

class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        int num = cbrt(n);
        cout<<num;
        vector <int> nums;
        for (int i=0; i<=num; i++){
            long long a =1LL * i*i*i;
            if (a<=n) nums.push_back(a);
        }
        int size=nums.size();

        map <int, int> mp;
        for (int i=0; i<size; i++){
            for (int j=i; j<size; j++){
                if (nums[i]+nums[j] <=n) mp[nums[i]+nums[j]]++;
            }
        }
        vector <int> answer;
        for (auto it:mp){
            if (it.second>=2) answer.push_back(it.first);
        }
        return answer;
    }
};