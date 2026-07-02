// 269

class Solution {
public:
    stack <char> s;
    int flag=0; //if cycle detected, flag=1;
    void dfs(unordered_map <char, vector<char>> &mp, char curr, vector<int> &visited){
        if (visited[curr-'a']==2) return;
        if (visited[curr-'a']==1) {
            flag=1;
            return;
        }
        visited[curr-'a']=1;
        for (auto it: mp[curr]){
            dfs(mp, it, visited);
            if (flag==1) return;
        }
        visited[curr-'a']=2;
        s.push(curr);
    }
	string findOrder(string dict[], int n, int k) {
		unordered_map <char, vector<char>> mp; //key is the child and ancestors are in vector
        int prev=dict[0].size();
        int curr=0;
        for (int i=1; i<n; i++){
            int curr=dict[i].size();
            int p=0, c=0;
            while (p<prev && c<curr){
                if (dict[i][c]==dict[i-1][p]){
                    p++;
                    c++;
                }
                else {
                    mp[dict[i-1][p]].push_back(dict[i][c]);
                    break;
                }
            }
            if ((p==curr || c==curr) && prev>curr) return "";
            prev=curr;
        }
        vector<int> visited(26, 0); // index_of_visited='a'+ i;
        for (int i=0; i<k; i++){
            if (visited[i]==0) dfs(mp, 'a'+i, visited);
            if (flag==1) return "";
        }
        string answer="";
        while (s.empty()!=true){
            answer+=s.top();
            s.pop();
        }
        return answer;
	}
};
