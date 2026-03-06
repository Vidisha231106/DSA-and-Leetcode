// 662

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
    int widthOfBinaryTree(TreeNode* root) {
        long long width =0;
        if (root==nullptr) return width;
        queue <pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while (q.empty()!=true){
            long long size = q.size();
            long long minIndex=q.front().second;
            long long beginning=0;
            long long ending=0;
            for (int i=0; i<size; i++){
                long long curr = q.front().second-minIndex;
                TreeNode* node= q.front().first;
                if (i==0) beginning = curr;
                if (i==size-1) ending = curr;
                q.pop();
                if (node->left!=nullptr) q.push({node->left, 2*curr+1});
                if (node->right!=nullptr) q.push({node->right, 2*curr+2});
            }
            width = max(width, ending-beginning+1);
        } 
        return width;
    }
};