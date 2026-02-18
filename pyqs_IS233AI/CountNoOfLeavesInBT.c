//count the number of leaves in a Binary Tree

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

int numLeavesInBT(TreeNode* root){
    if (root==NULL) return 0;
    if (root->left==NULL && root->right==NULL) return 1;
    return numLeavesInBT(root->left) + numLeavesInBT(root->right);
}

/*
// Helper function to create new node
TreeNode* createNode(int val){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main(){
    // Example tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    int leafCount = countLeaves(root);
    printf("Number of leaves: %d\n", leafCount);
    
    return 0;
}
*/