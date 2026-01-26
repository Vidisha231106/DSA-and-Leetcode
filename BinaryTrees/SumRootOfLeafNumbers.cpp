//129

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
    vector <int> nums;
    void recursion(TreeNode* root, int num){
        if (root->left==nullptr && root->right==nullptr){
            nums.push_back(num);
            return;
        } 
        if (root->left!=nullptr) recursion(root->left, num*10+ (root->left->val));
        if (root->right!=nullptr)recursion(root->right, num*10+ (root->right->val));
    }
    int sumNumbers(TreeNode* root) {
        recursion(root, root->val);
        int n= nums.size();
        int sum=0;
        for (int i=0; i<n; i++){
            sum+=nums[i];
        }
        return sum;
    }
};