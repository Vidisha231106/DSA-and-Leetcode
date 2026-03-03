//543

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
    int diam = 0;

    int recursion(TreeNode* root){
        if (root==NULL) return 0;
        int left_side =recursion(root->left);
        int right_side = recursion(root->right);
        diam = max(diam, left_side+right_side);
        return 1+ max(left_side, right_side);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // we have to find the path lengths from the root
        recursion(root);
        return diam;
    }
};