#include <stdio.h>
#include <stdlib.h>

// 1(head of ll)-> 2-> 3-> 4(top of stack)

struct stack_element {
    int data;
    struct stack_element* next;
};

struct stack_element* createLLNode(int value) {
    struct stack_element * new_node = (struct stack_element *) malloc(sizeof(struct stack_element));
    new_node->next = NULL;
    new_node->data = value;
    return new_node;
}

void push_element(struct stack_element **head, int value, int *count) {
    struct stack_element *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    struct stack_element *new_element = createLLNode(value); 
    temp->next = new_element;
    (*count)++;
}

int pop_element(struct stack_element **head, int *count) {
    if (*head == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }

    struct stack_element *temp = *head;
    struct stack_element *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    int value = temp->data;

    if (prev != NULL) {
        prev->next = NULL;
    } else {
        *head = NULL; // stack became empty
    }

    free(temp);
    (*count)--;
    return value;
}

void display_top(struct stack_element *head) {
    if (head == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    while (head->next != NULL) {
        head = head->next;
    }
    printf("Top: %d\n", head->data);
}

void display_stack(struct stack_element *head) {
    if (head == NULL) {
        return;
    }
    display_stack(head->next);
    printf("%d ", head->data);
}

int main() {
    int size;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    int count = 1;  // current number of elements
    printf("Enter the elements of the stack, starting with the bottom of the stack:\n");

    int value;
    scanf("%d", &value);
    struct stack_element *head = createLLNode(value);

    for (int i = 1; i < size; i++) {
        scanf("%d", &value);
        push_element(&head, value, &count);
    }

    display_stack(head);
    printf("\n");
    display_top(head);

    printf("Popped element: %d\n", pop_element(&head, &count));
    display_stack(head);
    printf("\n");
    display_top(head);

    return 0;
}
