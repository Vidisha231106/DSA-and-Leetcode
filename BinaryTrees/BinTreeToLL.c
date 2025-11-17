/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct LinkedListNode{
    int val; 
    struct LinkedListNode *next;
};
void recursionTree(struct TreeNode* root, struct LinkedListNode** head){
    if (root==NULL){
        return;
    }
    if (root->left==NULL && root->right==NULL){
        struct LinkedListNode* temp = (struct LinkedListNode*) malloc (sizeof(struct LinkedListNode));
        temp->val = root->val;
        temp->next = NULL;
        (*head)->next = temp;
        *head = temp; 
        return;
    }
    recursionTree(root->left, head);
    recursionTree(root->right, head);
}
struct LinkedListNode * flatten(struct TreeNode* root) {
    if (root == NULL) return NULL;
    struct LinkedListNode* head = (struct LinkedListNode*) malloc (sizeof(struct LinkedListNode));
    head->val = root->val;
    head->next = NULL;
    struct LinkedListNode* temp = head;
    recursionTree(root, &temp);
    return head;
}