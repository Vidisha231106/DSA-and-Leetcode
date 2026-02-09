// 110

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
    bool flag = true;
    int recursion(TreeNode* root, int dist){
        if (root==nullptr) return 0;
        int left = recursion(root->left, dist+1);
        int right= recursion(root->right, dist+1);
        if (flag==true && abs(right-left)>1) flag=false;
        return 1+ max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if (root==nullptr) return true;
        recursion(root, 0);
        return flag;
    }
};