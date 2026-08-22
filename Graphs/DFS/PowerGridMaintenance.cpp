// 3607

class Solution {
public:
    unordered_map<int, set<int>> ids; // id: set of numbers in same block
    unordered_map<int,int> individual; // number: id
    unordered_map<int, vector<int>> mp;// node: vector of neighbours
    void dfs(int i, int id){
        if (individual.contains(i)==true) return;
        if (mp.contains(i)==false) {
            individual[i]=id;
            ids[id].insert(i);
            return;
        }
        ids[id].insert(i);
        individual[i]=id;
        int x=mp[i].size(); // mp[i] is a vector here
        for(int j=0; j<x; j++){
            dfs(mp[i][j], id);
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        int m=connections.size();
        for(int i=0; i<m; i++){
            mp[connections[i][0]].push_back(connections[i][1]);
            mp[connections[i][1]].push_back(connections[i][0]);
        }
        for(int id=1;id<=c; id++){
            int num=id;
            dfs(num, id);
        }
        int n=queries.size();
        vector<int> answer;
        for(int i=0; i<n; i++){
            int set_num=individual[queries[i][1]];
            if (queries[i][0]==2){
                ids[set_num].erase(queries[i][1]);
            }
            else{
                if (ids[set_num].contains(queries[i][1])){
                    answer.push_back(queries[i][1]);
                }
                else{
                    if(ids[set_num].begin()==ids[set_num].end()) answer.push_back(-1);
                    else answer.push_back(*ids[set_num].begin());
                }
            }
        }
        return answer;
    }
};