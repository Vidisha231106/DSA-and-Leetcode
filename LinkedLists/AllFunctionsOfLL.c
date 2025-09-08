//LinkedList Practice:

/*Only pass struct Node **head if you're modifying the head (e.g., inserting/deleting at the beginning). For printing, just pass struct Node *head.*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *createNode (int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next=NULL;
    newNode->data=value;
    return newNode;
}

void insertAtBeginning(struct Node **head, int value){
    //ll is empty
    if (*head==NULL){
        return;
    }
    struct Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node **head, int value){
    struct Node *newNode = createNode(value);

    //ll is empty
    if (*head==NULL){
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void insertAtIndex(struct Node **head, int value, int index){
    if (index ==0){
        insertAtBeginning(head, value);
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data=value;
    
    int count=0;
    struct Node *temp = *head;
    while (temp != NULL && count < index - 1){
        temp=temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Index out of bounds\n");
        free(newNode); // Avoid memory leak
        return;
    }
    newNode->next = temp->next;
    temp->next=newNode;
}

void displayCountNodes(struct Node *head){
    int count =0;
    struct Node *temp= head;
    while (temp!=NULL){
        count++;
        temp = temp->next;  
    }
    printf("Number of nodes in LL = %d", count);
}

void displayCountBasedOnValue(struct Node *head, int value){
    struct Node *temp = head;
    int count=0;
    while (temp!=NULL){
        if (temp->data == value){
            count++;
        }
        temp = temp->next; 
    }
    printf("Number of nodes in LL with value %d = %d", value, count);
}

void printLinkedList(struct Node *head){
    struct Node *temp = head;
    while (temp->next!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    } 
    printf("%d", temp->data);
}

void deleteBeginning(struct Node **head){
    if (*head==NULL){
        return;
    }
    struct Node *temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteEnd(struct Node **head){

    //case-1: if ll is empty
    if (*head==NULL){
        return;
    }

    struct Node *temp = *head;
    //case-2: if ll has only one node
    if (temp->next==NULL){
        free(temp);
        *head=NULL;
    }

    while (temp->next->next !=NULL){
        temp=temp->next;
    }
    //temp points to the second-last element
    free(temp->next);
    temp->next=NULL;

    /*this logic is wrong since second last node should be updated to point to null:-
    
    while (temp->next!=NULL){
        temp=temp->next;
    }
    free(temp);
    temp=NULL;
    */
}

void deleteAtIndex(struct Node **head, int index){
    if (index==0){
        deleteBeginning(head);
        return;
    }
    struct Node *temp= *head;
    int count=0;
    while (temp->next!=NULL && count<(index-1)){
        temp=temp->next;
        count++;
    }
    
    if (temp==NULL || temp->next==NULL){
        printf("Index out of bounds\n");
        return;
    }
    struct Node *toDelete = temp->next;
    temp->next=toDelete->next;
    free(toDelete);
}

void deleteByValue(struct Node **head, int value){
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp= *head;
    int index=0;
    while (temp!=NULL){
        if (temp->data==value){
            deleteAtIndex(head, index);
            temp=*head; // to restart checking the list for the nodes with that value
            index=0;
        }
        else{
            temp=temp->next;
            index++;
        }
    }
}

int main() {
    struct Node *head = NULL;

    // Initial node
    head = createNode(10);

    // Insertions
    insertAtBeginning(&head, 20);     // List: 20 -> 10
    insertAtEnd(&head, 30);           // List: 20 -> 10 -> 30
    insertAtIndex(&head, 25, 2);      // List: 20 -> 10 -> 25 -> 30
    insertAtIndex(&head, 5, 0);       // List: 5 -> 20 -> 10 -> 25 -> 30
    insertAtEnd(&head, 10);           // List: 5 -> 20 -> 10 -> 25 -> 30 -> 10

    printf("Linked List after insertions:\n");
    printLinkedList(head);
    printf("\n");

    displayCountNodes(head);  // Total count
    printf("\n");

    displayCountBasedOnValue(head, 10);  // Frequency of 10
    printf("\n");

    // Deletions
    deleteBeginning(&head);             // Removes 5
    deleteAtIndex(&head, 2);            // Removes 25
    deleteByValue(&head, 10);           // Removes remaining 10 (1 occurrence left)
    deleteEnd(&head);                   // Removes last 10

    printf("\nLinked List after deletions:\n");
    printLinkedList(head);
    printf("\n");

    displayCountNodes(head);
    printf("\n");

    return 0;
}

