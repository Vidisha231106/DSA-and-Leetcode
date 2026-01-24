//105 - Inefficient but simple logic

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
    TreeNode* recursion(vector <int> inorder, vector<int> preorder, int root_i, int left_i, int right_i, int p){
        if (left_i>right_i || p>=preorder.size()) return nullptr;
        TreeNode* new_node = new TreeNode(preorder[p]);
        int left_size = root_i-left_i;
        if (p+1<preorder.size()){
            for (int i=0; i<root_i; i++){
                if (inorder[i]==preorder[p+1]){
                    new_node->left = recursion(inorder, preorder, i, left_i, root_i-1, p+1);
                    break;
                }
                    
            }
        }
        if (p+1+left_size <preorder.size()){
            for (int i=root_i+1; i<=right_i; i++){
                if (inorder[i]==preorder[p+1+left_size]){
                    new_node->right= recursion(inorder, preorder, i, root_i+1, right_i, p+1+left_size);
                    break;
                }
                    
            }
        }
        return new_node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i=0; i<n; i++){
            if (inorder[i]==preorder[0]){
                return recursion(inorder, preorder, i, 0, n-1, 0);
            }
        }        
        return nullptr;
    }
};