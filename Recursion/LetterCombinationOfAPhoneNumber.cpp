// 17

class Solution {
public:
    vector<string> answer;
    unordered_map <int, string> mp = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7,"pqrs"}, {8, "tuv"}, {9, "wxyz"}};
    void recursion(int size, string curr_st, string& digits, int curr_index){
        if (curr_index>=size){
            answer.push_back(curr_st);
            return;
        }
        for (int i=0; i<mp[digits[curr_index]-'0'].size(); i++){
            curr_st.push_back(mp[digits[curr_index]-'0'][i]);
            recursion(size, curr_st, digits, curr_index+1);
            curr_st.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits=="") return answer;
        recursion(digits.size(), "", digits, 0);
        return answer;
    }
};