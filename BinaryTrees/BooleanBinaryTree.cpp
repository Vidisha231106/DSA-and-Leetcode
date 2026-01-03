//2331

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
    vector <int> answer;

    void recursion(TreeNode* root){
        if (root==nullptr) return;
        recursion(root->left);
        recursion(root->right);
        answer.push_back(root->val);
    }
    bool evaluateTree(TreeNode* root) {
        if (root==nullptr) return false;
        if (root->left==nullptr && root->right==nullptr) return root->val; 
        recursion(root);
        stack <int> st;
        int n= answer.size();
        int op1, op2, result;
        for (int i=0; i<n; i++){
            if (answer[i]==0 || answer[i]==1) st.push(answer[i]);
            else if (answer[i]==2){
                op1=st.top();
                st.pop();
                op2 =st.top();
                st.pop();
                result = (op1 || op2) ? 1: 0;
                st.push(result);
            }
            else {
                op1=st.top();
                st.pop();
                op2 =st.top();
                st.pop();
                result = (op1 && op2) ? 1: 0;
                st.push(result);
            }
        }
        return (result)? true: false;
    }
};