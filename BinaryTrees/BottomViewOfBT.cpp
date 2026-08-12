// Strivers Sheet

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
  public:
    vector <int> bottomView(TreeNode *root){
    	//your code goes here
        map <int, int> positions;
        queue<pair<TreeNode*,int>> q;
        if (root==nullptr) return {};
        q.push({root, 0});
        while (q.empty()!=true){
            pair <TreeNode*, int> p=q.front();
            q.pop();
            positions[p.second]=p.first->data;
            if (p.first->left) q.push({p.first->left, p.second-1});
            if (p.first->right) q.push({p.first->right, p.second+1});
        }
        vector<int> answer;
        for (auto it: positions){
            answer.push_back(it.second);
        }
        return answer;
    }
};