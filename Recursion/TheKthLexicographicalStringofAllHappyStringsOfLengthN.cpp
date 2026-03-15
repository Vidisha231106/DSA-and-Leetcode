// 1415

//can be optimised more

class Solution {
public:
    vector <string> answers;
    void recursion(string s, int max_size, int curr_size){
        if (s.size()==max_size){
            answers.push_back(s);
            return;
        }
        for (auto i:{'a', 'b', 'c'}){
            if (s=="" || s.back()!=i) {
                s.push_back(i);
                recursion(s, max_size, curr_size+1);
                s.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        recursion("", n, 1);
        if (k> answers.size()) return "";
        return answers[k-1];
    }
};