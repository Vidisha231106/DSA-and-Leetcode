//237

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void deleteNode(struct ListNode* node) {
    struct ListNode * temp1 = node;
    struct ListNode * temp2 = node->next;
    struct ListNode * prev = NULL;
    while (temp2!= NULL){
        temp1->val = temp2->val;
        prev = temp1;
        temp1 = temp2;
        temp2 = temp2->next;
    } 
    prev->next = NULL;
    free (temp2);
}