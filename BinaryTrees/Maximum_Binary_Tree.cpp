//654. Maximum Binary Tree

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

#include <algorithm>
class Solution {
public:
    TreeNode* recursion(vector<int> &nums, int left, int right){
        if (left>right) return nullptr;
        int max_index=left;
        for (int i=left; i<right+1; i++){
            if (nums[i]>nums[max_index]) max_index=i;
        }
        TreeNode * root = new TreeNode (nums[max_index]);
        root->left = recursion(nums, left, max_index-1);
        root->right = recursion(nums, max_index+1, right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size()==0) return nullptr;
        TreeNode * root = recursion(nums, 0, nums.size()-1);
        return root;        
    }
};