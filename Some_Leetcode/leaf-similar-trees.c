// 872 Leaf Similar Trees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void treeLeaf(struct TreeNode* root, int * arr, int * index){
    if (root == NULL) return;
    if (root->left==NULL && root->right==NULL){
        arr[(*index)++] = root->val;
    }
    treeLeaf(root->left, arr, index);
    treeLeaf(root->right, arr, index);
}
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    struct TreeNode* temp = root1;
    int * arr1 = (int *) malloc (sizeof(int)* 1000);
    int * arr2 = (int *) malloc (sizeof(int)* 1000);
    int idx1=0;
    int idx2=0;
    treeLeaf(root1, arr1, &idx1);
    treeLeaf(root2, arr2, &idx2);
    if (idx1 != idx2) return false;
    int flag=1; //1 when same, 0 when diff
    int i;
    while (i<idx1){
        if (arr1[i]!=arr2[i]) flag=0;
        i++;
    }
    if (flag==0) return false;
    return true;
}