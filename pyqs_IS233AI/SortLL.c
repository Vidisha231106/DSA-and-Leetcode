// Sort a Singly Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

// Find middle

Node* getMiddle(Node* head){
    if (head==NULL) return head;
    Node* slow = head;
    Node* fast = head->next;

    while (fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

// Merge Sort

Node* mergeSort(Node* head){
    if (head==NULL || head->next==NULL) return head;
    Node* middle = getMiddle(head);
    Node* secondHead= middle->next;
    middle->next=NULL;

    Node* left= mergeSort(head);
    Node* right = mergeSort(secondHead);
    return mergeLists(left, right);
}

// Merge Sorted Lists

Node* mergeLists(Node* left, Node* right){
    if (left==NULL) return right;
    if (right==NULL) return left;

    Node* result = NULL;
    
    if (left->val<=right->val){
        result=left;
        result->next=mergeLists(left->next, right);
    }
    else{
        result=right;
        result->next=mergeLists(left, right->next);
    }
    return result;
}
