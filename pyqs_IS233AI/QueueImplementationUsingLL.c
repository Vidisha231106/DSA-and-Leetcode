//Queue Implementation using LL - enqueue, dequeue, display front, display back

#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int val;
    struct Node* next;
}Node;

void Enqueue(Node** head, int val){
    Node* new_element = (Node* ) malloc (sizeof(Node));
    new_element->val = val;
    new_element->next=NULL;

    if (*head==NULL){
        head= new_element;
        return;
    }

    Node* temp = *head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp ->next = new_element;
}

int Dequeue (Node** head){
    int value = (*head)->val;
    Node* temp = *head;
    (*head)=(*head)->next;
    free(temp);
    return value;
}

void displayFront(Node* head){
    if (head==NULL){
        printf("Queue is empty! Underflow!");
        return;
    }
    printf("Front: %d", (head)->val);
}

void displayRear(Node* head){
    if (head==NULL){
        printf("Queue is empty! Underflow!");
        return;
    }
    Node* temp = head;
    while (temp->next!=NULL) temp=temp->next;
    printf("Rear: %d", temp->val);
}

/*
int main(){
    Node* queue = NULL;
    
    // Enqueue elements
    Enqueue(&queue, 10);
    Enqueue(&queue, 20);
    Enqueue(&queue, 30);
    Enqueue(&queue, 40);
    
    printf("After enqueuing 10, 20, 30, 40:\n");
    displayFront(queue);
    displayRear(queue);
    
    // Dequeue elements
    printf("\nDequeued: %d\n", Dequeue(&queue));
    printf("Dequeued: %d\n", Dequeue(&queue));
    
    printf("\nAfter dequeuing:\n");
    displayFront(queue);
    displayRear(queue);
    
    // Enqueue more
    Enqueue(&queue, 50);
    printf("\nAfter enqueuing 50:\n");
    displayFront(queue);
    displayRear(queue);
    
    return 0;
}
*/