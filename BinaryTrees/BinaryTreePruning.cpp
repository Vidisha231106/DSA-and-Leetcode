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
 #include <stdbool.h>
class Solution {
public:
    TreeNode* recursion(TreeNode* root){
        if (root==NULL) return NULL;
        root->left = recursion(root->left);
        root->right = recursion(root->right);
        if (root->left==NULL && root->right==NULL && root->val==0) return NULL;
        return root;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if (root==NULL) return NULL;
        return recursion(root);
    }
};