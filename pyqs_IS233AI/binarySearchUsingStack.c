#include <stdio.h>
#include <stdlib.h>

typedef struct Range{
    int low, high;
}Range;

typedef struct Stack{
    Range items[100];
    int top;
}Stack;

void push(Stack *s, Range r){
    s->top++;
    s->items[s->top]=r;
}

Range pop(Stack* s){
    return s->items[(s->top)--];
}

int binarySearch(int* arr, int n, int target){
    Stack s;
    s.top=-1;
    Range initial={0,n-1};
    push(&s, initial);

    while (s.top!=-1){
        Range current = pop(&s);
        int low= current.low;
        int high=current.high;
        if (low>high) continue;
        int mid = (low+high)/2;
        if (arr[mid]==target) return mid;
        else if (target<arr[mid]){
            Range left = {low, mid-1};
            push(&s, left);
        }
        else{
            Range right = {mid+1, high};
            push(&s, right);
        }
    }
    return -1;
}

/*int main() {
    int arr[] = {10,20,30,40,50};
    int n = sizeof(arr)/sizeof(int);
    int key = 40;

    if(binarySearch(arr,n,key))
        printf("Element Found");
    else
        printf("Not Found");
    return 0;
}*/