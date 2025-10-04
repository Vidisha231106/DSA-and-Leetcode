#include <stdio.h>
#include <stdlib.h>

struct queue_element{
    int data;
    struct queue_element* next;
};

struct queue_element* createLLNode(int value){
    struct queue_element * new_node = (struct queue_element *)malloc(sizeof(struct queue_element));
    new_node->next= NULL;
    new_node->data = value;
    return new_node;
}

void push_element(struct queue_element **head, int value, int *count){
    struct queue_element *temp = *head;
    while (temp->next !=NULL){
        temp = temp->next;
    }
    struct queue_element *new_element = createLLNode (value);
    temp->next = new_element;
    (*count)++;
}

int pop_element(struct queue_element **head, int *count){
    if (*head == NULL){
        printf("Queue Underflow!\n");
    }
    struct queue_element *temp = *head;
    int value = temp->data;

    *head=temp->next;
    free(temp);
    (*count)--;

    return value;
}

void display_front (struct queue_element *head){
    if (head == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Front: %d\n", head->data);
}

void display_queue (struct queue_element *head){
    if (head == NULL){
        return;
    }
    struct queue_element *temp = head;
    while (temp!= NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main (){
    int size;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    int count =1;
    printf("Enter the elements of the stack, starting from the front element: ");

    int value;
    scanf("%d", &value);
    struct queue_element *head = createLLNode(value);

    for (int i =1; i<size; i++){
        scanf("%d", &value);
        push_element(&head, value, &count);
    }

    display_queue(head);
    printf("\n");
    display_front(head);

    printf("Popped element: %d\n", pop_element(&head, &count));
    display_queue(head);
    printf("\n");
    display_front(head);
    
    return 0;
}