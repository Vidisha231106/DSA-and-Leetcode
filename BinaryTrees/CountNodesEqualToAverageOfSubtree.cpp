// 2265

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
    int count=0;
    //int sum, int num of nodes
    pair<int, int> recursion(TreeNode* root){
        if (root==nullptr) return {0,0};
        if (root->left==nullptr && root->right==nullptr){
            count++;
            return {root->val, 1};
        }
        pair<int,int> left_side=recursion(root->left);
        pair<int,int> right_side=recursion(root->right);

        int av=(left_side.first+right_side.first+root->val)/(left_side.second+right_side.second+1);
        cout<< root->val<<av<<endl;
        if (av==root->val) count++;

        return {left_side.first+right_side.first+root->val, left_side.second+right_side.second+1};
    }
    int averageOfSubtree(TreeNode* root) {
        recursion(root);
        return count;
    }
};