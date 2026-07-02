// 126

//Better Approach

class Solution {
public:
    unordered_map <string, vector<string>>parent;
    unordered_map <string, int> level;
    vector<vector<string>> answer;
    void dfs(string curr, string &beginWord, vector<string>& v){
        if (curr==beginWord){
            vector<string> temp=v;
            reverse(temp.begin(), temp.end());
            answer.push_back(temp);
            return;
        }
        int x=parent[curr].size();
        for (int i=0; i<x;i++){
            v.push_back(parent[curr][i]);
            dfs(parent[curr][i], beginWord, v);
            v.pop_back();
        }
    }    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> s(wordList.begin(), wordList.end());
        queue <string> q;
        q.push(beginWord);
        level[beginWord]=0;
        while (q.empty()!=true){
            string curr=q.front();
            string copy=curr;
            q.pop();
            int x=curr.size();
            for (int i=0; i<x;i++){
                char org=curr[i];
                for (int j=0; j<26; j++){
                    curr[i]='a'+j;
                    if (s.contains(curr)==true){
                        if (level.contains(curr)==false){
                            level[curr]=level[copy]+1;
                            parent[curr].push_back(copy);
                            q.push(curr);
                        }
                        else if (level[curr]==level[copy]+1){
                            parent[curr].push_back(copy);
                        }
                    }
                }
                curr[i]=org;
            }
        }
        vector<string> v;
        v.push_back(endWord);
        dfs(endWord, beginWord, v);
        return answer;
    }
};

//Memory Expensive Approach

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> s(wordList.begin(), wordList.end());
        queue <vector<string>>q;
        q.push({beginWord});
        vector<string> onSameLevel;
        onSameLevel.push_back(beginWord);
        int level=0;
        vector<vector<string>> ans;
        while(q.empty()!=true){
            vector<string> v=q.front();
            q.pop();
            if (v.size()>level){
                level++;
                int sl=onSameLevel.size();
                for (int i=0; i<sl; i++){
                    s.erase(onSameLevel[i]);
                }
                onSameLevel.clear();
            }
            string curr_word=v.back();
            if (curr_word==endWord){
                if (ans.size()==0 || ans[0].size()==v.size()) ans.push_back(v);
            }
            int x=curr_word.size();
            for (int i=0; i<x; i++){
                char org=curr_word[i];
                for (int j=0; j<26; j++){
                    curr_word[i]='a'+j;
                    if (s.contains(curr_word)){
                        v.push_back(curr_word);
                        q.push(v);
                        onSameLevel.push_back(curr_word);
                        v.pop_back();
                    }
                }
                curr_word[i]=org;
            }
        }
        return ans;
    }
};