// 1373

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
    unordered_map <TreeNode*, vector<int>> mp;
    int answer=0;
    void postOrder(TreeNode* root){
        if (root==nullptr) return;
        postOrder(root->left);
        postOrder(root->right);
        if (root->left==nullptr && root->right==nullptr){
            mp[root]={root->val, root->val, root->val, 1}; // 1 here represents bst is valid till this node
            answer=max(answer, root->val);
        }
        else {
            mp[root]={root->val,
                root->left ? min(root->val, mp[root->left][1]) : root->val, 
                root->right ? max(root->val, mp[root->right][2]) : root->val,
                1
            };
            
            if (root->left && mp[root->left][3]==1){
                mp[root][0]+=mp[root->left][0];
            }
            else if (root->left){
                mp[root][3]=0;
            }

            if (root->right && mp[root->right][3]==1){
                mp[root][0]+=mp[root->right][0];
            }
            else if (root->right){
                mp[root][3]=0;
            }

            if (root->left && mp[root->left][2]>=root->val) {
                mp[root][3]=0;
            }
            if (root->right && mp[root->right][1]<=root->val) {
                mp[root][3]=0;
            }
            if (mp[root][3]==1) answer=max(answer, mp[root][0]);
        }
    }
    int maxSumBST(TreeNode* root) {
        if (root==nullptr) return 0;
        postOrder(root);
        return answer;
    }
};