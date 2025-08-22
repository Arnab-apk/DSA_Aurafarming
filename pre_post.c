#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

// Push a string onto stack
void push(char str[]) {
    if (top < MAX - 1) {
        top++;
        strcpy(stack[top], str);
    }
}

// Pop a string from stack
void pop(char str[]) {
    if (top >= 0) {
        strcpy(str, stack[top]);
        top--;
    }
}

// Function to convert prefix to postfix
void prefixToPostfix(char prefix[]) {
    int len = strlen(prefix);
    char op1[MAX], op2[MAX], expr[MAX], symbol[2];

    // Scan from right to left
    for (int i = len - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            symbol[0] = prefix[i];
            symbol[1] = '\0';
            push(symbol);  // Operand → push
        } else {
            // Operator → pop two operands
            pop(op1);  // actually operand2
            pop(op2);  // actually operand1

            // Postfix = operand1 operand2 operator
            sprintf(expr, "%s%s%c", op2, op1, prefix[i]);

            push(expr);
        }
    }

    printf("Postfix Expression: %s\n", stack[top]);
}

int main() {
    char prefix[MAX]();
}
