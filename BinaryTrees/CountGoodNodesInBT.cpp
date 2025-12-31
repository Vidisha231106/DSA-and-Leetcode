//1448

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void recursion(TreeNode* root, int min, int& count) {
        if (root == nullptr) return;
        if (root->val >= min) count++;
        int n = max(root->val, min);
        
        if (root->left != nullptr) {
            recursion(root->left, n, count);
        }
        if (root->right != nullptr) {
            recursion(root->right, n, count);
        }
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        recursion(root, root->val, count);
        return count;
    }
};