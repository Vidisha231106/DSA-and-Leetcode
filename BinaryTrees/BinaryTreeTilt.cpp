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
    int recursion(TreeNode* root, int &total){
        if (root==nullptr) return 0;
        int x = recursion(root->left, total);
        int y= recursion(root->right, total);
        total+=abs(x-y);
        return root->val+x+y;
    }
    
    int findTilt(TreeNode* root) {
        if (root==nullptr) return 0;
        int total=0;
        recursion(root, total);
        return total; 
    }
};