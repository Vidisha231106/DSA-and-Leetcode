// 987

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map <int, vector<pair<int,int>>> mp; // col, {row, node}
        int min_col=INT_MAX;
        queue <pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});
        while (q.empty()!=true){
            pair<TreeNode*, pair<int,int>> curr=q.front();
            q.pop();
            min_col=min(curr.second.second, min_col);
            mp[curr.second.second].push_back({curr.second.first, curr.first->val});
            if (curr.first->left) q.push({curr.first->left, {curr.second.first+1, curr.second.second-1}});
            if (curr.first->right) q.push({curr.first->right, {curr.second.first+1, curr.second.second+1}});
        }
        vector<vector<int>> temp(3000);
        for (auto it: mp){
            sort(it.second.begin(), it.second.end());
            int n=it.second.size();
            for (int i=0; i<n; i++){
                temp[it.first-min_col].push_back(it.second[i].second);
            }
        }
        vector<vector<int>> answer;
        for (auto it: temp){
            if (it.empty()!=true) answer.push_back(it);
        }
        return answer;
    }
};