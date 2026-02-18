// Program to detect cycle in LL

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
} ListNode;

bool isCyclePresent(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast = fast->next->next;
        if (slow==fast) return true;
    }
    return false;
}

int main(){
    ListNode* node1 = (ListNode* ) malloc (sizeof(ListNode));
    node1->val = 1;
    ListNode* node2 = (ListNode*) malloc (sizeof(ListNode));
    node2->val = 2;
    node1->next = node2;
    ListNode* node3 = (ListNode*) malloc (sizeof(ListNode));
    node3->val=3;
    node2->next = node3;
    node3->next=NULL;
    printf("Cycle present (before): %s\n", isCyclePresent(node1) ? "Yes" : "No");
    node3->next = node2;
    printf("Cycle present (after): %s\n", isCyclePresent(node1) ? "Yes" : "No");
    return 0;
}