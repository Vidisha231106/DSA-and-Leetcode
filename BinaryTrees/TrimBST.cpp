//669

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
    TreeNode* lesserThanLow(TreeNode* root, int low){
        if (root==nullptr) return nullptr;
        if (root->val<low){
            return lesserThanLow(root->right, low);
        }
        root->left = lesserThanLow(root->left, low);
        return root;
    }
    TreeNode* greaterThanHigh(TreeNode* root, int high){
        if (root==nullptr) return nullptr;
        if (root->val>high){
            return greaterThanHigh(root->left, high);
        }
        root->right = greaterThanHigh(root->right, high);
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root->val<low && root->right!=nullptr) root = trimBST(root->right, low, high);
        if (root->val>high && root->left!=nullptr) root = trimBST(root->left, low, high);

        
        if (root->left==nullptr && root->right==nullptr  && (root->val>high || root->val<low)) return nullptr;
        if (root==nullptr || (root->left==nullptr && root->right==nullptr)) return root;
        if (root->left!=nullptr) root->left = lesserThanLow(root->left, low);
        if (root->right!=nullptr) root->right = greaterThanHigh(root->right, high);
        return root;
    }
};