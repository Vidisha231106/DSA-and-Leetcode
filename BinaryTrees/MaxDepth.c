#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int num = 0;
int capacity = 1000;
int *branches;

void one_branch(struct TreeNode* root, int count) {
    if (root == NULL)
        return;

    // Expand array dynamically if needed
    if (num >= capacity) {
        capacity *= 2;
        branches = realloc(branches, capacity * sizeof(int));
    }

    // If it's a leaf, record depth
    if (root->left == NULL && root->right == NULL) {
        branches[num++] = count;
        return;
    }

    if (root->left != NULL)
        one_branch(root->left, count + 1);

    if (root->right != NULL)
        one_branch(root->right, count + 1);
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    // Initialize array dynamically
    capacity = 1000;
    num = 0;
    branches = malloc(capacity * sizeof(int));

    one_branch(root, 1);

    // Find max depth
    int max = branches[0];
    for (int i = 1; i < num; i++) {
        if (branches[i] > max)
            max = branches[i];
    }

    free(branches);
    return max;
}
