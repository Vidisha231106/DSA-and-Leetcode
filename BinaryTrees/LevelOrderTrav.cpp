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
#include <algorithm>
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if (root==NULL) return answer;
        queue <TreeNode*> q;
        q.push(root);
        int num=0;
        while (q.empty()==false){
            int levelSize = q.size();
            vector <int> level;
            for (int i=0; i<levelSize; i++){
                TreeNode * current = q.front();
                q.pop();
                level.push_back(current->val);
                if (current->left!=NULL) q.push(current->left);
                if (current->right!=NULL) q.push(current->right);
            }
            if (num%2!=0) reverse (level.begin(), level.end());
            answer.push_back(level);
            num++;
        }
        return answer;
    }
};