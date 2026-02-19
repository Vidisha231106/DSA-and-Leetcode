
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

/* Create new node */
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* Insert into BST */
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

/* Inorder traversal (prints sorted order) */
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Tree Sort */
void treeSort(int arr[], int n) {
    struct Node* root = NULL;

    /* Build BST */
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    /* Print sorted elements */
    printf("Sorted elements:\n");
    inorder(root);
}

int main() {
    int arr[] = {7, 3, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    treeSort(arr, n);

    return 0;
}
