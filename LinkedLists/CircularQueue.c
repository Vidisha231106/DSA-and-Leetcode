#include <stdio.h>
#include <stdlib.h>

//implementation of circular queue using linked lists

#define QUEUE_SIZE 6

struct ListNode {
    int val;
    struct ListNode* next;  
};

struct CircularQueue{
    struct ListNode* front;
    struct ListNode* rear;
    int size;
};

struct CircularQueue* initialiseQueue(){
    struct CircularQueue* q = (struct CircularQueue*) malloc (sizeof(struct CircularQueue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(struct CircularQueue* q, int val){
    if (q->size == QUEUE_SIZE){
        printf("Queue is full, OverFlow!");
        return;
    }
    struct ListNode* newNode = (struct ListNode*) malloc (sizeof(struct ListNode));
    
    newNode->val = val;
    
    if (q->front==NULL){
        q->front = newNode;
        q->rear = newNode;
        newNode->next = q->front;
    }
    else{
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear= newNode;
    }
    q->size++;
}

void dequeue(struct CircularQueue* q){
    if (q->size==0){
        printf("Queue is empty, Underflow condition!");
    }
    struct ListNode* temp = q->front;
    if (q->front==q->rear){
        free(q->front);
        q->front=NULL;
        q->rear=NULL;
    }
    else{
        q->front= q->front->next;
        q->rear->next = q->front;
    }
    q->size--;
    printf("Value of dequeued element: %d", temp->val);
    free(temp);
}

void printQueue(struct CircularQueue * q){
    if (q->size==0) {
        printf("Queue is empty. \n");
        return;
    }
    struct ListNode* temp = q->front;
    printf("Circular Queue: ");
    while (temp->next!=q->front){
        printf("%d -> ", temp->val);
        temp=temp->next;
    }
    printf("%d", q->rear->val);
}

int main() {
    struct CircularQueue* queue = initialiseQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);  
    enqueue(queue, 70);
    printf("\n");  
    printQueue(queue);
    printf("\n");
    dequeue(queue);
    printf("\n");
    printQueue(queue);
    printf("\n");
    enqueue(queue, 80);
    enqueue(queue, 90);
    printQueue(queue);
    printf("\n");
    return 0;
}