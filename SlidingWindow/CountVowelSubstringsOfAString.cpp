// 2062

//my solution: 
class Solution {
public:
    int countVowelSubstrings(string word) {
        int n= word.size();
        int left=0;
        int count=0;
        unordered_map <char, int> mp;
        for (int i=0; i<n; i++){
            if (word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u'){
                left=i;
                break;
            }
        }        
        for (int i=left; i<n; i++){ // i=right
            if (word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u'){
                mp[word[i]]++;
            }
            else{
                mp.clear();
                left=i+1;
                continue;
            }
            int temp_left=left;
            unordered_map <char, int> temp_mp=mp;
            while (temp_mp.size()==5){
                count++;
                temp_mp[word[temp_left]]--;
                if (temp_mp[word[temp_left]]==0) temp_mp.erase(word[temp_left]);
                temp_left++;
            }
        }
        return count;
    }
};

//better solution:
class Solution {
    bool check(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;}
    int func(string s, int k) {
        unordered_map<char, int> hash,hash1;
        int l = 0, n = s.size(), cnt = 0;
        for (int r = 0; r < n; r++) {
            if (!check(s[r])) {
                hash=hash1;
                l=r+1;
                continue;
                
            }
            hash[s[r]]++;
            while(l<r && (hash.size()>k )){
                hash[s[l]]--;
                if(hash[s[l]]==0) hash.erase(s[l]);
                l++;           
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        return func(word, 5) - func(word, 4);
    }
};