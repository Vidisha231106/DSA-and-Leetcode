// 2840

// Better Solution:

class Solution {
public:
    static bool checkStrings(string& s1, string& s2) {
        array<array<int, 26>, 2> freq{};
        constexpr array<array<int, 26>, 2> zero{};
        const int n=s1.size();
        for(int i=0; i<n; i++){
            bool iOdd=i&1;
            freq[iOdd][s1[i]-'a']++;
            freq[iOdd][s2[i]-'a']--;
        }
        return freq==zero;
    }
};

// My solution: 

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        multiset <char> a;
        multiset <char> b;
        multiset <char> c;
        multiset <char> d;
        for (int i=0; i<n; i+=2) a.insert(s1[i]);
        for (int i=0; i<n; i+=2) b.insert(s2[i]);
        for (int i=1; i<n; i+=2) c.insert(s1[i]);
        for (int i=1; i<n; i+=2) d.insert(s2[i]);

        return (a==b) && (c==d);
    }
};