#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int eval_operator(int a, int b, char op){
    // a = top_most, b = second_topmost
    if (op=='+') return a+b;
    else if (op=='-') return b-a;
    else if (op=='*') return a*b;
    else if (op=='/') return b/a;
    else if (op=='%') return b%a;
    return pow(b, a); 
}
int eval_postfix(char* postfix){
    int top=-1;
    int stack[100];
    
    int n = strlen(postfix);
    for (int i=0; i<n; i++){
        if (postfix[i]==' ') continue;
        else if (isalnum(postfix[i])==true){
            top++;
            stack[top]=postfix[i]-'0';
        }
        else{
            int n1=stack[top];
            top--;
            int n2 = stack[top];
            stack[top] = eval_operator(n1, n2, postfix[i]);
        }
    }
    return stack[top--];
}


/*
int main(){
    char postfix[100];
    printf("Enter postfix expression: ");
    fgets(postfix, 100, stdin);
    
    // Remove newline if present
    postfix[strcspn(postfix, "\n")] = '\0';
    
    int result = eval_postfix(postfix);
    printf("Result: %d\n", result);
    
    return 0;
}
*/