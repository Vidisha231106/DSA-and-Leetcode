// 127

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=endWord.size();
        queue <pair<string, int>> q; // word, number of steps
        q.push({beginWord, 1});
        unordered_set <string> s(wordList.begin(), wordList.end());
        s.erase(beginWord);
        while (q.empty()!=true){
            string curr=q.front().first;
            int steps=q.front().second;
            if (curr==endWord) return steps;
            q.pop();
            for (int i=0; i<n; i++){
                char og=curr[i];
                for (int j=0; j<26; j++){
                    curr[i]='z'-j;
                    if (s.contains(curr)==true){
                        s.erase(curr);
                        q.push({curr, steps+1});
                    }
                }
                curr[i]=og;
            }
        }
        return 0;
    }
};