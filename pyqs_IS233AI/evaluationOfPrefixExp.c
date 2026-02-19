#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int eval_operator(int a, int b, char op){
    // a = top_most, b = second_topmost
    if (op=='+') return a+b;
    else if (op=='-') return a-b;
    else if (op=='*') return a*b;
    else if (op=='/') return a/b;
    else if (op=='%') return a%b;
    return pow(a,b); 
}
int eval_prefix(char* prefix){
    int top=-1;
    int stack[100];
    
    int n = strlen(prefix);
    for (int i=n-1; i>=0; i--){
        if (prefix[i]==' ') continue;
        else if (isalnum(prefix[i])==true){
            top++;
            stack[top]=prefix[i]-'0';
        }
        else{
            int n1=stack[top];
            top--;
            int n2 = stack[top];
            stack[top] = eval_operator(n1, n2, prefix[i]);
        }
    }
    return stack[top--];
}


/*
int main(){
    char prefix[100];
    printf("Enter prefix expression: ");
    fgets(prefix, 100, stdin);
    
    // Remove newline if present
    prefix[strcspn(prefix, "\n")] = '\0';
    
    int result = eval_prefix(prefix);
    printf("Result: %d\n", result);
    
    return 0;
}
*/