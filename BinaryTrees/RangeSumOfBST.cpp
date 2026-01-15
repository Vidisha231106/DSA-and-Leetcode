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
    int sum=0; 
    void recursion(TreeNode* root, int low, int high){
        if (root==nullptr) return;

        if (low<=root->val && root->val<=high){
            sum+=root->val;
            recursion(root->left, low, high);
            recursion(root->right, low, high);
        }
        else if (root->val<low){
            recursion(root->right, low, high);
        }
        else if (root->val>high){
            recursion(root->left, low, high);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        recursion(root, low, high);
        return sum;
    }
};