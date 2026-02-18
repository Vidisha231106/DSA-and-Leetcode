// 10
//BST Operations - creating a tree, inserting a  node, deleting a node, displaying the tree

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* createNode(int val){
    TreeNode* root = (TreeNode*) malloc (sizeof(TreeNode));
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}

TreeNode* insertNode(TreeNode* root, int value){
    if (root==NULL) return createNode(value);
    TreeNode* temp = root;
    if (root->val>value){
        root->left= insertNode(root->left, value);
    }
    else if (root->val<value){
        root->right= insertNode(root->right, value);
    }
    return root;
}

TreeNode* findMinNode(TreeNode* root){
    if (root==NULL) return NULL;
    while (root->left!=NULL) root=root->left;
    return root;
}

void displayTreeDFS(TreeNode* root){
    if (root==NULL) return;
    printf("%d ", root->val);
    displayTreeDFS(root->left);
    displayTreeDFS(root->right);
}

TreeNode* deleteNode(TreeNode* root, int value){
    if (root==NULL) return NULL;
    if (value<root->val){
        root->left= deleteNode(root->left, value);
        return root;
    }
    else if (value>root->val){
        root->right= deleteNode(root->right, value);
        return root;
    }
    if (root->left==NULL){
        TreeNode* temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right==NULL){
        TreeNode* temp = root->left;
        free(root);
        return temp;
    }
    else{
        TreeNode* temp = findMinNode(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
        return root;
    }

}

int main(){
    TreeNode* root= createNode(7);
    root= insertNode(root, 3);
    root= insertNode(root, 4);
    root= insertNode(root, 5);
    root= insertNode(root, 8);
    root= insertNode(root,9);
    root= insertNode(root,1);
    root= insertNode(root,10);
    root= insertNode(root,6);
    displayTreeDFS(root);
    printf("\n");
    root = deleteNode(root, 9);
    root = deleteNode(root, 1);
    root = deleteNode(root, 3);
    displayTreeDFS(root);
    return 0;
}