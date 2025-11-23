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
    void sumCalc(TreeNode* root, vector<int> & distances, int s){
        if (root==NULL){
            return;
        }
        if (root->left==NULL && root->right==NULL) distances.push_back(s);
        if (root->left!=NULL) sumCalc(root->left, distances, s+root->left->val);
        if (root->right!=NULL) sumCalc(root->right, distances, s+root->right->val);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root==NULL) return 0;
        vector <int> distances;
        sumCalc(root, distances, root->val);
        for (int i=0; i<distances.size(); i++) 
            if (distances[i]==targetSum) 
                return true;
        return false;
    }
};