// Strivers sheet - not in leetcode

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
    vector<int> topView(TreeNode *root){
        //your code goes here
        vector<int> answer;
        TreeNode* curr=root->left;
        while (curr!=nullptr){
            answer.push_back(curr->data);
            curr=curr->left;
        }
        reverse(answer.begin(), answer.end());
        curr=root;
        while (curr!=nullptr){
            answer.push_back(curr->data);
            curr=curr->right;
        }
        return answer;

    }
};