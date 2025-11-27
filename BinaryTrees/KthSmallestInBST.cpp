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
    int recursion(TreeNode * root, int &k){
        if (root==NULL) return -1;
        int left = recursion(root->left, k);
        if (left!=-1) return left;
        k--;
        if (k==0) return root->val;
        
        int right = recursion(root->right, k);
        return right;
    }

    int kthSmallest(TreeNode* root, int k) {
        return recursion(root, k);
    }
};