// 513

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
    int max_distance = -1;
    int max_left_node_val = 0;

    void rec_left_tree(TreeNode* root, int dist) {
        if (root == nullptr)
            return;
        if (dist > max_distance) {
            max_left_node_val = root->val;
            max_distance = dist;
        }
        rec_left_tree(root->left, dist + 1);
        rec_left_tree(root->right, dist + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr)return 0;
        rec_left_tree(root, 0);
        return max_left_node_val;
    }
};