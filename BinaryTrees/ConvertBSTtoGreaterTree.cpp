//538

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
    void recursion(TreeNode* root, int& curr){
        if (root==nullptr) return;
        if (root->right!=nullptr) {
            recursion(root->right, curr);       
        }
        root->val+=curr;
        curr=root->val;

        if (root->left!=nullptr){
            recursion(root->left, curr);
        } 
    }
    TreeNode* convertBST(TreeNode* root) {
        if (root==nullptr) return root;
        int curr=0;
        recursion(root, curr);
        return root;
    }
};