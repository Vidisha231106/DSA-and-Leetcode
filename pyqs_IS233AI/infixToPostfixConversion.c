#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int precedence(char op){
    if (op=='+' || op=='-') return 1;
    else if (op=='*' || op=='/') return 2;
    else if (op=='^') return 3;
    return 0;
}
void infixToPostfix(char* infix){
    char stack[100];
    int top=-1;

    int n= strlen(infix);
    char* postfix = (char* ) malloc (sizeof(char)*n +1) ;
    int index=0;

    for (int i=0; i<n; i++){
        if (infix[i]==' ') continue;
        else if (infix[i]=='('){
            top++;
            stack[top]='(';
        }
        else if (infix[i]==')'){
            while (stack[top]!='('){
                postfix[index]=stack[top];
                index++;
                top--;
            }
            top--; // to remove '('
        }
        else if (isalnum(infix[i])==true){
            postfix[index]=infix[i];
            index++;
        }
        else{
            if (precedence(infix[i])>=precedence(stack[top])) stack[++top]=infix[i];
            else{
                // Pop operators with higher or equal precedence (except ^ which is right-associative)
                while (top != -1 && stack[top] != '(' && 
                    ((infix[i] != '^' && precedence(infix[i]) <= precedence(stack[top])) || (infix[i] == '^' && precedence(infix[i]) < precedence(stack[top])))){
                    
                        postfix[index++]= stack[top--];
                }
                stack[++top]=infix[i];
            }
        }
    }
    while (top!=-1){
        postfix[index++]=stack[top--];
    }
    postfix[index++]='\0';
    printf("Postfix Expression: %s", postfix);
}

/*
int main(){
    char infix[100];
    
    printf("Enter infix expression: ");
    fgets(infix, 100, stdin);
    
    // Remove newline if present
    infix[strcspn(infix, "\n")] = '\0';
    
    infixToPostfix(infix);
    
    return 0;
}
*/