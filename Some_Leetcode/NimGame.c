//292 - Nim Game - IMPORTANT

#include <stdbool.h>
bool canWinNim(int n) {
    return n%4!=0;
}
/*
5
3,1,1       3,2
2,2,1       2,3
1,1,1,1,1   2,1,1,1 

4
2,1,1       1,1,1,1
            3,1         
            2,2

3
3
1,1,1       2,1    

2
2           1,1

1
1
only multiples of 4 result in the opponent winning*/
