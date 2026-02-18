// Tower of Hanoi

#include <stdio.h>
#include <stdlib.h>

void recursion(int n, char from, char to, char aux){
    if (n==1){
        printf("\nMove disk 1 from %c, to %c", from, to);
        return;
    }
    recursion(n-1, from, aux, to);
    printf("\nMove disk %d from %c, to %c", n, from, to);
    recursion(n-1, aux, to, from);
}

int main(){
    recursion(4,'A', 'B', 'C');
    return 0;
}
