#include <stdio.h>
#include <stdlib.h>

// add element at the end
// add element after key

//THIS IS A CIRCULAR SINGLY LL, NOT A DOUBLY LL

typedef struct Node{
    int val; 
    struct Node *next;
}Node;

void add_at_end(Node** tail, int val){
    Node* new_node=(Node*) malloc(sizeof(Node));
    new_node->val=val;
    if (*tail==NULL){
        *tail = new_node;
        (*tail)->next=new_node; // tail points to itself
        return;
    }
    new_node->next=(*tail)->next;
    (*tail)->next=new_node;
    *tail=new_node;
}

void add_after_key(Node** tail, int key, int val){
    if (*tail==NULL){
        return;
    }
    if (key==(*tail)->val){
        add_at_end(*tail, val);
        return;
    }
    Node* new_node=(Node*) malloc(sizeof(Node));
    new_node->val=val;

    Node* temp =(*tail)->next;

    // do nothing if key not found
    while (temp!=*tail){
        if (temp->val==key){
            new_node->next=temp->next;
            temp->next=new_node;
            return;
        }
        temp=temp->next;
    }
}