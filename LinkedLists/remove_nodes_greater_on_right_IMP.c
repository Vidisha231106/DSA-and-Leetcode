//2487

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct ListNode* removeNodes(struct ListNode* head) {
    head = reverseList(head);

    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    int maxSoFar = curr->val;

    while (curr) {
        if (curr->val < maxSoFar) {
            // delete curr
            prev->next = curr->next;
        } else {
            maxSoFar = curr->val;
            prev = curr;
        }
        curr = curr->next;
    }

    head = reverseList(head);
    return head;
}


//brute force - O(n^2)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdbool.h>
bool greaterOnRight(struct ListNode* current){
    struct ListNode * temp = current->next;
    while (temp!=NULL){
        if (temp->val > current -> val){
            return true;
        }
        temp= temp->next;
    }
    return false;

}
struct ListNode* removeNodes(struct ListNode* head) {
    struct ListNode * temp2 = head;
    struct ListNode * temp3 = NULL;
    struct ListNode * newHead = head;
    while (temp2!=NULL){
        bool answer = greaterOnRight(temp2);
        if (answer == true){
            //delete node
            if (temp3==NULL){
                newHead = temp2->next;
            }
            else{
                temp3 ->next = temp2->next;
            }
            temp2 = temp2->next;        
        }
        else{
            temp3 = temp2;
            temp2 = temp2->next;        
        }
    }
    return newHead;
}