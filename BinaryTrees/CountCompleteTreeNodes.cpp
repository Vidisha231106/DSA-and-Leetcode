//222

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
    int leftSide(TreeNode* root){
        int h=0;
        while (root!=nullptr){
            root=root->left;
            h++;
        }
        return h;
    }
    int rightSide(TreeNode* root){
        int h=0;
        while (root!=nullptr){
            root=root->right;
            h++;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if (root==nullptr) return 0;
        int left_side = leftSide(root);
        int right_side = rightSide(root);
        if (left_side==right_side) return pow(2, left_side) -1;
        return 1 + countNodes(root->left) +countNodes(root->right);
    }
};