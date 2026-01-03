//1110

//IMPORTANT - Set has been used here to check if element exists in vector to_delete

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
    vector <TreeNode*> answer;
    unordered_set <int> my_set;

    TreeNode* recursion(TreeNode* root){
        if (root==nullptr) return nullptr;
        root->left = recursion(root->left);
        root->right=recursion(root->right);
        if (my_set.count(root->val)==1){
            if (root->left!=nullptr) answer.push_back(root->left);
            if (root->right!=nullptr) answer.push_back(root->right);
            return nullptr;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        my_set = unordered_set(to_delete.begin(), to_delete.end());
        TreeNode* result = recursion(root);
        if (result!=nullptr) answer.push_back(result);
        return answer;
    }
};