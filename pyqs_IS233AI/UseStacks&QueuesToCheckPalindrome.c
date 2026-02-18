//Use stacks and queues to check if a string is a palindrome

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void palindrome(){
    int num=0;
    printf("Enter the size of string: ");
    scanf("%d", &num);
    char* string =  (char *) malloc (sizeof(char)*num +1);
    char * stack = (char *) malloc (sizeof(char)*num +1);
    char * queue = (char *) malloc (sizeof(char)*num +1);
    
    printf("Enter the string: ");
    scanf("%s", string);
    int top =-1;
    int front=0;
    int rear=-1;

    for (int i=0; i<num; i++){
        top++;
        rear++;
        stack[top]=string[i];
        queue[rear] = string[i];
    }
    
    while (top>-1 && stack[top]==queue[front]){
        top--;
        front++; // here, we dont care about maintaining this value
    }
    if (top==-1){
        printf("Palindrome");
    }
    else{
        printf("Not a Palindrome");
    }
}
