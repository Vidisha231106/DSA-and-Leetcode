//437

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
class Solution{
public:
    vector<long> path;
    int count=0;
    void recursion(TreeNode* root, int targetSum, long currentSum, vector<long> path, int path_size){
        if (root==nullptr) return;
        currentSum+=root->val;
        long copy= currentSum;
        path.push_back(root->val);
        path_size++;
            int index=0;
            while (index<path_size){
                if (currentSum==targetSum) count++; 
                currentSum-=path[index];
                index++;
            }
        
        recursion(root->left, targetSum, copy, path, path_size);
        recursion(root->right, targetSum, copy, path, path_size);
    }
    int pathSum(TreeNode* root, int targetSum){
        recursion(root, targetSum, 0, path, 0);
        return count;
    }
};