//2476

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
    vector<int> values;
    void recursion(TreeNode* root){
        if (root==nullptr) return;
        recursion(root->left);
        values.push_back(root->val);
        recursion(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector <vector <int>> answers;
        recursion(root);
        int n = values.size();
        int num_queries= queries.size();
        for (int i=0; i<num_queries; i++){
            int a=-1;
            int b = -1;
            auto it = lower_bound(values.begin(), values.end(), queries[i]);
            if (it!=values.end()) b = *it;
            if (it!=values.begin()) a= *(it-1);
            if (it != values.end() && (*it)==queries[i]) a=b=queries[i];
            
            vector <int> answer;
            answer.push_back(a);
            answer.push_back(b);
            answers.push_back(answer);            
        }
        return answers;
    }
};