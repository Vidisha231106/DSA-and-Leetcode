#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int precedence(char op){
    if (op=='+' || op=='-') return 1;
    else if (op=='*' || op=='/') return 2;
    else if (op=='^') return 3;
    return 0;
}

// 1. reverse infix 
// 2. swap ( to ) and ) to ( 
// 3. evaluate as postfix
// 4. reverse again

void infixToPrefix(char* infix){
    char stack[100];
    int top=-1;

    int n= strlen(infix);
    char* prefix = (char* ) malloc (sizeof(char)*n +1) ;
    int index=0;
    // reverse infix
    for (int i=0; i<n/2; i++){
        char temp = infix[n-i-1];
        infix[n-i-1]=infix[i];
        infix[i]=temp;
    }

    for (int i=0; i< n; i++){
        if (infix[i]=='(') infix[i]=')';
        else if (infix[i]==')') infix[i]='(';
    }

    for (int i=0; i<n; i++){
        if (infix[i]==' ') continue;
        else if (infix[i]=='('){
            top++;
            stack[top]='(';
        }
        else if (infix[i]==')'){
            while (stack[top]!='('){
                prefix[index]=stack[top];
                index++;
                top--;
            }
            top--; // to remove '('
        }
        else if (isalnum(infix[i])==true){
            prefix[index]=infix[i];
            index++;
        }
        else{
            // Pop operators with higher or equal precedence (except ^ which is right-associative)
            while (top != -1 && stack[top] != '(' && 
                ((infix[i] == '^' && precedence(infix[i]) <= precedence(stack[top])) || (infix[i] != '^' && precedence(infix[i]) < precedence(stack[top])))){
                
                    prefix[index++]= stack[top--];
            }
            stack[++top]=infix[i];
        }
    }
    while (top!=-1){
        prefix[index++]=stack[top--];
    }

    prefix[index]='\0';
    for (int i=0; i<index/2; i++){
        char temp = prefix[n-i-1];
        prefix[n-i-1]=prefix[i];
        prefix[i]=temp;
    }
    printf("Prefix Expression: %s", prefix);
}

/*
int main(){
    char infix[100];
    
    printf("Enter infix expression: ");
    fgets(infix, 100, stdin);
    
    // Remove newline if present
    infix[strcspn(infix, "\n")] = '\0';
    
    infixToPrefix(infix);
    
    return 0;
}
*/