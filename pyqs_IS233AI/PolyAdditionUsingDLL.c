#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int coeff;
    int exp; 
    struct Node* prev;
    struct Node* next;
}Node;

Node* createNode(int c, int e){
    Node* new_node = (Node*) malloc (sizeof(Node));
    new_node->coeff = c;
    new_node->exp = e;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insertNode(struct Node** head, int c, int e){
    Node* new_node = createNode(c, e);
    if (*head==NULL){
        *head = new_node;
        return;
    } 
    Node* temp = *head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

Node* addPoly(struct Node* p1, struct Node* p2) {
    Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            insert(&result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            insert(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else {
            insert(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    /* Copy remaining terms */
    while (p1 != NULL) {
        insert(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insert(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}



/*
// Display polynomial 
void display(struct Node* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->exp);
        if (head->next != NULL)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;

    //Polynomial 1: 5x^3 + 3x^2 + 2 
    insert(&poly1, 5, 3);
    insert(&poly1, 3, 2);
    insert(&poly1, 2, 0);

    // Polynomial 2: 4x^3 + 2x^1 + 1 
    insert(&poly2, 4, 3);
    insert(&poly2, 2, 1);
    insert(&poly2, 1, 0);

    printf("Polynomial 1:\n");
    display(poly1);

    printf("Polynomial 2:\n");
    display(poly2);

    sum = addPoly(poly1, poly2);

    printf("Sum:\n");
    display(sum);

    return 0;
}
*/

