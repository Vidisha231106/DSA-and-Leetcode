#include <stdio.h>
#include <ctype.h>
#include <string.h>

const int INT_MIN_VAL = -2147483648;
const int INT_MAX_VAL = 2147483647;

int helper(const char * s, int i, long num, int sign){
    int n = strlen(s);
    if (i>=n || !isdigit(s[i])){
        return (int)(sign * num);
    }
    
    num = num* 10 + (s[i] - '0');

    // Clamp if overflow
    if (sign * num <= INT_MIN_VAL) return INT_MIN_VAL;
    if (sign * num >= INT_MAX_VAL) return INT_MAX_VAL;

    return helper(s, i + 1, num, sign);
}

int myAtoi(const char* s){
    int i =0;
    while (i<strlen(s) && s[i] == ' ') i++;
    int sign = 1;
    if (i < strlen(s)  && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    return helper(s, i, 0, sign);
}

int main() {
    char s[] = "  -12345";
    printf("%d\n", myAtoi(s));
    return 0;
}