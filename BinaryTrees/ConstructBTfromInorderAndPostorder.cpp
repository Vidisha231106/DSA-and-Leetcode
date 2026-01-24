//106

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
    unordered_map <int, int> indices;
 
    TreeNode* recursion(vector <int>& inorder, vector<int>& postorder, int left_i, int right_i, int &p){
        if (left_i>right_i || p<0) return nullptr;
        TreeNode* new_node = new TreeNode(postorder[p]);

        int root_i = indices[postorder[p]];
        p--;
        new_node->right = recursion(inorder, postorder, root_i+1, right_i, p);
        new_node->left= recursion(inorder, postorder, left_i, root_i-1, p);
        return new_node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();

        for (int i=0; i<n; i++){
            indices[inorder[i]]=i;
        }
        int p = n-1;
        return recursion(inorder, postorder, 0, n-1, p);    
    }
};