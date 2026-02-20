//Polynomial Multiplication:

#include <stdio.h>
#include <stdlib.h>

struct PolynomialNode{
    int exp;
    int coeff;
    struct PolynomialNode* next;
};

struct PolynomialNode* createNode(int exponent, int coefficient){
    struct PolynomialNode* newNode = (struct PolynomialNode*) malloc(sizeof(struct PolynomialNode));
    newNode->exp = exponent;
    newNode->coeff = coefficient;
    newNode->next = NULL;
    return newNode;
}

struct PolynomialNode* insertNode(struct PolynomialNode* head, int exponent, int coefficient){
    if (coefficient == 0) return head; // Don't insert zero coefficients
    
    struct PolynomialNode* newNode = createNode(exponent, coefficient);
    
    // Empty list
    if (head == NULL) {
        return newNode;
    }
    
    // Insert at beginning (higher exponent)
    if (head->exp < exponent) {
        newNode->next = head;
        return newNode;
    }
    
    // Same exponent as head
    if (head->exp == exponent) {
        head->coeff += coefficient;
        free(newNode);
        return head;
    }
    
    // Find position to insert
    struct PolynomialNode* temp = head;
    while (temp->next != NULL && temp->next->exp > exponent) {
        temp = temp->next;
    }
    
    // Same exponent found
    if (temp->next != NULL && temp->next->exp == exponent) {
        temp->next->coeff += coefficient;
        free(newNode);
    } else {
        // Insert in middle or end
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    return head;
}

struct PolynomialNode* multiplyPolynomial(struct PolynomialNode* list1, struct PolynomialNode* list2){
    if (list1 == NULL || list2 == NULL) return NULL;
    
    struct PolynomialNode* result = NULL;
    struct PolynomialNode* temp1 = list1;
    
    // Multiply each term of list1 with each term of list2
    while (temp1 != NULL) {
        struct PolynomialNode* temp2 = list2;
        while (temp2 != NULL) {
            int newExp = temp1->exp + temp2->exp;
            int newCoeff = temp1->coeff * temp2->coeff;
            result = insertNode(result, newExp, newCoeff);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    
    return result;
}

void displayPolynomialMultiplication(struct PolynomialNode* poly){
    if (poly == NULL){
        printf("0\n");
        return;
    }
    
    struct PolynomialNode* temp = poly;
    int first = 1;
    while (temp != NULL){
        if (!first && temp->coeff > 0) printf(" + ");
        else if (temp->coeff < 0) printf(" - ");
        
        if (temp->exp == 0) {
            printf("%d", first ? temp->coeff : abs(temp->coeff));
        } else if (temp->exp == 1) {
            printf("%dx", first ? temp->coeff : abs(temp->coeff));
        } else {
            printf("%dx^%d", first ? temp->coeff : abs(temp->coeff), temp->exp);
        }
        
        first = 0;
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    // Create first polynomial: 3x^2 + 5x + 2
    struct PolynomialNode* poly1 = NULL;
    poly1 = insertNode(poly1, 2, 3);
    poly1 = insertNode(poly1, 1, 5);
    poly1 = insertNode(poly1, 0, 2);
    
    // Create second polynomial: 4x^2 + 2x + 1
    struct PolynomialNode* poly2 = NULL;
    poly2 = insertNode(poly2, 2, 4);
    poly2 = insertNode(poly2, 1, 2);
    poly2 = insertNode(poly2, 0, 1);
    
    printf("First Polynomial: ");
    displayPolynomialMultiplication(poly1);
    
    printf("Second Polynomial: ");
    displayPolynomialMultiplication(poly2);
    
    struct PolynomialNode* result = multiplyPolynomial(poly1, poly2);
    
    printf("Result of Multiplication: ");
    displayPolynomialMultiplication(result);
    
    return 0;
}