//572

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
    bool sameTree(TreeNode* root, TreeNode* subRoot){
        if (root==nullptr && subRoot==nullptr) return true;
        if (root==nullptr || subRoot==nullptr) return false;
        bool left_ans=false, right_ans=false;
        if (root->val!=subRoot->val) return false;
        left_ans = sameTree(root->left, subRoot->left);
        right_ans= sameTree(root->right, subRoot->right);
        if (left_ans && right_ans) return true;
        return false;
    }
    bool recursion(TreeNode* root, TreeNode* subRoot){
        if(root==nullptr || subRoot==nullptr) return false;
        bool left_ans=false, right_ans=false;
        if (root->val==subRoot->val){
            if (sameTree(root, subRoot)) return true;
        }
        left_ans= recursion(root->left, subRoot);
        right_ans = recursion(root->right, subRoot);
        
        if (left_ans || right_ans) return true;
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return recursion(root, subRoot);
    }
};