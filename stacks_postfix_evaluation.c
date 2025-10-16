#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int evaluation(int op2, char op, int op1){
    if (op == '-'){
        return op2-op1;
    }
    else if (op == '+'){
        return op2+op1;
    }
    else if (op== '*'){
        return op2*op1;
    }
    else if (op =='/'){
        return op2/op1;
    }
    else if (op =='^'){
        return (int)pow(op2, op1);
    }
    return 0;
}

int postfix_to_infix(char * postfix){
    int * operands = (int *) malloc (sizeof(int)*strlen(postfix));  // Changed to int*
    int operands_top=-1;

    int op1, op2;
    int len = strlen(postfix);
    for (int i=0; i<len; i++){
        if (postfix[i]==' ') continue;  // Check space first
        else if (postfix[i]!='+' && postfix[i]!='-' && postfix[i]!='*' && postfix[i]!='/' && postfix[i]!='^'){
            operands_top++;
            operands[operands_top]=postfix[i] - '0';  // Convert char to int
        }
        else{
            op1 = operands[operands_top];  // Already an int now
            operands_top--;
            op2 = operands[operands_top];  // Already an int now
            operands[operands_top] = evaluation(op2, postfix[i], op1);
        }
    }
    int answer = operands[operands_top];
    free(operands);  // Free memory
    return answer;
}

int main(){
    char * s = "5 3 4 * + 9 -";
    int answer = postfix_to_infix(s);
    printf("The answer = %d\n", answer);  // Fixed format specifier
    return 0;
}