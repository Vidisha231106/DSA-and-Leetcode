//530

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
    void abs_diff(TreeNode* root, vector <int>& arr){
        if (root==nullptr) return;
        
        abs_diff(root->left, arr);
        arr.push_back(root->val);
        abs_diff(root->right, arr);
    }
    int getMinimumDifference(TreeNode* root) {
        if (root==nullptr || (root->left==nullptr && root->right==nullptr)){
            return 0;
        }
        vector <int> arr;
        abs_diff(root, arr);
        int smallest_diff=INT_MAX;
        int n= arr.size();
        for (int i=0; i<n-1; i++){
            if (arr[i+1]-arr[i]<smallest_diff) smallest_diff= arr[i+1]-arr[i];
        }
        return smallest_diff;
    }
};