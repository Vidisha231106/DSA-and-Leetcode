bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    // Base cases
    if (left == NULL && right == NULL)
        return true;
    if (left == NULL || right == NULL)
        return false;

    // Check current node values and recursive symmetry
    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;
    return isMirror(root->left, root->right);
}