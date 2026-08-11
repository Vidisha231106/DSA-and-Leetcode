// 863

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map <TreeNode*, TreeNode*> mp;
        // child: parent
        queue <TreeNode*> q;
        q.push(root);
        mp[root]=nullptr;
        TreeNode* temp=root;
        while (q.empty()!=true){
            TreeNode* curr=q.front();
            q.pop();
            if (curr->left) {
                q.push(curr->left);
                mp[curr->left]=curr;
            }
            if (curr->right) {
                q.push(curr->right);
                mp[curr->right]=curr;
            }
        }
        
        queue <pair<TreeNode*, int>> nq;
        nq.push({target,0});
        nq.push({mp[target], 1});//push parent
        for (auto it: mp){
            // push all children
            if (it.second==target){
                nq.push({it.first, 1});
            }
        }        
        unordered_set <TreeNode*> s;
        vector <int> answer;
        while (nq.empty()!=true){
            pair<TreeNode*, int> curr=nq.front();
            nq.pop();
            if (curr.first==nullptr) continue;
            if (s.contains(curr.first)==true) continue;
            if (curr.second==k) answer.push_back(curr.first->val);
            s.insert(curr.first);
            if (curr.first->left) nq.push({curr.first->left, curr.second+1});
            if (curr.first->right) nq.push({curr.first->right, curr.second+1});
            nq.push({mp[curr.first], curr.second+1});
        }
        return answer;
    }
};