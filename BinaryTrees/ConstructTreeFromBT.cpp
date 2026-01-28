//606

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

    string recursion(TreeNode* root){
        if (root==nullptr) return "";
        if (root->left==nullptr && root->right==nullptr) return to_string(root->val);
        string left_child=recursion(root->left);
        string right_child=recursion(root->right);
        if (right_child!="") return to_string(root->val)+"("+left_child+")"+"("+right_child+")";
        return to_string(root->val)+"("+left_child+")";
    }
    string tree2str(TreeNode* root) {
        string ans= recursion (root);
        return ans;
    }
};