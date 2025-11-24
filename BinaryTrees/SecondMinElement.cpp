//671. Second Min Element in a Binary Tree - BRUTE FORCE - my solution
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
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> node_values;
        int smallest=root->val;
        queue <TreeNode *> q;
        q.push(root);
        while (q.empty()!=true){
            TreeNode * current = q.front();
            q.pop();
            if (current->val<smallest) smallest=current->val;
            node_values.push_back(current->val);
            if (current->left!=NULL) q.push(current->left);
            if (current->right!=NULL) q.push(current->right);
        }
        node_values.erase(remove(node_values.begin(), node_values.end(), smallest), node_values.end());

        if (node_values.empty()==true) return -1;
        int second_smallest=*min_element(node_values.begin(), node_values.end());
        
        return second_smallest;
    }
};


//OPTIMAL APPROACH

class Solution2 {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        return dfs(root, root->val);
    }

    int dfs(TreeNode* node, int smallest) {
        if (!node) return -1;
        if (node->val > smallest) return node->val;  // found candidate

        int left = dfs(node->left, smallest);
        int right = dfs(node->right, smallest);

        if (left == -1) return right;
        if (right == -1) return left;
        return min(left, right);  // pick smaller of two valid candidates
    }
};
