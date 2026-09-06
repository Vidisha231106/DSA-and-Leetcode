// 993

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
    int x_parent=0;
    int x_h=0;
    int y_h=0;
    int y_parent=0;
    void recursion(TreeNode* node, int x, int y, int height, int parent){
        if (node==nullptr) return;
        if (node->val==x){
            x_parent=parent;
            x_h=height;
            
        } 
        if (node->val==y){
            y_parent=parent;
            y_h=height;
            
        }
        recursion(node->left, x, y, height+1, node->val);
        recursion(node->right, x, y, height+1, node->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        recursion(root, x, y, 0, -1);
        cout<<x<<" is of height: "<<x_h<<endl;
        cout<<y<<" is of height: "<<y_h;
        return (x_h==y_h) && !(x_parent==y_parent);
    }
};