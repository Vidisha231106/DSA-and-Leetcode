// 2196

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n=descriptions.size();
        unordered_set <int> children;
        for (int i=0; i<n; i++){
            children.insert(descriptions[i][1]);
        }
        TreeNode* root=new TreeNode();
        root->val=0;
        unordered_map <int, TreeNode*> storage;
        for (int i=0; i<n; i++){
            if (children.find(descriptions[i][0])==children.end()){ // root parent
                root->val=descriptions[i][0];
                storage[root->val]=root;
            }
            else if (storage.contains(descriptions[i][0])!=true){ // normal parent
                TreeNode* parent=new TreeNode(descriptions[i][0]);
                storage[parent->val]=parent;
            }
            if (storage.contains(descriptions[i][1])!=true){ // child
                TreeNode* child=new TreeNode(descriptions[i][1]);
                storage[child->val]=child;
                if (descriptions[i][2]==1){
                    storage[descriptions[i][0]]->left=child;
                }
                else{
                    storage[descriptions[i][0]]->right=child;
                }
            }
            else{
                TreeNode* kid=storage[descriptions[i][1]];
                if (descriptions[i][2]==1) storage[descriptions[i][0]]->left=kid;
                else storage[descriptions[i][0]]->right=kid;
            }
        }
        return root;
    }
};