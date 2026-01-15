// 1382
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
    vector <TreeNode*> nodes;
    void recursion (TreeNode* root){
        if (root==nullptr) return;
        recursion(root->left);
        nodes.push_back(root);
        recursion(root->right);
    }
    TreeNode* construct_bst(int left, int right){
        if (left>right) return nullptr;
        int mid = (left+right)/2;
        TreeNode* root= nodes[mid];
        root->left= construct_bst(left, mid-1);
        root->right = construct_bst(mid+1, right);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        recursion(root);
        int num_of_nodes= nodes.size();
        return construct_bst(0, num_of_nodes-1);
    }
};