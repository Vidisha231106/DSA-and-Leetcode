// 9 
// Binary Tree Operations - 
// creating a tree, displaying the tree, counting the number of nodes, counting the number of leaf nodes

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* createNode(int value){
    TreeNode* root= (TreeNode*) malloc(sizeof(TreeNode));
    root->val = value;
    root->left= NULL;
    root->right= NULL;
    return root;
}

TreeNode* createTree(){
    int value;
    printf("Enter the node value: ");
    scanf("%d", &value);

    if (value==-1) return NULL;
    TreeNode* new_node = (TreeNode*) malloc (sizeof(TreeNode));
    new_node->val=value;

    printf("\nLeft node value of %d: ", value);
    new_node->left= createTree();
    printf("\nRight node value of %d: ", value);
    new_node->right= createTree();
    return new_node;
}

void displayTree(TreeNode* root){
    if (root==NULL) return;
    printf("%d ", root->val);
    displayTree(root->left);
    displayTree(root->right);
}

int countNodes(TreeNode* root){
    if (root==NULL) return 0;
    int left = countNodes(root->left);
    int right=countNodes(root->right);
    return 1+left+right;
}

int countLeafNodes(TreeNode* root){
    if (root==NULL) return 0;
    if (root->left==NULL && root->right==NULL) {
        return 1;
    }
    int left =countLeafNodes(root->left);
    int right=countLeafNodes(root->right);
    return left+right;
}

int main(){
    TreeNode* root = createTree();
    displayTree(root);
    printf("Number of nodes = %d\n", countNodes(root));
    printf("Number of leaf nodes = %d\n", countLeafNodes(root));
    return 0;
}