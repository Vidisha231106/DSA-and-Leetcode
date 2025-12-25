//1261 - Very Inefficient

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
class FindElements {
public:
TreeNode* root;
    FindElements(TreeNode* root) {
        this->root=root;
        if (root!=nullptr) root->val =0;
    }
    
    bool fill_tree(TreeNode* root, int target){
        if (root==nullptr) return false;
        if (root->val==target) return true;
        if (root->left!=nullptr) root->left->val = 2*(root->val) + 1;
        bool left_ans = fill_tree(root->left, target);
        if (root->right!=nullptr) root->right->val = 2*(root->val) + 2;
        bool right_ans=fill_tree(root->right, target);
        if (left_ans || right_ans) return true;
        return false;
    }
    bool find(int target) {
        return fill_tree(root, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */