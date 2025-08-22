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
        char currentChar = prefix[i];
        
        // Skip parentheses
        if (currentChar == '(' || currentChar == ')') {
            continue;
        }

        if (isalnum(currentChar)) {
            symbol[0] = currentChar;
            symbol[1] = '\0';
            push(symbol);  // Operand -> push
        } else {
            // Operator -> pop two operands
            pop(op1);
            pop(op2);

            // Postfix = operand1 operand2 operator
            // Using snprintf to prevent buffer overflow
            snprintf(expr, sizeof(expr), "%s%s%c", op2, op1, currentChar);

            push(expr);
        }
    }

    printf("Postfix Expression: %s\n", stack[top]);
}

int main() {
    char prefix[MAX];
    printf("Enter a prefix expression (e.g., -+AB\*CD): ");
    scanf("%s", prefix);
    prefixToPostfix(prefix);
    return 0;
}