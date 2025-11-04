#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    return -1;
}

void print_postfix(char *infix) {
    int n = strlen(infix);
    char *mystack = (char *) malloc(sizeof(char) * n);
    char *postfix = (char *) malloc(sizeof(char) * (n + 1));
    int top = -1, postfix_index = 0;

    for (int i = 0; i < n; i++) {
        char c = infix[i];

        // If operand
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            postfix[postfix_index++] = c;
        }
        else if (c == '(') {
            mystack[++top] = c;
        }
        else if (c == ')') {
            while (top != -1 && mystack[top] != '(') {
                postfix[postfix_index++] = mystack[top--];
            }
            top--; // remove '('
        }
        else { // operator
            while (top != -1 && mystack[top] != '(' &&
                    ((precedence(mystack[top]) > precedence(c)) ||
                    (precedence(mystack[top]) == precedence(c) && c != '^'))) {
                postfix[postfix_index++] = mystack[top--];
            }
            mystack[++top] = c;
        }
    }

    // pop remaining operators
    while (top != -1) {
        postfix[postfix_index++] = mystack[top--];
    }

    postfix[postfix_index] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    free(mystack);
    free(postfix);
}

int main() {
    char *s = "A+(B*C-(D/E)/F*G)*(H+I)";
    print_postfix(s);
    return 0;
}
