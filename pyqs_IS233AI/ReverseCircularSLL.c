#include <stdio.h>
#include <stdlib.h>

// THIS IS A CIRCULAR LL, NOT A DLL

typedef struct Node{
    int val;
    struct Node* next;
}Node;

void insertNode(Node** head, int val){
    Node* new_node= (Node* ) malloc (sizeof(Node));
    new_node->val=val;
    if ((*head)==NULL){
        *head=new_node; 
        new_node->next=*head;
        return;
    }
    Node* temp  = *head;
    while (temp->next!=*head) temp=temp->next;
    temp->next = new_node;
    new_node->next=*head;
}

void reverseCircularLL(Node** head){
    if (*head==NULL || (*head)->next==*head) return;
    Node* behind=NULL;
    Node* temp = *head;
    Node* front=NULL;
    Node* original_head = *head;
    
    do {
        front=temp->next;
        temp->next = behind;
        behind= temp;
        temp=front;
    } while (temp!=original_head);
    (*head)->next=behind;
    (*head)=behind;
}

/*
int main(){
    Node* head = NULL;
    
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    
    printf("Original Circular Linked List: ");
    display(head);
    
    reverseCircularLL(&head);
    
    printf("Reversed Circular Linked List: ");
    display(head);
    
    return 0;
}*/