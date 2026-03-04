// 687

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
    int answer=0;
    int recursion(TreeNode* root){
        if (root==nullptr) return 0;
        int left_side=recursion(root->left);
        int right_side=recursion(root->right);

        if (root->left!=nullptr && root->left->val==root->val) left_side+=1;
        else left_side=0;
        if (root->right!=nullptr && root->right->val==root->val) right_side+=1;
        else right_side=0;

        answer= max(answer, left_side+right_side);
        return max(left_side, right_side);
    }
    int longestUnivaluePath(TreeNode* root) {
        recursion(root);
        return answer;
    }
};


//BETTER SOL

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
    int answer=0;
    int recursion(TreeNode* root){
        if (root==nullptr) return 0;
        int left_side=recursion(root->left);
        int right_side=recursion(root->right);

        if (root->left!=nullptr && root->left->val==root->val) left_side+=1;
        else left_side=0;
        if (root->right!=nullptr && root->right->val==root->val) right_side+=1;
        else right_side=0;

        answer= max(answer, left_side+right_side);
        return max(left_side, right_side);
    }
    int longestUnivaluePath(TreeNode* root) {
        recursion(root);
        return answer;
    }
};