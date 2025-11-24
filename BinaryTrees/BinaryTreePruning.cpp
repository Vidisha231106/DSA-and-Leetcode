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
    void recursion(TreeNode* root){
        if (root==NULL) return;
        if (root->val!=1){
            if (root->left!=NULL && root->left->val!=1) root->left=NULL;
            if (root->right!=NULL && root->right->val!=1) root->right=NULL;
        }
        if (root->left!=NULL)recursion(root->left);
        if (root->right!=NULL)recursion(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode* copy_root=root;
        recursion(root);
        return copy_root;
    }
};