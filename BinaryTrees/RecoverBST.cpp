//99

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
    TreeNode* wrong_val=nullptr;
    TreeNode* replace_val=nullptr;
    TreeNode* prev=nullptr;
    void inorder_traversal(TreeNode* root){
        if (root==nullptr) return;
        inorder_traversal(root->left);
        if (prev!=nullptr && root->val<prev->val){
            if (wrong_val==nullptr) wrong_val = prev;
            replace_val =root;
        }
        prev= root;
        inorder_traversal(root->right);
        
    }
    void recoverTree(TreeNode* root) {
        inorder_traversal(root);
        int temp= wrong_val->val;
        wrong_val->val = replace_val->val;
        replace_val->val=temp;
    }
};