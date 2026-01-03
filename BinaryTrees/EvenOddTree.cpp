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
    int is_sorted(vector<TreeNode*> level){
        vector <int> values;
        int n = level.size();
        for (int i=0; i<n; i++){
            if (level[i]->val%2==0) return 0;
            values.push_back(level[i]->val);
        }
        vector <int> copy = values;
        sort(copy.begin(), copy.end());
        for (int i =1; i<n; i++){
            if (values[i]==values[i-1]) return 0; // duplicate
        }
        return (copy==values)? 1:0;
    }
    int is_reverse_sorted(vector<TreeNode*> level){
        vector <int> values;
        int n = level.size();
        for (int i=0; i<n; i++){
            if (level[i]->val%2!=0) return 0;
            values.push_back(level[i]->val);
        }
        vector <int> copy = values;
        sort(copy.begin(), copy.end());
        for (int i =1; i<n; i++){
            if (values[i]==values[i-1]) return 0; // duplicate
        }
        reverse(copy.begin(), copy.end());
        return (copy==values)? 1:0;
    }
    bool isEvenOddTree(TreeNode* root) {
        if (root==nullptr) return false;
        vector <vector<TreeNode*>> answer;
        queue <TreeNode*> q;
        q.push(root);
        while (q.empty()==false){
            vector <TreeNode*> level;
            int n = q.size();
            for (int i=0; i<n; i++){
                TreeNode* curr = q.front();
                q.pop();
                level.push_back(curr);
                if (curr->left!=nullptr) q.push(curr->left);
                if (curr->right!=nullptr) q.push(curr->right);
            }
            answer.push_back(level);
        }
        int n= answer.size();
        for (int i=0; i<n; i++){
            int ans = (i%2==0)? is_sorted(answer[i]): is_reverse_sorted(answer[i]);
            if (ans==0) return false; 
        }
        return true;
    }
};