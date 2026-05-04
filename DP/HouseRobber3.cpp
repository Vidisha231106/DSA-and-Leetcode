// 337

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
    pair<int, int> recursion(TreeNode* root){
        if (root==NULL) return {0,0};
        pair<int, int> left_side= recursion(root->left);
        pair<int, int> right_side= recursion(root->right);
        int root_not_taken = max(left_side.first, left_side.second) + max(right_side.first, right_side.second);
        int root_taken = root->val + left_side.second + right_side.second;
        return {root_taken, root_not_taken};
    }
    int rob(TreeNode* root) {
        pair<int, int> answer = recursion(root);
        return max(answer.first, answer.second);
    }
};