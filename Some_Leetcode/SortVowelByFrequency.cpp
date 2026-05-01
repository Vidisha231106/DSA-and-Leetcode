// 3913

class Solution {
public:
    string sortVowels(string s) {
        int n = s.length();
        vector<pair<int, char>> v= {{0,'a'}, {0,'e'}, {0,'i'}, {0,'o'}, {0,'u'}};
        for (int i=0; i<n; i++){
            if (s[i]=='a' || s[i]=='i' || s[i]=='e' ||s[i]=='u' || s[i]=='o'){
                for (int j=0; j<5; j++){
                    if (v[j].second==s[i]) v[j].first++;
                }
            }
        }
        map<char, int> order={{'a', INT_MAX}, {'e', INT_MAX}, {'i', INT_MAX}, {'o', INT_MAX}, {'u', INT_MAX}};
        for (int i=0; i<n; i++){
            if (s[i]=='a' || s[i]=='i' || s[i]=='e' ||s[i]=='u' || s[i]=='o'){
                if (order[s[i]]==INT_MAX) {
                    order[s[i]]=i;
                }
            }
        }
        //IMPORTANT METHOD TO SORT THE ARRAY

        sort(v.begin(), v.end(), [&](pair<int, char> &one, pair<int, char> &two){
            if (one.first!=two.first) return one.first>two.first;
            else return order[one.second]<order[two.second];
        });
        string vowels="";

        for (int i=0; i<5; i++){
            for (int j=0; j<v[i].first; j++){
                vowels.push_back(v[i].second);
            }
        }
        int index=0; 
        for (int i=0; i<n; i++){
            if (s[i]=='a' || s[i]=='i' || s[i]=='e' ||s[i]=='u' || s[i]=='o'){
                s[i]=vowels[index];
                index++;
            }
        }
        return s;
    }
};