// 4032

class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        unordered_set <int> s(nums.begin(), nums.end());
        int b=lower;
        int e=lower;
        //vector<int> absent;
        while(s.contains(b)){
            b++;
        }
        e=b;
        if (lower==upper && s.contains(lower)==false) return {{lower, upper}};
        vector<vector<int>> answer;
        for(int i=b; i<=upper; i++){
            if (s.contains(i)==true){
                cout<<b<<" "<<e-1<<endl;
                if (b==e) {
                    b++;
                    e++;
                }
                else if (e>lower && b<=e-1 && b<e) {
                    answer.push_back({b, e-1});
                    b=i+1;
                    e=b;
                }
            }
            else{
                e++;
            }
        }
        if (s.contains(b)) b++;
        e=upper;
        if (e>lower && b<=e) {
                    answer.push_back({b, e});
                }
        //answer.push_back({absent[b],absent[e]});
        return answer;
    }
};