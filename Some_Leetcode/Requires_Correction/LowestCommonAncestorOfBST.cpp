//235

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector <vector<TreeNode*>> answer;
    vector <TreeNode*> p_nodes;
    vector <TreeNode*> q_nodes;

    void recursion(TreeNode* root, TreeNode* node, vector <TreeNode*> arr){
        if (root==nullptr) return;
        arr.push_back(root);
        if (root==node) {
            arr.push_back(node);
            answer.push_back(arr);
            return;
        }
        recursion(root->left, node, arr);
        recursion(root->right, node, arr);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recursion(root, p, p_nodes);
        recursion(root, q, q_nodes);
        p_nodes = answer[0];
        q_nodes=answer[1];
        int n_p = p_nodes.size();
        int n_q= q_nodes.size();
        for (int i=0; i<min(n_p, n_q); i++){
            if (p_nodes[i]!=q_nodes[i]) return p_nodes[i-1];
        }
        return root;
    }
};