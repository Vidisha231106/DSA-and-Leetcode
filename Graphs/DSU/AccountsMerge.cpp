// 721

class DSU {
public:
    unordered_map<string, string> parent;
    string find(string x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
        }
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(string x, string y) { parent[find(x)] = find(y); }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu;

        unordered_map<string, string> names;
        int n = accounts.size();
        for (int i = 0; i < n; i++) {
            int x = accounts[i].size() - 1;
            for (int j = 1; j <= x; j++) {
                names[accounts[i][j]] = accounts[i][0];
            }
        }

        for (int i = 0; i < n; i++) {
            int x = accounts[i].size() - 1;
            for (int j = 1; j <= x; j++) {
                dsu.unite(accounts[i][1], accounts[i][j]);
            }
        }

        unordered_map<string, vector<string>> components;
        for (int i = 0; i < n; i++) {
            int x = accounts[i].size() - 1;
            for (int j = 1; j <= x; j++) {
                string root = dsu.find(accounts[i][j]);
                components[root].push_back(accounts[i][j]);
            }
        }
        vector<vector<string>> s;
        int m=components.size();
        for (auto it: components){
            unordered_set<string> v;
            int x=it.second.size();
            for (int j=0; j<x; j++){
                v.insert(it.second[j]);
            }
            vector<string> v_new(v.begin(), v.end());
            sort(v_new.begin(), v_new.end());
            v_new.insert(v_new.begin(), names[it.first]);
            s.push_back(v_new);
        }
        return s;
    }
};


//OPTIMISED

class DSU {
public:
    unordered_map<string, string> parent;
    string find(string x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
        }
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(string x, string y) { parent[find(x)] = find(y); }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu;

        unordered_map<string, string> names;
        int n = accounts.size();
        for (int i = 0; i < n; i++) {
            int x = accounts[i].size() - 1;
            for (int j = 1; j <= x; j++) {
                names[accounts[i][j]] = accounts[i][0];
            }
        }

        for (int i = 0; i < n; i++) {
            int x = accounts[i].size() - 1;
            for (int j = 1; j <= x; j++) {
                dsu.unite(accounts[i][1], accounts[i][j]);
            }
        }

        unordered_map<string, vector<string>> components;
        for (auto &it: dsu.parent){
            string root=dsu.find(it.first);
            components[root].push_back(it.first);
        }
        vector<vector<string>> s;
        for (auto &it: components){
            sort(it.second.begin(), it.second.end());
            it.second.insert(it.second.begin(), names[it.first]);
            s.push_back(it.second);
        }
        return s;
    }
};