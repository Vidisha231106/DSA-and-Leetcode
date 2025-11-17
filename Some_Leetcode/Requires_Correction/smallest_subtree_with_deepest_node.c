//865

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* findSubtree(struct TreeNode* root, struct TreeNode* deepest, int *tallest){
    if (root==NULL){
        return NULL;
    }
    if (root!=NULL && root->left!=NULL && root->right!=NULL && root->left->left==NULL && root->left->right==NULL && root->right->left==NULL && root->right->right==NULL){
        deepest = root;
    }
    (*tallest)+=1;
    root = findSubtree(root->left, deepest, tallest);
    root = findSubtree(root->right, deepest, tallest);
    return deepest;
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    int height = 0;
    return findSubtree(root, root, &height);
}