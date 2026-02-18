#include <stdio.h>
#include <stdlib.h>

typedef struct DLLNode{
    int val;
    struct DLLNode * prev;
    struct DLLNode* next;
}DLLNode;

void deleteNode(DLLNode** head, int val){
    if (*head==NULL) return;
    int found=0; // flag
    DLLNode* behind=NULL;
    DLLNode* temp =* head;
    DLLNode* front = NULL;

    if ((*head)->val==val) {
        *head=(*head)->next;
        if ((*head)!=NULL) (*head)->prev=NULL;
        free(temp);
        return;
    }
    while (found==0 && temp!=NULL){
        if (temp->val==val){
            found=1;
            break;
        } 
        behind=temp;
        temp=temp->next;
        if (temp!=NULL) front=temp->next;
    }
    if (found==0) printf("Value not found.");
    else {
        behind->next=front;
        if (front!=NULL) front->prev=behind;
    }
    free(temp);
}