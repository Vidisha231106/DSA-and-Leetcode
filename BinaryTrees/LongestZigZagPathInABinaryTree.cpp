// 1372

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
    //-1 ->left, 1->right;
    int answer=0;
    void dfs(TreeNode* node, int curr, int dir){
        if (node==nullptr) return;
        answer=max(curr, answer);
        if (dir==-1) dfs(node->right, curr+1, 1);
        if (dir==-1) dfs(node->left, 1, -1);
        if (dir==1) dfs(node->left, curr+1, -1);
        if (dir==1) dfs(node->right, 1, 1);
    }
    int longestZigZag(TreeNode* root) {
        dfs(root, 0, -1);
        dfs(root, 0, 1);
        return answer;
    }
};