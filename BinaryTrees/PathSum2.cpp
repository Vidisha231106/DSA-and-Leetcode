//113

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
    vector<vector<int>> answer;
    vector<int> nums;

    void recursion(TreeNode* root, int targetSum, int currentSum, vector<int> n){
        if (root==nullptr) {
            return;
        }
        n.push_back(root->val);
        currentSum+=root->val;
        recursion(root->left, targetSum, currentSum, n);
        recursion(root->right, targetSum, currentSum, n);

        if (currentSum==targetSum && (root->left==nullptr && root->right==nullptr)){
            answer.push_back(n);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root==nullptr) return answer;
        recursion(root, targetSum, 0, nums);
        return answer;
    }
};