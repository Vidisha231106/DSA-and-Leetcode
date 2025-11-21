//1669 - Merge in between two linked lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode * head = list1;
    struct ListNode *tail = list2;
    struct ListNode *before_start;
    struct ListNode *after_end;
    //Convert a and b into values at those indices rather than having them as the node number
    int counter =0;
    while (list1!=NULL){
        if (counter==a-1) before_start= list1;
        if (counter==b-1){
            after_end = list1->next;
            list1->next=NULL;
        } 
        counter++;
        list1=list1->next;
    }
    before_start->next=list2;
    while (list2->next!=NULL){
        list2=list2->next;
    }
    list2->next = after_end->next;
    return head;
}