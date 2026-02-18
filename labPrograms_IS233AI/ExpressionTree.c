//8

//Expression Tree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct TreeNode{
    char val;
    struct TreeNode* left; 
    struct TreeNode* right;
}TreeNode;

TreeNode* numStack[100];
int numTop =-1;

char opStack[100];
int opTop=-1;

void pushOp(char node){
    opStack[++opTop]=node;
}

void pushNum(TreeNode* node){
    numStack[++numTop]=node;
}

char popOp(){
    if (opTop < 0) return '\0';
    return opStack[opTop--];
}

TreeNode* popNum(){
    if (numTop < 0) return NULL;
    return numStack[numTop--];
}

TreeNode* createNode(char val){
    TreeNode* root=(TreeNode* ) malloc (sizeof(TreeNode));
    root->val = val;
    root->left= NULL;
    root->right=NULL;
    return root;
}

int precedence(char op){
    if (op=='+' || op=='-') return 1;
    if (op=='*' || op=='/') return 2;
    if (op=='^') return 3;
    return 0;
}

void buildSubTree(char op){
    if (op == '\0') return;
    TreeNode* right = popNum();
    TreeNode* left = popNum();
    TreeNode* opNode = createNode(op);
    opNode->left = left;
    opNode->right = right;
    pushNum(opNode);
}

TreeNode* constructTree(char infix[]){
    int i=0;
    while (infix[i]!='\0'){
        if (isalnum(infix[i])){
            pushNum(createNode(infix[i]));
        }
        else if (infix[i]=='('){
            pushOp(infix[i]);
        }
        else if (infix[i]==')'){
            while (opStack[opTop]!='('){
                buildSubTree(popOp());
            }
            popOp();
        }
        else{
            while (opTop!=-1 && precedence(opStack[opTop])>=precedence(infix[i])){
                buildSubTree(popOp());
            }
            pushOp(infix[i]);
        }
        i++;
    }
    while (opTop >= 0){
        buildSubTree(popOp());
    }
    return popNum();
}

void displayPreorder(TreeNode* root){
    if (root==NULL) return;
    printf("%c ", root->val);
    displayPreorder(root->left);
    displayPreorder(root->right);
}

int main(){
    char expression[100];
    printf("Enter the infix expression: ");
    if (!fgets(expression, sizeof(expression), stdin)) return 0;
    expression[strcspn(expression, "\n")] = '\0';
    TreeNode* root = constructTree(expression);
    printf("Preorder of expression tree: ");
    displayPreorder(root);
    printf("\n");
    return 0;
}
