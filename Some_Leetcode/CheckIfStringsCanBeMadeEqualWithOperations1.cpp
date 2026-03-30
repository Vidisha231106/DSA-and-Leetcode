// 2839

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        set <char> a = {s1[0], s1[2]};
        set <char> b = {s2[0], s2[2]};
        set <char> c = {s1[1], s1[3]};
        set <char> d = {s2[1], s2[3]};

        return (a==b) && (c==d);
    }
};