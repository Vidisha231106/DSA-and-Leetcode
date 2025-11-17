// 114. Flatten Binary Tree to Linked List
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void recursionTree(struct TreeNode* root, struct TreeNode** head){
    if (root==NULL){
        return;
    }
    (*head)->left = NULL;
    (*head)->right = root;
    *head = root;
    struct TreeNode * temp = root->right;
    recursionTree(root->left, head);
    recursionTree(temp, head);
    root->left = NULL;
}
void flatten(struct TreeNode* root) {
    if (root == NULL) return;
    struct TreeNode temp;
    // I didnt get this in first try - BE CAREFUL WITH POINTERS
    temp.left = NULL;
    temp.right = NULL;
    struct TreeNode* head = &temp;
    recursionTree(root, &head);
}