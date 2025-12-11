//Polynomial Multiplication:

#include <stdio.h>
#include <stdlib.h>

struct PolynomialNode{
    int exp;
    int coeff;
    PolynomialNode* next;
};

struct PolynomialNode* createNode(int exponent, int coefficient){
    struct PolynomialNode* newNode = (struct PolynomialNode*) malloc (sizeof(struct PolynomialNode));
    newNode->exp = exponent;
    newNode->coeff = coefficient;
    newNode->next = NULL;
    return newNode;
}

struct PolynomialNode* insertNode(struct PolynomialNode* head, int exponent, int coefficient){
    struct PolynomialNode* temp = head;
    if (temp==NULL){
        return createNode(exponent, coefficient);
    }
    if (head->exp<exponent){
        temp = head->next;
        head= createNode(exponent, coefficient);
        head->next= temp;
        return head;
    }
    while (temp!=NULL){
        if (temp->exp == exponent){
            temp->coefficient+=coefficient;
            break;
        } 
        temp=temp->next;
    }
    return head;
}

struct PolynomialNode* multiplyPolynomial(struct Polynomial* list1, struct Polynomial* list2){
    if (list1==NULL || list2==NULL) return NULL;
    struct PolynomialNode* answer=list1;
    struct PolynomialNode* answer_head= answer;
    struct PolynomialNode* temp2= list2;
    int highest_exponent = list1->exp + list2->exp;
    while (list1!=NULL){
        list2=temp2;
        while (temp2!=NULL){
            answer->next = createNode(list1->exp+list2->exp, list1->coeff*list2->coeff);
            answer = answer->next;
        }
        list1= list1->next;
    }
    return answer_head;
}

void displayPolynomialMultiplication(struct PolynomialNode* answer){
    if (answer==NULL){
        printf("Answer is 0");
        return;
    }
    struct PolynomialNode* temp = answer;
    while (temp->next!=NULL){
        printf("%d  x^%d-> ", temp->coeff, temp->exp);
    }
    printf("%d x^%d", temp->coeff, temp->exp);
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