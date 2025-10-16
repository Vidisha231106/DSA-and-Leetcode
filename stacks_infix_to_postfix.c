#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for malloc

int precedence (char c){
    if (c=='^'){
        return 2;
    }
    else if (c=='*' || c=='/'){
        return 1;
    }
    else if (c=='+' || c=='-'){
        return 0;
    }
    return -1;
} 

void print_postfix(char * infix){
    int n = strlen(infix);
    char *mystack = (char *) malloc (sizeof(char)*n);
    int top = -1;
    char *postfix = (char*) malloc (sizeof(char)*(n+1));
    int postfix_index = 0;

    for (int i = 0; i < n; i++){
        char c = infix[i];

        if (precedence(c) == -1){ // operand
            postfix[postfix_index] = c;
            postfix_index++;
        }
        else if (c == '('){ 
            top++;
            mystack[top] = c;
        }
        else if (c == ')'){
            while (top != -1 && mystack[top] != '('){
                postfix[postfix_index++] = mystack[top];
                top--;
            }
            top--; // pop '('
        }
        else { // operator
            while (top != -1 && mystack[top] != '(' && precedence(mystack[top]) > precedence(c)){
                if (c =='^'){
                    postfix[postfix_index++] = mystack[top--];
                }
                else{
                    break;
                }
                postfix[postfix_index] = mystack[top];
                postfix_index++;
                top--;
            }
            top++;
            mystack[top] = c;
        }
    }

    // pop remaining operators
    while (top != -1){
        postfix[postfix_index++] = mystack[top--];
    }

    postfix[postfix_index] = '\0'; // null terminate

    printf("Postfix Expression: ");
    for (int i = 0; i < postfix_index; i++){
        printf("%c", postfix[i]);
    }
    printf("\n");
}

int main(){
    char * s = "(a*b)+c";
    print_postfix(s);
    return 0;
}