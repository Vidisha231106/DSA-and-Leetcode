/*
Next Greater Element Using Stack

Given a circular integer array A, return the next greater element for every element in A. 
The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner. 
If it doesn't exist, return -1 for this element.

Example: 
Input: N = 11, A[] = {3,10,4,2,1,2,6,1,7,2,9}
Output: 10,-1,6,6,2,6,7,7,9,9,10
*/

#include <stdio.h>
#include <stdlib.h>

struct stackElement{
    int val;
    struct stackElement *next;
};

void pushStackElement(struct stackElement ** head, int element){
    struct stackElement * new_stack_element = (struct stackElement* ) malloc (sizeof(struct stackElement));
    new_stack_element ->next = NULL;
    new_stack_element ->val = element;
    if (*head == NULL) { // empty stack
        *head = new_stack_element;
        return;
    }
    struct stackElement * temp = *head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new_stack_element;
}

void popStackElement(struct stackElement **head){
    if (*head == NULL) return; // empty stack

    // If only one element
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct stackElement *temp = *head;
    while (temp->next->next!=NULL){
        temp= temp->next;
    }
    free(temp->next);
    temp->next= NULL;
}

int topStackElement(struct stackElement *head){
    struct stackElement *temp = head;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    return temp->val;
}

int isStackEmpty(struct stackElement *head){
    if (head==NULL){
        return 1; // yes, stack is empty
    }
    return 0; // no, stack is not empty
}

void nextGreaterElement (int *arr, int arrSize, int *answer_arr){
    struct stackElement* mystack = NULL;
    int greatest_opp_direction =0;
    pushStackElement(&mystack, -1);
    for (int i = arrSize-2; i>=0; i++){
        int top = -1;
        if (!isStackEmpty(mystack)) {
            top = topStackElement(mystack);
        }
        while (top<=arr[i]){
            popStackElement(&mystack);
            top = topStackElement(mystack);
        }
        answer_arr[i]=top;
        if (top>greatest_opp_direction){
            greatest_opp_direction = top;
        }
    }
    answer_arr[arrSize-1] = greatest_opp_direction;
}

int main() {
    int arr[] = {3,10,4,2,1,2,6,1,7,2,9};
    int N = sizeof(arr) / sizeof(arr[0]);
    int answer_arr[13];

    nextGreaterElement(arr, N, answer_arr);

    printf("Next Greater Elements:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", answer_arr[i]);
    }
    printf("\n");

    return 0;
}
