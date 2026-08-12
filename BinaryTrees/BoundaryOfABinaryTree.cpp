// 545

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
public:
    vector<int> bottom;
    vector<int> right_boundary;
    vector<int> left_boundary;

    void dfs(TreeNode* root){
        if (root==nullptr)return;
        if (root->left==nullptr && root->right==nullptr) {
            bottom.push_back(root->data);
            return;
        }
        dfs(root->left);
        dfs(root->right);
    }
    vector <int> boundary(TreeNode* root){
        if (root->left==nullptr && root->right==nullptr) 
            return {root->data};
        TreeNode* temp=root->left;
        left_boundary.push_back(root->data);        
        while (temp!=nullptr){
            if (temp->left!=nullptr && temp->right!=nullptr) 
                left_boundary.push_back(temp->data);
            temp=(temp->left!=nullptr)? temp->left: temp->right;
        }
        temp=root->right;
        while (temp!=nullptr){
            if (temp->left!=nullptr && temp->right!=nullptr) 
                right_boundary.push_back(temp->data);
            temp=(temp->right!=nullptr)? temp->right: temp->left;
        }
        reverse(right_boundary.begin(), right_boundary.end());
        dfs(root);
        vector<int> answer;
        for (auto it: left_boundary) answer.push_back(it);
        for (auto it: bottom) answer.push_back(it);
        for (auto it: right_boundary) answer.push_back(it);
        return answer;
    }
};