// 3488

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int q_n = queries.size();
        vector<int> answer(q_n, -1);

        map<int, set<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].insert(i);
        }
        for (int i = 0; i < q_n; i++) {
            int min_index=INT_MAX;
            auto & num = mp[nums[queries[i]]];
            if (num.size()==1){
                answer[i]=-1;
                continue;
            }
            auto upper_num=num.upper_bound(queries[i]);
            auto lower_num=num.lower_bound(queries[i]);
            if (upper_num==num.end())upper_num=num.begin();
            if (upper_num!=num.end()){
                min_index=min(min_index, min(n-abs(*upper_num-queries[i]), abs(*upper_num-queries[i])));
            }
            if (lower_num==num.begin()) lower_num=num.end();
            if (lower_num!=num.begin()){
                lower_num--;
                min_index=min(min_index, min(n-abs(*lower_num-queries[i]), abs(*lower_num-queries[i])));
            }
                        
            answer[i] = min_index;
        }
        return answer;
    }
};